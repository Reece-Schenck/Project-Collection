#include "Bat.hpp"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include <ctime>
#include "Pitcher.hpp"
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
    // Create a video mode object
    VideoMode vm(1920, 1080);
    // Create and open a window for the game
    RenderWindow window(vm, "Pong-like", Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU 
    Texture textureBackground;
    // Load a graphic into the texture 
    textureBackground.loadFromFile("graphics/background.png");
    // Create a sprite 
    Sprite spriteBackground;
    // Attach the texture to the sprite 
    spriteBackground.setTexture(textureBackground);
    // Set the spriteBackground to cover the screen 
    spriteBackground.setPosition(0, 0);

    // Place pitcher near top-center (mound), bat near bottom-center (plate)
    Pitcher pitcher(vm.width / 2.0f, 220.0f);
    Bat batter(vm.width / 2.0f, vm.height - 120.0f); // plate area y
    Ball ball(vm.width / 2.0f, 260.0f); // initial ball resting on mound
    // Create a bat at the bottom center of the screen
    Bat bat(1920 / 2, 1080 - 20);
    Text hud;
    Font font;
    font.loadFromFile("fonts/Rubik-Black.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::Black);
    hud.setPosition(20, 20);

    // for Game Over text
    Text messageText;
    messageText.setFont(font);
    messageText.setCharacterSize(80);
    messageText.setFillColor(Color::Yellow);

    Clock clock;

    // Game states
    enum GameState { WAITING_FOR_PITCH, BALL_IN_PLAY, HIT_RESOLUTION, POINT_SCORED };
    GameState state = WAITING_FOR_PITCH;

    // Player selections & counters
    Ball::PitchType selectedPitch = Ball::FASTBALL;
    int pitcherScore = 0;
    int batterScore = 0;
    const int WIN_SCORE = 10;

    int strikes = 0;      // strikes against batter for current at-bat
    bool acceptInput = false;
    bool isPaused = true;

    // Plate region for batter
    float plateY = vm.height - 120.0f;

    // Mound start pos for resets
    float moundX = vm.width / 2.0f;
    float moundY = 220.0f;

    bool gameOver = false;

    /*
    ****************************************
    Music and Sound Effects
    ****************************************
    */
    Music backgroundMusic;
    if (!backgroundMusic.openFromFile("sound/backgroundMusic.wav")) {
        // handle error
    }
    backgroundMusic.setLoop(true);   // keep looping
    backgroundMusic.play();          // start playing immediately

    // Buffers hold the actual sound data
    SoundBuffer hitBuffer;
    SoundBuffer throwBuffer;
    SoundBuffer catchBuffer;
    SoundBuffer strikeBuffer;
    SoundBuffer scoreBuffer;

    // Load sound files into buffers
    hitBuffer.loadFromFile("sound/ballHit.wav");
    throwBuffer.loadFromFile("sound/throw.wav");
    catchBuffer.loadFromFile("sound/catch.wav");
    strikeBuffer.loadFromFile("sound/strike.wav");
    scoreBuffer.loadFromFile("sound/score.wav");

    Sound ballHit;
    ballHit.setBuffer(hitBuffer);

    Sound throwSound;
    throwSound.setBuffer(throwBuffer);

    Sound catchSound;
    catchSound.setBuffer(catchBuffer);

    Sound strikeSound;
    strikeSound.setBuffer(strikeBuffer);

    Sound scoreSound;
    scoreSound.setBuffer(scoreBuffer);


    // Game Loop
    while (window.isOpen())
    {
        /*
        ****************************************
        Handle the players input
        ****************************************
        */
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased && !isPaused)
            {
                // Listen for key presses again
                acceptInput = true;
            }

            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }
        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // Start the game
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            if (isPaused) {
                isPaused = false;
                gameOver = false;

                state = WAITING_FOR_PITCH;
                pitcherScore = 0;
                batterScore = 0;
                strikes = 0;

                // Reset positions
                pitcher.setPosition(moundX, moundY);
                // reset to center
                batter.setPosition(vm.width / 2.0f, plateY);
                batter.resetSwing();
                ball.reset(moundX, moundY + 40.0f);

                acceptInput = true;
            }
        }


        // Pitcher movement (arrows)
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            pitcher.moveLeft();
        }
        else {
            pitcher.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            pitcher.moveRight();
        }
        else {
            pitcher.stopRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            pitcher.moveUp();
        }
        else {
            pitcher.stopUp();
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pitcher.moveDown();
        }
        else {
            pitcher.stopDown();
        }

        // Batter movement (A/D)
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            batter.moveLeft();
        }
        else {
            batter.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            batter.moveRight();
        }
        else {
            batter.stopRight();
        }

        // Pitch selection
        if (state == WAITING_FOR_PITCH && acceptInput) {
            if (Keyboard::isKeyPressed(Keyboard::J)) {
                selectedPitch = Ball::FASTBALL;
            }
            if (Keyboard::isKeyPressed(Keyboard::K)) {
                selectedPitch = Ball::CURVEBALL;
            }
            if (Keyboard::isKeyPressed(Keyboard::L)) {
                selectedPitch = Ball::CHANGEUP;
            }

            // Throw pitch with Space
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                // Throw from pitcher downward
                ball.throwPitch(selectedPitch, pitcher.getCenterX(), 
                    pitcher.getShape().getPosition().y + 30.0f);
                state = BALL_IN_PLAY;
                acceptInput = false;
                throwSound.play();
            }
        }


        // Stops batter from just holding down W
        static bool wPrev = false;
        bool wNow = Keyboard::isKeyPressed(Keyboard::W);
        if (wNow && !wPrev) {
            // Attempt to start swing
            batter.startSwing();
        }
        wPrev = wNow;

        /*
        ****************************************
        Update the scene
        ****************************************
        */
        if (!isPaused && !gameOver) {
            // Update the delta time
            Time dt = clock.restart();

            // Once ball is thrown pitcher gets free movement
            bool pitcherFree = (state != WAITING_FOR_PITCH);
            pitcher.update(dt, pitcherFree);

            batter.update(dt);
            ball.update(dt);

            if (state == BALL_IN_PLAY) {
                if (!ball.wasHitByBat() && ball.isInFlight()) {
                    // If batter swings and bat intersects ball
                    if (batter.isSwinging() && 
                        ball.getPosition().intersects(batter.getPosition())) {
                        // Bat hit the ball
                        float swingPow = batter.getSwingPower();
                        float batCenterX = batter.getShape().getPosition().x;
                        ball.hitByBat(swingPow, batCenterX);
                        state = HIT_RESOLUTION;
                        ballHit.play();
                    }
                    if (!batter.isSwinging() &&
                        ball.getPosition().intersects(batter.getPosition())) {
                        // batter bunts the ball (doesn't swing but hits the ball)
                        float swingPow = batter.getSwingPower();
                        float batCenterX = batter.getShape().getPosition().x;
                        ball.hitByBat(swingPow, batCenterX);
                        state = HIT_RESOLUTION;
                        ballHit.play();
                    }
                    else {
                        // If ball passes the batter -> strike (batter miss)
                        if (ball.getShape().getPosition().y > plateY + 40.0f) {
                            // Batter missed: count a strike
                            strikes++;
                            // Reset the ball for next pitch if strikes < 3
                            ball.reset(moundX, moundY + 40.0f);
                            state = WAITING_FOR_PITCH;
                            acceptInput = true;
                            strikeSound.play();

                            // 3 strikes = pitcher scores point
                            if (strikes >= 3) {
                                pitcherScore++;
                                // Reset counters and positions
                                strikes = 0; 

                                scoreSound.play();

                                // Check for win condition
                                if (pitcherScore >= WIN_SCORE) {
                                    isPaused = true;
                                    gameOver = true;
                                    state = WAITING_FOR_PITCH;
                                    messageText.setString("Pitcher wins! Press Enter to restart");
                                    FloatRect tr = messageText.getLocalBounds();
                                    messageText.setOrigin(tr.width / 2, tr.height / 2);
                                    messageText.setPosition(vm.width / 2, vm.height / 2);
                                    continue; // skip resetting positions since game ended
                                }

                                // Reset positions
                                pitcher.setPosition(moundX, moundY);
                                batter.setPosition(vm.width / 2.0f, plateY);
                                batter.resetSwing();
                                ball.reset(moundX, moundY + 40.0f);
                            }
                        }
                    }
                }
            }
            else if (state == HIT_RESOLUTION) {
                // If pitcher intersects the ball, pitcher catches the ball and scores
                if (ball.getPosition().intersects(pitcher.getPosition())) {
                    // Pitcher caught the ball
                    pitcherScore++;

                    // Check for win condition
                    if (pitcherScore >= WIN_SCORE) {
                        isPaused = true;
                        gameOver = true;
                        state = WAITING_FOR_PITCH;
                        messageText.setString("Pitcher wins! Press Enter to restart");
                        FloatRect tr = messageText.getLocalBounds();
                        messageText.setOrigin(tr.width / 2, tr.height / 2);
                        messageText.setPosition(vm.width / 2, vm.height / 2);
                        continue; // skip resetting positions since game ended
                    }

                    // Reset everything
                    ball.reset(moundX, moundY + 40.0f);
                    state = WAITING_FOR_PITCH;
                    acceptInput = true;
                    strikes = 0; 
                    // Reset positions
                    pitcher.setPosition(moundX, moundY);
                    batter.setPosition(vm.width / 2.0f, plateY);
                    batter.resetSwing();

                    catchSound.play();
                }
                else {
                    // If ball reaches top of screen
                    if (ball.getPosition().top < 0) {
                        // Home Run
                        batterScore++;
                        scoreSound.play();

                        if (batterScore >= WIN_SCORE) {
                            isPaused = true;
                            gameOver = true;
                            state = WAITING_FOR_PITCH;
                            messageText.setString("Batter wins! Press Enter to restart");
                            FloatRect tr = messageText.getLocalBounds();
                            messageText.setOrigin(tr.width / 2, tr.height / 2);
                            messageText.setPosition(vm.width / 2, vm.height / 2);
                            continue;
                        }

                        // Reset
                        ball.reset(moundX, moundY + 40.0f);
                        state = WAITING_FOR_PITCH;
                        acceptInput = true;
                        strikes = 0; 
                        pitcher.setPosition(moundX, moundY);
                        batter.setPosition(vm.width / 2.0f, plateY);
                        batter.resetSwing();
                    }
                    if (ball.getPosition().left < 0 || 
                        ball.getPosition().left + ball.getPosition().width> window.getSize().x){
                            // ball bounces off walls
                            ball.reboundSides();
                    }
                }
            }
        }// End if(!isPaused)


        /*
        ****************************************
        Draw the scene
        ****************************************
        */
        window.clear();

        // Draw the background
        window.draw(spriteBackground);

        if (!gameOver) {
            std::stringstream ss;
            ss << "Pitcher: " << pitcherScore << "   Batter: "
                << batterScore << "   Strikes: " << strikes;
            hud.setString(ss.str());
            window.draw(hud);
        }

        // Draw play objects
        window.draw(pitcher.getShape());
        window.draw(batter.getShape());
        window.draw(ball.getShape());

        // Draw instructions if waiting for input
        if (isPaused && gameOver) {
            window.draw(messageText); // draw win text
        }
        if (state == WAITING_FOR_PITCH && isPaused && !gameOver) {
            std::string controls1 = "Pitcher: Arrow keys to move. J / K / L select pitch. Space to throw.\n";
            std::string controls2 = "Batter : A / D to move, W to swing.\n";
            Text waiting(controls1 + controls2 + "Press Enter to Start", font, 32);
            waiting.setFillColor(Color::Black);
            waiting.setPosition(vm.width / 2.0f - 200, vm.height / 2.0f + 200);
            window.draw(waiting);
        }

        // Draw controls & selected pitch indicator
        std::string pitchName = (selectedPitch == Ball::FASTBALL) ? "Fastball (1)" :
            (selectedPitch == Ball::CURVEBALL) ? "Curveball (2)" : "Changeup (3)";
        Text info(pitchName + "  Pitch: Space", font, 28);
        info.setFillColor(Color::Black);
        info.setPosition(20, vm.height - 60);
        window.draw(info);

        window.display();
    }
    return 0;
}
