// Pong.cpp : Defines the entry point for the console application.

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

// whenever I try to run the game with audio it crashes and I don't know why
#include <SFML/Audio.hpp>
// for getting desktop screen size
#include "wtypes.h"
#include <iostream>

using namespace sf;
using namespace std;

int main(){
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Pong", Style::Fullscreen);


	int score = 0;
	int lives = 1;

	// Create a bat
	Bat bat(1900, 1080/2);

	Ball ball(1920/2, 1080/2);
	ball.setSpeedBoostFactor(1.35f);

	// Create a Text object called HUD
	Text hud;

	// A cool retro-style font
	Font font;
	font.loadFromFile("fonts/ArmWrestler.ttf");

	// Set the font to our retro-style
	hud.setFont(font);

	// Make it nice and big
	hud.setCharacterSize(75);

	// Choose a color
	hud.setFillColor(Color::White);

	hud.setPosition(20, 20);

	// Here is our clock for timing everything
	Clock clock;

	SoundBuffer hitBuffer;
	SoundBuffer deathBuffer;

	Sound hitSound;
	Sound deathSound;

	//if(hitBuffer.loadFromFile("sound/hit.wav")){
	//	hitSound.setBuffer(hitBuffer);
	//}

	//if(deathBuffer.loadFromFile("sound/game-over.wav")){
	//	deathSound.setBuffer(deathBuffer);
	//}

	while(window.isOpen()){
		/*
		Handle the player input
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed) {
				// Quit the game when the window is closed
				window.close();
			}
		}

		// Handle the player quitting
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}

		// Handle the pressing and releasing of the arrow keys
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}

		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}

		if(Keyboard::isKeyPressed(Keyboard::Up)){
			bat.moveUp();
		}
		else{
			bat.stopUp();
		}

		if(Keyboard::isKeyPressed(Keyboard::Down)){
			bat.moveDown();
		}
		else{
			bat.stopDown();
		}

		/*
		Update the bat, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		// Update the HUD text
		stringstream ss;
		ss << "Score: " << score << "     Lives: " << lives;
		hud.setString(ss.str());


		// Handle ball hitting the right
		if(ball.getPosition().left > window.getSize().x){

			ball.setSpeedBoostFactor(0.5f);

			ball.reboundBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if(lives < 1){
				//deathSound.play();
				
				// reset the score
				score = 0;
				// reset the lives
				lives = 1;
			}

		}

		// Handle ball hitting top or bottom
		if(ball.getPosition().top < 0 || ball.getPosition().top + 10 > window.getSize().y){
			ball.setSpeedBoostFactor(0.95f);

			ball.reboundTop();

			// Add a point to the players score
			score++;
		}

		// Handle ball hitting left side
		if(ball.getPosition().left < 0){
			ball.setSpeedBoostFactor(0.95f);

			ball.reboundSides();

			// Add a point to the players score
			score++;
		}

		// Has the ball hit the bat?
		if(ball.getPosition().intersects(bat.getPosition())){
			ball.setSpeedBoostFactor(1.35f);

			// Hit detected so reverse the ball and score a point
			ball.reboundBat();

			//hitSound.play();

			// Add a point to the players score
			score++;
		}

		// grants more lives and points the better the player does
		if(score != 0 && score % 25 == 0){
			lives += 1;
			score += 5;
		}

		/*
		Draw the bat, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		window.clear();
		window.draw(hud);

		window.draw(bat.getShape());
		window.draw(ball.getShape());

		window.draw(bat.getSprite());
		window.draw(ball.getSprite());

		window.display();
	}

	return 0;
}