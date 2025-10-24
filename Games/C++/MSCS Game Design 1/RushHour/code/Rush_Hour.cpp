// Include important libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>

// Make code easier to type with "using namespace" 
using namespace sf;

// Function declaration
void updateCars(int seed);

const int NUM_CARS = 6;
Sprite cars[NUM_CARS];

// Where is the player/car?
// Left or Right
enum class side { LEFT, RIGHT, NONE };
side carPositions[NUM_CARS];


// This is where our game starts from int main()
int main()
{
	// Create a video mode object 
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Rush Hour!!!", Style::Fullscreen);

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

	// Prepare the deer
	Texture textureDeer;
	textureDeer.loadFromFile("graphics/deer.png");
	Sprite spriteDeer;
	spriteDeer.setTexture(textureDeer);
	spriteDeer.setPosition(0, 800);

	// Is the deer currently moving?
	bool deerActive = false;

	// How fast can the deer move
	float deerSpeed = 0.0f;

	// make 3 bird sprites from 1 texture
	Texture textureBird;

	// Load 1 new texture
	textureBird.loadFromFile("graphics/bird.png");

	// 3 New sprites with the same texture
	Sprite spriteBird1;
	Sprite spriteBird2;
	Sprite spriteBird3;
	spriteBird1.setTexture(textureBird);
	spriteBird2.setTexture(textureBird);
	spriteBird3.setTexture(textureBird);

	// Position the birds on the left of the screen
	// at different heights
	spriteBird1.setPosition(0, 0);
	spriteBird2.setPosition(0, 250);
	spriteBird3.setPosition(0, 500);

	// Are the birds currently on screen?
	bool bird1Active = false;
	bool bird2Active = false;
	bool bird3Active = false;

	// How fast is each bird?
	float bird1Speed = 0.0f;
	float bird2Speed = 0.0f;
	float bird3Speed = 0.0f;

	// Variables to control time itself
	Clock clock;

	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 50;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Magenta);
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
	font.loadFromFile("fonts/Branda-yolq.ttf");

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
	messageText.setFillColor(Color::Black);
	scoreText.setFillColor(Color::Black);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	scoreText.setPosition(20, 20);

	// Prepare 5 cars
	Texture textureCar;
	textureCar.loadFromFile("graphics/car.png");

	// Set the texture for each car sprite
	for (int i = 0; i < NUM_CARS; i++) {
		cars[i].setTexture(textureCar);

		cars[i].setPosition(-2000, -2000);

		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its po-sition
		cars[i].setOrigin(220, 20);
	}


	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	// Jumping state
	bool isJumping = false;
	float jumpHeight = 250.0f;
	float jumpProgress = 0.0f;
	float jumpDuration = 0.75f;

	// The player starts on the left
	side playerSide = side::LEFT;

	// Prepare the explosion
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 860);

	// Control the player input
	bool acceptInput = false;

	// Prepare the sound
	// tire screech
	SoundBuffer tireBuffer;
	tireBuffer.loadFromFile("sound/rubber-tire-screech.wav");
	Sound tire;
	tire.setBuffer(tireBuffer);

	// explosion
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// Out of time
	SoundBuffer ootBuffer;
	ootBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(ootBuffer);

	// Jump
	SoundBuffer jumpBuffer;
	jumpBuffer.loadFromFile("sound/jump.wav");
	Sound jump;
	jump.setBuffer(jumpBuffer);

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
			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;

			// Reset the time and the score
			score = 0;
			timeRemaining = 6;

			// Make all the cars disappear
			for (int i = 1; i < NUM_CARS; i++)
			{
				carPositions[i] = side::NONE;
			}

			// Make sure the explosion is hidden
			spriteRIP.setPosition(675, 2000);

			// Move the player into position
			spritePlayer.setPosition(750, 720);

			acceptInput = true;
			isJumping = false;
		}

		// Wrap the player controls to
		// Make sure we are accepting input
		if (acceptInput && !isJumping)
		{

			// Jumping
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				isJumping = true;
				jumpProgress = 0.0f;
				// disable lane switching during jump
				acceptInput = false;

				// Play a jump sound
				jump.play();
			}

			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;

				score++;

				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;

				spritePlayer.setPosition(1030, 720);

				// Update the cars
				updateCars(score);

				acceptInput = false;

				// Play a tire sound
				tire.play();
			}

			// Handle the left cursor key
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// Make sure the player is on the left
				playerSide = side::LEFT;

				score++;

				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;

				spritePlayer.setPosition(750, 720);

				// update the cars
				updateCars(score);

				acceptInput = false;

				// Play a tire sound
				tire.play();
			}
		}


		/*
		****************************************
		Update the scene
		****************************************
		*/

		if (!paused)
		{
			// Measure time
			Time dt = clock.restart();

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f) {


				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Out of time!!!");

				// Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the out of time sound
				outOfTime.play();

			}


			// Setup the deer
			if (!deerActive)
			{

				// How fast is the deer
				srand((int)time(0));
				deerSpeed = (rand() % 250) + 500;

				// How high is the deer
				srand((int)time(0) * 10);
				float height = (rand() % 150) + 700;
				spriteDeer.setPosition(2000, height);
				deerActive = true;

			}
			else
				// Move the deer
			{

				spriteDeer.setPosition(
					spriteDeer.getPosition().x -
					(deerSpeed * dt.asSeconds()),
					spriteDeer.getPosition().y);

				// Has the deer reached the left-hand edge of the screen?
				if (spriteDeer.getPosition().x < -100)
				{
					// Set it up ready to be a whole new deer next frame
					deerActive = false;
				}
			}

			// Manage the birdds
			// Birdd 1
			if (!bird1Active)
			{

				// How fast is the birdd
				srand((int)time(0) * 10);
				bird1Speed = (rand() % 200) + 50;

				// How high is the bird
				srand((int)time(0) * 10);
				float height = (rand() % 150) + 50;
				spriteBird1.setPosition(-200, height);
				bird1Active = true;
			}
			else
			{
				spriteBird1.setPosition(
					spriteBird1.getPosition().x +
					(bird1Speed * dt.asSeconds()),
					spriteBird1.getPosition().y);

				// Has the bird reached the right hand edge of the screen?
				if (spriteBird1.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new bird next frame
					bird1Active = false;
				}
			}
			// Bird 2
			if (!bird2Active)
			{

				// How fast is the bird
				srand((int)time(0) * 20);
				bird2Speed = (rand() % 200) + 50;

				// How high is the bird
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteBird2.setPosition(-200, height);
				bird2Active = true;


			}
			else
			{

				spriteBird2.setPosition(
					spriteBird2.getPosition().x +
					(bird2Speed * dt.asSeconds()),
					spriteBird2.getPosition().y);

				// Has the bird reached the right hand edge of the screen?
				if (spriteBird2.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new bird next frame
					bird2Active = false;
				}
			}

			if (!bird3Active)
			{

				// How fast is the bird
				srand((int)time(0) * 30);
				bird3Speed = (rand() % 200) + 50;

				// How high is the bird
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteBird3.setPosition(-200, height);
				bird3Active = true;


			}
			else
			{

				spriteBird3.setPosition(
					spriteBird3.getPosition().x +
					(bird3Speed * dt.asSeconds()),
					spriteBird3.getPosition().y);

				// Has the bird reached the right hand edge of the screen?
				if (spriteBird3.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new bird next frame
					bird3Active = false;
				}
			}

			// Update the score text
			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());

			// update the car sprites
			for (int i = 0; i < NUM_CARS; i++)
			{

				float height = i * 150;

				if (carPositions[i] == side::LEFT)
				{
					// Move the sprite to the left side
					cars[i].setPosition(900, height);

					// Set the sprite rotation to normal
					cars[i].setRotation(0);
				}
				else if (carPositions[i] == side::RIGHT)
				{
					// Move the sprite to the right side
					cars[i].setPosition(1200, height);

					// Set the sprite rotation to normal
					cars[i].setRotation(0);

				}
				else
				{
					// Hide the car
					cars[i].setPosition(3000, height);
				}
			}

			// Jumping logic
			if (isJumping)
			{
				jumpProgress += dt.asSeconds();
				float progress = jumpProgress / jumpDuration;
				if (progress >= 1.0f)
				{
					isJumping = false;
					// back to ground
					spritePlayer.setPosition(spritePlayer.getPosition().x, 720);
				}
				else
				{
					// Move player up and down in an arc
					float offset = sin(progress * 3.14159f) * jumpHeight;
					spritePlayer.setPosition(spritePlayer.getPosition().x, 720 - offset);
				}
			}

			// has the player been hit by a car?
			if (!isJumping && carPositions[5] == playerSide)
			{
				// death
				paused = true;
				acceptInput = false;

				// Draw the explosion
				spriteRIP.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y);

				// hide the player
				spritePlayer.setPosition(2000, 660);

				// Change the text of the message
				messageText.setString("CRASHED!!!");

				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();

				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);


				// Play the death sound
				death.play();
			}

			// Check collision with deer
			if (!isJumping && spritePlayer.getGlobalBounds().intersects(spriteDeer.getGlobalBounds()))
			{
				// death
				paused = true;
				acceptInput = false;

				// Draw the explosion
				spriteRIP.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y);

				// hide the player
				spritePlayer.setPosition(2000, 660);

				// Change the text of the message
				messageText.setString("HIT BY A DEER!!!");

				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();

				messageText.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the death sound
				death.play();
			}

		} // End if(!paused)

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame 
		window.clear();

		// Draw the background
		window.draw(spriteBackground);

		// Draw the birds
		window.draw(spriteBird1);
		window.draw(spriteBird2);
		window.draw(spriteBird3);

		// Draw the cars
		for (int i = 0; i < NUM_CARS; i++)
		{
			window.draw(cars[i]);
		}


		// Draw the player
		window.draw(spritePlayer);

		// Draw the explosion
		window.draw(spriteRIP);

		// Draw the deer
		window.draw(spriteDeer);

		// Draw the score
		window.draw(scoreText);

		// Draw the timebar
		window.draw(timeBar);


		if (paused)
		{
			// Draw message
			window.draw(messageText);
		}
 
		window.display();
	}
	return 0;
}

void updateCars(int seed)
{
	// Move all the cars down one place
	for (int j = NUM_CARS - 1; j > 0; j--)
	{
		carPositions[j] = carPositions[j - 1];
	}

	// Spawn a new car at position 0
	// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);

	switch (r) {
	case 0:
		carPositions[0] = side::LEFT;
		break;

	case 1:
		carPositions[0] = side::RIGHT;
		break;

	default:
		carPositions[0] = side::NONE;
		break;
	}
}