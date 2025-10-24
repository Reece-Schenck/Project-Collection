#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	// How fast is each zombie type?
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;

	float m_SpeedModifier;
	int m_Type; // Add a member variable to store the zombie type

	bool m_IsStunned; // Add a member variable to track the stunned state
	sf::Clock m_StunTimer; // Add a clock to keep track of stun duration

	bool m_IsFleeing;  // Add a member variable to track the flee state
	sf::Clock m_FleeTimer;  // Add a clock to keep track of flee duration

	// How tough is each zombie type
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 2;
	const float CRAWLER_HEALTH = 3;

	// Make each zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	// Where is this zombie?
	Vector2f m_Position;

	// A sprite for the zombie
	Sprite m_Sprite;

	// How fast can this one run/crawl?
	float m_Speed;

	// How much health has it got?
	float m_Health;

	// Is it still alive?
	bool m_Alive;

	// Public prototypes go here	
public:
	void increaseSpeedModifier();

	// Add a member function to set the zombie type
	void setType(int type);

	// Handle when a bullet hits a zombie
	bool hit();

	void stun();

	void flee(float elapsedTime, Vector2f playerLocation);

	void resumeNormalBehavior();

	// Find out if the zombie is alive
	bool isAlive();

	// Spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);

	// Return a rectangle that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);
};