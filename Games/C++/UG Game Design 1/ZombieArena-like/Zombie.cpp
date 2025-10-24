#include "zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Zombie::spawn(float startX, float startY, int type, int seed)
{

	switch (type)
	{
	case 0:
		// Bloater
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bloater.png"));

		m_Speed = 40;
		m_Health = 5;
		break;

	case 1:
		// Chaser
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/chaser.png"));

		m_Speed = 70;
		m_Health = 1;
		break;

	case 2:
		// Crawler
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/crawler.png"));

		m_Speed = 20;
		m_Health = 3;
		break;
	}

	// Modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	srand((int)time(0) * seed);
	// Somewhere between 80 an 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
	// Express as a fraction of 1
	modifier /= 100; // Now equals between .7 and 1
	m_Speed *= modifier;

	m_Position.x = startX;
	m_Position.y = startY;

	m_Sprite.setOrigin(25, 25);
	m_Sprite.setPosition(m_Position);

	m_SpeedModifier = 1.0f; // Initialize the speed modifier to 1.0

	//m_SpawnedCrawler = false;

	m_IsStunned = false; // Initialize the stunned state to false

	m_IsFleeing = false;  // Initialize the flee state to false

	m_Type = type; // Set the zombie type
}

void Zombie::increaseSpeedModifier()
{
	m_SpeedModifier += 0.2f;
	m_Speed *= m_SpeedModifier; // Apply the speed modifier
}

void Zombie::setType(int type)
{
	m_Type = type;
}

bool Zombie::hit()
{
	m_Health--;

	if (m_Type == 2) // Check if it's a crawler
	{
		increaseSpeedModifier(); // Increase the speed modifier for crawlers
	}
	else if (m_Type == 0) // Check if it's a bloater
	{
		stun(); // Stun the bloater
	}
	else if (m_Type == 1) // Check if it's a chaser
	{
		m_IsFleeing = true;
		m_FleeTimer.restart();
	}

	if (m_Health < 0)
	{
		// dead
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture(
			"graphics/blood.png"));

		return true;
	}

	// injured but not dead yet
	return false;
}

void Zombie::stun()
{
	m_IsStunned = true; // Set the stunned state to true
	m_StunTimer.restart(); // Restart the stun timer
}

void Zombie::flee(float elapsedTime, Vector2f playerLocation)
{
	// Check if the flee duration has passed (1 seconds)
	if (m_FleeTimer.getElapsedTime().asSeconds() >= 1.0f)
	{
		m_IsFleeing = false; // Flee duration has passed, set flee state to false
		resumeNormalBehavior(); // Resume normal behavior
	}
	else
	{
		// Zombie is fleeing, move away from the player
		float fleeSpeed = 1.25 * m_Speed;  // increase flee speed

		// Calculate the angle to move away from the player
		float angle = atan2(playerLocation.y - m_Position.y, playerLocation.x - m_Position.x);
		m_Position.x -= fleeSpeed * cos(angle) * elapsedTime;
		m_Position.y -= fleeSpeed * sin(angle) * elapsedTime;

		// Set the sprite's rotation to face the fleeing direction
		m_Sprite.setRotation((angle * 180) / 3.141);
	}
}

void Zombie::resumeNormalBehavior()
{
	m_SpeedModifier = 1.5f;  // chaser moves towards the player even faster
	m_Speed *= m_SpeedModifier;  // Apply the speed modifier
}


bool Zombie::isAlive()
{
	return m_Alive;
}

FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}


Sprite Zombie::getSprite()
{
	return m_Sprite;
}

void Zombie::update(float elapsedTime,
	Vector2f playerLocation)
{
	if (m_IsFleeing)
	{
		flee(elapsedTime, playerLocation);
		return;
	}

	if (m_IsStunned)
	{
		// Check if the stun duration has passed (1 seconds)
		if (m_StunTimer.getElapsedTime().asSeconds() >= 1.0f)
		{
			m_IsStunned = false; // Stun duration has passed, set stunned state to false
		}
		else
		{
			// Zombie is stunned, don't move
			return;
		}
	}

	float playerX = playerLocation.x;
	float playerY = playerLocation.y;

	// Update the zombie position variables
	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x +
			m_Speed * elapsedTime;
	}

	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y +
			m_Speed * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x -
			m_Speed * elapsedTime;
	}

	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y -
			m_Speed * elapsedTime;
	}

	// Move the sprite
	m_Sprite.setPosition(m_Position);

	// Face the sprite in the correct direction
	float angle = (atan2(playerY - m_Position.y,
		playerX - m_Position.x)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);


}