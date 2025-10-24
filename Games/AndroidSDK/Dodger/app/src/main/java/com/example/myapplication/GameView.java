package com.example.myapplication;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Handler;
import android.view.Display;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.core.content.res.ResourcesCompat;

import java.util.ArrayList;
import java.util.Random;

public class GameView extends View implements SensorEventListener {
    Bitmap background, ground, player;
    Rect rectBackground, rectGround;
    Context context;
    Handler handler;
    final long UPDATE_MILLIS = 30;
    Runnable runnable;
    Paint textPaint = new Paint();
    Paint healthPaint = new Paint();
    float TEXT_SIZE = 220;
    int points = 0;
    int life = 3;
    static int dWidth, dHeight;
    Random random;
    float playerX, playerY;
    float oldX, oldPlayerX;
    ArrayList<Fireball> fireballs;
    ArrayList<Explosion> explosions;

    float last_x,last_y, last_z;
    long lastUpdateTime, diffTime;
    SensorManager sensorManager;

    public static final int THRESHOLD = 1000;

    Sensor lightSensor;
    boolean isDark = false;
    boolean isLight = false;


    @SuppressLint("MissingPermission")
    public GameView(Context context) {
        super(context);
        this.context = context;

        background = BitmapFactory.decodeResource(getResources(), R.drawable.background);
        ground = BitmapFactory.decodeResource(getResources(), R.drawable.ground);
        player = BitmapFactory.decodeResource(getResources(), R.drawable.player);

        Display display = ((Activity) getContext()).getWindowManager().getDefaultDisplay();

        Point size = new Point();

        display.getSize(size);
        dWidth = size.x;
        dHeight = size.y;

        rectBackground = new Rect(0, 0, dWidth, dHeight);
        rectGround = new Rect(0, dHeight-ground.getHeight(), dWidth, dHeight);

        handler = new Handler();
        runnable = new Runnable() {
            @Override
            public void run() {
                invalidate();
            }
        };

        textPaint.setColor(Color.rgb(255, 165, 0));
        textPaint.setTextSize(TEXT_SIZE);
        textPaint.setTextAlign(Paint.Align.LEFT);
        textPaint.setTypeface(ResourcesCompat.getFont(context, R.font.dm_serif_display));

        healthPaint.setColor(Color.GREEN);

        random = new Random();

        playerX = dWidth/2 - player.getWidth()/2;
        playerY = dHeight - ground.getHeight() - player.getHeight();

        fireballs = new ArrayList<>();
        explosions = new ArrayList<>();

        for(int i=0; i<4; i++){
            Fireball fireball = new Fireball(context);
            fireballs.add(fireball);
        }

        // ACCELEROMETER
        sensorManager = (SensorManager) context.getSystemService(Context.SENSOR_SERVICE);
        Sensor accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);

        // LIGHT
        sensorManager = (SensorManager) context.getSystemService(Context.SENSOR_SERVICE);
        lightSensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        sensorManager.registerListener(this, lightSensor, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    protected void onDraw(@NonNull Canvas canvas) {
        super.onDraw(canvas);
        canvas.drawBitmap(background,null,rectBackground,null);
        canvas.drawBitmap(ground,null,rectGround,null);
        canvas.drawBitmap(player,playerX,playerY,null);

        for(int i=0; i < fireballs.size(); i++){
            canvas.drawBitmap(fireballs.get(i).getFireball(fireballs.get(i).fireballFrame),
                    fireballs.get(i).fireballX, fireballs.get(i).fireballY, null);

            // switched between fireball frames
            fireballs.get(i).fireballFrame++;
            if(fireballs.get(i).fireballFrame > 2){
                fireballs.get(i).fireballFrame = 0;
            }

            // fireballs falling speed based on light/mode
            int baseSpeed = fireballs.get(i).fireballVelocity;
            if (isDark) {
                fireballs.get(i).fireballY += baseSpeed * 2;
            } else if (isLight){
                fireballs.get(i).fireballY += baseSpeed / 2;
            } else {
                fireballs.get(i).fireballY += fireballs.get(i).fireballVelocity;
            }

            // hit the ground?
            if(fireballs.get(i).fireballY + fireballs.get(i).getFireballHeight()
                    >= dHeight - ground.getHeight()){

                // add points for dodging the fireball depending on light/mode
                if (isDark) {
                    // hard mode
                    points += 40;
                } else if (isLight){
                    // easy mode
                    points += 2;
                } else{
                    // normal mode
                    points += 10;
                }

                // makes explosion where fireball was
                @SuppressLint("DrawAllocation") Explosion explosion = new Explosion(context);
                explosion.explosionX = fireballs.get(i).fireballX;
                explosion.explosionY = fireballs.get(i).fireballY;
                explosions.add(explosion);

                // resets the fireball to drop again
                fireballs.get(i).resetPosition();


                // May need balancing:

                // every 100 points, all fireball fall speed is increased
                if(points % 100 == 0 && points != 0){
                    for(int j=0; j < fireballs.size(); j++) {
                        fireballs.get(j).increaseVelocity();
                    }
                }

                // every 250 points, a super fast fireball falls
                if(points % 250 == 0 && points != 0){
                    fireballs.get(i).fireballVelocity += 50;
                }
            }
        }

        for(int i = 0; i < fireballs.size(); i++){
            // is player hit?
            if(fireballs.get(i).fireballX + fireballs.get(i).getFireballWidth() >= playerX
            && fireballs.get(i).fireballX <= playerX + player.getWidth()
            && fireballs.get(i).fireballY + fireballs.get(i).getFireballWidth() >= playerY
            && fireballs.get(i).fireballY + fireballs.get(i).getFireballWidth()
                    <= playerY + player.getHeight()){

                // lose 1 life per hit
                life--;

                // fireballs ready to drop again
                fireballs.get(i).resetPosition();

                // Game Over
                if(life == 0){
                    @SuppressLint("DrawAllocation") Intent intent = new Intent(context, GameOver.class);
                    intent.putExtra("points", points);
                    context.startActivity(intent);
                    ((Activity) context).finish();
                }
            }
        }

        for(int i = 0; i < explosions.size(); i++){
            canvas.drawBitmap(explosions.get(i).getExplosion(explosions.get(i).explosionFrame),
                    explosions.get(i).explosionX, explosions.get(i).explosionY, null);

            explosions.get(i).explosionFrame++;
            // Make it so Explosions don't linger
            if(explosions.get(i).explosionFrame > 3){
                explosions.remove(i);
            }
        }

        // Show Damaged Life
        if(life == 2){
            healthPaint.setColor(Color.YELLOW);
        }
        // Show Critical Life
        else if(life == 1){
            healthPaint.setColor(Color.RED);
        }

        // draws health bar
        canvas.drawRect(dWidth - 200, 30, dWidth-200+60*life, 80, healthPaint);

        // draws points
        canvas.drawText("" + points, 20, TEXT_SIZE, textPaint);

        handler.postDelayed(runnable, UPDATE_MILLIS);
    }

    @SuppressLint("ClickableViewAccessibility")
    @Override
    // Player movement
    public boolean onTouchEvent(MotionEvent event) {
        float touchX = event.getX();
        float touchY = event.getY();

        if(touchY >= playerY){
            int action = event.getAction();
            if(action == MotionEvent.ACTION_DOWN){
                oldX = event.getX();
                oldPlayerX = playerX;
            }
            // stops player from going off the screen
            if(action == MotionEvent.ACTION_MOVE){
                float shift = oldX - touchX;
                float newPlayerX = oldPlayerX - shift;

                if(newPlayerX <= 0){
                    playerX = 0;
                }
                else if(newPlayerX >= dWidth - player.getWidth()){
                    playerX = dWidth - player.getWidth();
                }
                else{
                    playerX = newPlayerX;
                }
            }
        }
        return true;
    }


    @Override
    public void onSensorChanged(SensorEvent event) {
        // Accelerometer
        if(event.sensor.getType()==Sensor.TYPE_ACCELEROMETER){
            // Accelerometer values
            float x = event.values[0];
            float y = event.values[1];
            float z = event.values[2];

            // Player movement using tilt
            // Sensitivity adjustment (tweak as needed)
            float tiltSensitivity = 5.0f;

            // Move player based on tilt
            playerX -= x * tiltSensitivity;

            // Clamp player within screen bounds
            if (playerX < 0) {
                playerX = 0;
            } else if (playerX > dWidth - player.getWidth()) {
                playerX = dWidth - player.getWidth();
            }

            // shaking a certain amount gives a life
            long currentTime = System.currentTimeMillis();

            diffTime = currentTime - lastUpdateTime;

            if(diffTime > 100){
                float speed = Math.abs(x + y + z - last_x - last_y - last_z) / diffTime * 10000;
                if(speed > THRESHOLD){
                    life = 2;
                }
                lastUpdateTime = currentTime;
                last_x = x;
                last_y = y;
                last_z = z;
            }
        // Light sensor
        } else if (event.sensor.getType() == Sensor.TYPE_LIGHT) {
            float lux = event.values[0];
            // threshold for darkness(tweak as needed)
            isDark = lux < 30;
            isLight = lux > 100;
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}