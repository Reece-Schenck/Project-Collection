// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// for getting desktop screen size
#include "wtypes.h"
#include <iostream>
using namespace std;
void GetDesktopResolution(int& horizontal, int& vertical);

// Make code easier to type with "using namespace"
using namespace sf;

// Function declaration
void updateBranches(int seed);

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];


// Where is the player/branch? 
// Left or Right or middle
enum class side { LEFT, RIGHT, UP, NONE };
side branchPositions[NUM_BRANCHES];


int main(){
	// 
	int horizontal = 0;
	int vertical = 0;
	GetDesktopResolution(horizontal, vertical);
	const int VIRTUAL_WIDTH = horizontal;
	const int VIRTUAL_HEIGHT = vertical;
	RenderWindow window(VideoMode::getFullscreenModes()[0], "Timber!!!", Style::Fullscreen);
	View view(FloatRect(0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT));
	window.setView(view);


	// Create a video mode object
	//VideoMode vm(1920, 1080);

	// Create and open a window for the game
	//RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	// put texture in graphics folder
	textureBackground.loadFromFile("../../GameProg1/Timber!!!/graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Get the size of the window
	Vector2u windowSize = window.getSize();

	// Calculate the scaling factors for both axes
	float scaleX = static_cast<float>(windowSize.x) / VIRTUAL_WIDTH;
	float scaleY = static_cast<float>(windowSize.y) / VIRTUAL_HEIGHT;

	// Apply the scaling to the view
	view.setSize(Vector2f(windowSize));
	view.setCenter(Vector2f(windowSize.x / 2, windowSize.y / 2));
	view.zoom(min(scaleX, scaleY));

	// Set the modified view (for the any device) to the window
	window.setView(view);

	// Set the size of the spriteBackground to match the window size
	spriteBackground.setScale(
		static_cast<float>(windowSize.x) / spriteBackground.getLocalBounds().width,
		static_cast<float>(windowSize.y) / spriteBackground.getLocalBounds().height);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	// put texture in graphics folder
	textureTree.loadFromFile("../../GameProg1/Timber!!!/graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Make a second tree sprite
	Texture textureTree2;
	// put texture in graphics folder
	textureTree2.loadFromFile("../../GameProg1/Timber!!!/graphics/tree.png");
	Sprite spriteTree2;
	spriteTree2.setTexture(textureTree2);
	spriteTree2.setPosition(810, 100);

	// Prepare the bat
	Texture textureBat;
	// put texture in graphics folder
	textureBat.loadFromFile("../../GameProg1/Timber!!!/graphics/bat.png");
	Sprite spriteBat;
	spriteBat.setTexture(textureBat);
	spriteBat.setPosition(0, 800);

	// Is the bat currently moving?
	bool batActive = false;

	// How fast can the bat fly
	float batSpeed = 0.0f;


	// Prepare the bat2
	Texture textureBat2;
	// put texture in graphics folder
	textureBat2.loadFromFile("../../GameProg1/Timber!!!/graphics/bat.png");
	Sprite spriteBat2;
	spriteBat2.setTexture(textureBat2);
	spriteBat2.setPosition(0, 800);

	// Is the bat2 currently moving?
	bool bat2Active = false;

	// How fast can the bat fly
	float bat2Speed = 0.0f;


	// Prepare the bat3
	Texture textureBat3;
	// put texture in graphics folder
	textureBat3.loadFromFile("../../GameProg1/Timber!!!/graphics/bat.png");
	Sprite spriteBat3;
	spriteBat3.setTexture(textureBat3);
	spriteBat3.setPosition(1920 / 2, 1080);
	spriteBat3.setScale(-1.0f, 1.0f); // Flip bat3 horizontally

	// Is the bat3 currently moving?
	bool bat3Active = false;

	// How fast can bat3 fly
	float bat3Speed = 0.0f;


	// make 3 crow sprites from 1 texture
	Texture textureCrow;

	// Load 1 new texture
	// put texture in graphics folder
	textureCrow.loadFromFile("../../GameProg1/Timber!!!/graphics/crow.png");

	// 3 New sprites withe the same texture
	Sprite spriteCrow1;
	Sprite spriteCrow2;
	Sprite spriteCrow3;
	spriteCrow1.setTexture(textureCrow);
	spriteCrow2.setTexture(textureCrow);
	spriteCrow3.setTexture(textureCrow);

	// Position the crows off screen
	spriteCrow1.setPosition(0, 0);
	spriteCrow2.setPosition(0, 150);
	spriteCrow3.setPosition(0, 300);

	// Are the crows currently on screen?
	bool crow1Active = false;
	bool crow2Active = false;
	bool crow3Active = false;

	// How fast is each crow?
	float crow1Speed = 0.0f;
	float crow2Speed = 0.0f;
	float crow3Speed = 0.0f;

	// Variables to control time itself
	Clock clock;
	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	// Track whether the game is running
	bool paused = true;
	// Draw some text
	int score = 0;

	Text messageText;
	Text scoreText;

	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/BEARPAW_.ttf");

	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	// Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	// Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	// Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	scoreText.setPosition(20, 20);

	// Prepare 5 branches
	Texture textureBranch;
	// put texture in graphics folder
	textureBranch.loadFromFile("../../GameProg1/Timber!!!/graphics/branch.png");

	// Set the texture for each branch sprite
	for(int i = 0; i < NUM_BRANCHES; i++){
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);

		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(620.5, 200.5);
	}

	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("../../GameProg1/Timber!!!/graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	// The player starts on the left
	side playerSide = side::LEFT;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("../../GameProg1/Timber!!!/graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 860);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("../../GameProg1/Timber!!!/graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(700, 700);

	spriteAxe.setScale(100.0f / spriteAxe.getLocalBounds().width, 0.5f);

	// Line the axe up with the tree
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;

	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("../../GameProg1/Timber!!!/graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 720);

	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;

	// Control the player input
	bool acceptInput = false;

	// Prepare the sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("../../GameProg1/Timber!!!/sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);

	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("../../GameProg1/Timber!!!/sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// Out of time
	SoundBuffer ootBuffer; 
	ootBuffer.loadFromFile("../../GameProg1/Timber!!!/sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(ootBuffer);

	// for special ability to reset timer
	bool specialAbilityUsed = false;

	while(window.isOpen()){

		// score ++;
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::KeyReleased && !paused){
				// Listen for key presses again
				acceptInput = true;

				// hide the axe
				spriteAxe.setPosition(2000,spriteAxe.getPosition().y);
			}
		}

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}

		// Start the game
		if(Keyboard::isKeyPressed(Keyboard::Return)){
			paused = false;
			specialAbilityUsed = false;

			// Reset the time and the score
			score = 0;
			timeRemaining = 6;

			// Make all the branches disappear
			for(int i = 1; i < NUM_BRANCHES; i++){
				branchPositions[i] = side::NONE;
			}

			// Make sure the gravestone is hidden
			spriteRIP.setPosition(675, 2000);

			// Move the player into position
			spritePlayer.setPosition(580, 720);

			acceptInput = true;
		}

		// Wrap the player controls to
		// Make sure we are accepting input
		if(acceptInput){

			// First handle pressing the right cursor key
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				// Make sure the player is on the right
				playerSide = side::RIGHT;

				score++;

				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;

				spriteAxe.setPosition(AXE_POSITION_RIGHT,spriteAxe.getPosition().y);


				spritePlayer.setPosition(1050, 720);

				// update the branches
				updateBranches(score);

				// set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();
			}

			// Handle the left cursor key
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				// Make sure the player is on the left
				playerSide = side::LEFT;

				score++;

				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;

				spriteAxe.setPosition(AXE_POSITION_LEFT,spriteAxe.getPosition().y);


				spritePlayer.setPosition(580, 720);

				// update the branches
				updateBranches(score);

				// set the log flying
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();
			}

			// Handle the Up cursor key
			// Player in the middle does not get hit by branches, BUT continues to lose time and doesn't get any score
			if(Keyboard::isKeyPressed(Keyboard::Up)){
				// Make sure the player is actually up
				playerSide = side::UP;

				spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);

				spritePlayer.setPosition(815, 720);

				// update the branches
				updateBranches(score);

				// set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();
			}

			// for special ability to reset the timer(can be good or bad depending on when it is activated)
			if(Keyboard::isKeyPressed(Keyboard::Space) && !specialAbilityUsed){
				// Player pressed spacebar and hasn't used the ability yet

				// Activate the special ability
				specialAbilityUsed = true;
				// reset the timer
				timeRemaining = 7;

			}
		}


		/*
		****************************************
		Update the scene
		****************************************
		*/
		if(!paused){

			// Measure time
			Time dt = clock.restart();

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));


			if(timeRemaining <= 0.0f){

				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Out of time!!");

				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the out of time sound
				outOfTime.play();
			}

			
			// Setup the bat
			if(!batActive){

				// How fast is the bat
				srand((int)time(0) * 10);
				batSpeed = (rand() % 200) + 200;

				// How high is the bat
				srand((int)time(0) * 10); 
				float height = (rand() % 500) + 500; 
				spriteBat.setPosition(2000, height); 
				batActive = true; 

			}
			else{
				// Move the bat

				spriteBat.setPosition(
					spriteBat.getPosition().x -
					(batSpeed * dt.asSeconds()),
					spriteBat.getPosition().y);

				// Has the bat reached the right hand edge of the screen?
				if(spriteBat.getPosition().x < -200){
					// Set it up ready to be a whole new crow next frame
					batActive = false;
				}
			}


			// has bat2 come from the opposite side of bat 1
			if(!bat2Active){

				// How fast is the bat2
				srand((int)time(0) * 10);
				bat2Speed = (rand() % 200) + 200;

				// How high is the bat2
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBat2.setPosition(-100, height);
				bat2Active = true;

			}
			else{
				// Move the bat2

				spriteBat2.setPosition(
					spriteBat2.getPosition().x +
					(bat2Speed * dt.asSeconds()),
					spriteBat2.getPosition().y);

				// Has the bat2 reached the left hand edge of the screen?
				if (spriteBat2.getPosition().x > VIRTUAL_WIDTH + 200) {
					// Set it up ready to be a whole new crow next frame
					bat2Active = false;
				}
			}

			// Move bat3 from bottom to top
			if(!bat3Active){
				// How fast is bat3
				srand((int)time(0) * 15);
				bat3Speed = (rand() % 200) + 200;

				// Set the initial position of bat3 at the bottom of the screen
				spriteBat3.setPosition((rand() % VIRTUAL_WIDTH), 1080);
				bat3Active = true;
			}
			else{
				// Move bat3 upwards
				spriteBat3.setPosition(
					spriteBat3.getPosition().x,
					spriteBat3.getPosition().y - (bat3Speed * dt.asSeconds()));

				// Has bat3 reached the top of the screen?
				if(spriteBat3.getPosition().y < -100){
					// Reset bat3 to come from the bottom again
					bat3Active = false;
				}
			}

			// Manage the crows
			// Crow 1
			if(!crow1Active){

				// How fast is the crow
				srand((int)time(0) * 10);
				crow1Speed = (rand() % 200);

				// How high is the crow
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCrow1.setPosition(-200, height);
				crow1Active = true;


			}
			else{

				spriteCrow1.setPosition(
					spriteCrow1.getPosition().x +
					(crow1Speed * dt.asSeconds()),
					spriteCrow1.getPosition().y);

				// Has the crow reached the right hand edge of the screen?
				if(spriteCrow1.getPosition().x > 1920){
					// Set it up ready to be a whole new crow next frame
					crow1Active = false;
				}
			}
			// Crow 2
			if(!crow2Active){

				// How fast is the crow
				srand((int)time(0) * 20);
				crow2Speed = (rand() % 200);

				// How high is the crow
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCrow2.setPosition(-200, height);
				crow2Active = true;


			}
			else{

				spriteCrow2.setPosition(
					spriteCrow2.getPosition().x +
					(crow2Speed * dt.asSeconds()),
					spriteCrow2.getPosition().y);

				// Has the crow reached the right hand edge of the screen?
				if(spriteCrow2.getPosition().x > 1920){
					// Set it up ready to be a whole new crow next frame
					crow2Active = false;
				}
			}

			if(!crow3Active){

				// How fast is the crow
				srand((int)time(0) * 30);
				crow3Speed = (rand() % 200);

				// How high is the crow
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCrow3.setPosition(-200, height);
				crow3Active = true;


			}
			else{

				spriteCrow3.setPosition(
					spriteCrow3.getPosition().x +
					(crow3Speed * dt.asSeconds()),
					spriteCrow3.getPosition().y);

				// Has the crow reached the right hand edge of the screen?
				if(spriteCrow3.getPosition().x > 1920){
					// Set it up ready to be a whole new crow next frame
					crow3Active = false;
				}
			}

			// Update the score text
			stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());

			// update the branch sprites
			for(int i = 0; i < NUM_BRANCHES; i++){

				float height = i * 150;

				if(branchPositions[i] == side::LEFT){
					// Move the sprite to the left side
					branches[i].setPosition(480, height);
					// Flip the sprite round the other way
					branches[i].setOrigin(620.5, 200.5);
					// Flip the sprite round the other way
					branches[i].setRotation(180);
				}
				else if(branchPositions[i] == side::RIGHT){
					// Move the sprite to the right side
					branches[i].setPosition(1530, height);
					// Set the sprite rotation to normal
					branches[i].setOrigin(620.5, 200.5);
					// Set the sprite rotation to normal
					branches[i].setRotation(0);

				}
				else{
					// Hide the branch
					branches[i].setPosition(3000, height);
				}
			}

			// Handle a flying log				
			if(logActive){

				spriteLog.setPosition(
					spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));

				// Has the insect reached the right hand edge of the screen?
				if(spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000){
					// Set it up ready to be a whole new cloud next frame
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}

			// has the player been squished by a branch?
			if(branchPositions[5] == playerSide){
				// death
				paused = true;
				acceptInput = false;

				// Draw the gravestone
				spriteRIP.setPosition(525, 760);

				// hide the player
				spritePlayer.setPosition(2000, 660);

				// Change the text of the message
				messageText.setString("SQUISHED!!");

				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();

				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f,1080 / 2.0f);

				// Play the death sound
				death.play();
			}

		}// End if(!paused)

		 /*
		 ****************************************
		 Draw the scene
		 ****************************************
		 */

		 // Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the crows
		window.draw(spriteCrow1);
		window.draw(spriteCrow2);
		window.draw(spriteCrow3);

		// Draw the branches
		for(int i = 0; i < NUM_BRANCHES; i++){
			window.draw(branches[i]);
		}

		// Draw the tree
		window.draw(spriteTree);
		window.draw(spriteTree2);

		// Draw the player
		window.draw(spritePlayer);

		// Draw the axe
		window.draw(spriteAxe);

		// Draraw the flying log
		window.draw(spriteLog);

		// Draw the gravestone
		window.draw(spriteRIP);

		// Drawraw the bats
		window.draw(spriteBat);
		window.draw(spriteBat2);
		window.draw(spriteBat3);

		// Draw the score
		window.draw(scoreText);

		// Draw the timebar
		window.draw(timeBar);


		if(paused){
			// Draw our message
			window.draw(messageText);
		}

		// Show everything we just drew
		window.display();
	}

	return 0;
}

// Function definition
void updateBranches(int seed){
	// Move all the branches down one place
	for(int j = NUM_BRANCHES - 1; j > 0; j--){
		branchPositions[j] = branchPositions[j - 1];
	}

	// Spawn a new branch at position 0
	// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);

	switch (r){
	case 0:
		branchPositions[0] = side::LEFT;
		break;

	case 1:
		branchPositions[0] = side::RIGHT;
		break;

	default:
		branchPositions[0] = side::NONE;
		break;
	}
}

// gets the desktop resolution reguardless of native device
void GetDesktopResolution(int& horizontal, int& vertical){
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();

	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);

	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}