package com.example.myapplication;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.Random;

public class Fireball {
    // so that I can add more fireball types easily
    Bitmap[] fireball = new Bitmap[3];
    int fireballFrame = 0;
    int fireballX, fireballY, fireballVelocity;
    int increase = 0;
    int BASE_SPEED = 30;
    Random random;
    public Fireball(Context context){
        fireball[0] = BitmapFactory.decodeResource(context.getResources(), R.drawable.fireball);
        fireball[1] = BitmapFactory.decodeResource(context.getResources(), R.drawable.fireball2);
        fireball[2] = BitmapFactory.decodeResource(context.getResources(), R.drawable.fireball3);

        random = new Random();

        resetPosition();
    }

    public void resetPosition(){
        fireballX = random.nextInt(GameView.dWidth - getFireballWidth());
        fireballY = -200 + random.nextInt(600) * -1;
        fireballVelocity = BASE_SPEED + random.nextInt(20) + increase;
    }

    public void increaseVelocity(){
        increase += 2;
    }

    public Bitmap getFireball(int fireballFrame){
        return fireball[fireballFrame];
    }

    public int getFireballWidth(){
        return fireball[0].getWidth();
    }

    public int getFireballHeight(){
        return fireball[0].getHeight();
    }
}
