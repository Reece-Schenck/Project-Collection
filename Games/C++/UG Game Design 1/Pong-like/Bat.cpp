#include "Bat.h"
#include <iostream>

// This the constructor and it is called when we create an object
Bat::Bat(float startX, float startY){
	m_Position.x = startX;
	m_Position.y = startY;

	m_NormalSize = sf::Vector2f(25, 100);

	m_Shape.setSize(m_NormalSize);

	// Increased size during special ability
	m_IncreasedSize = sf::Vector2f(25, 300);
	// Special ability not active initially
	m_IsSpecialAbilityActive = false;

	m_Shape.setPosition(m_Position);

	m_RightQuarterLimit = startX - (1920 / 4);

	// the texture loads but doesn't actually appear on screen for some reason
	sf::Texture batTexture;
	if(batTexture.loadFromFile("graphics/bat.png")){
		m_Sprite.setTexture(batTexture);
		std::cout << "Bat texture loaded successfully." << std::endl;
	}
	else {
		std::cout << "Bat texture has failed to load." << std::endl;
	}

	// Set the sprite's initial position to match the RectangleShape
	m_Sprite.setPosition(m_Position);

	// Set the sprite's size to match the RectangleShape
	m_Sprite.setScale(m_Shape.getSize().x / m_Sprite.getLocalBounds().width, m_Shape.getSize().y / m_Sprite.getLocalBounds().height);
}

FloatRect Bat::getPosition(){
	return m_Shape.getGlobalBounds();
}

Sprite Bat::getSprite(){
	return m_Sprite;
}

RectangleShape Bat::getShape(){
	return m_Shape;
}

void Bat::moveLeft(){
	m_MovingLeft = true;
}

void Bat::moveRight(){
	m_MovingRight = true;
}

void Bat::stopLeft(){
	m_MovingLeft = false;
}

void Bat::stopRight(){
	m_MovingRight = false;
}

void Bat::moveUp(){
	m_MovingUp = true;
}

void Bat::moveDown(){
	m_MovingDown = true;
}

void Bat::stopUp(){
	m_MovingUp = false;
}

void Bat::stopDown(){
	m_MovingDown = false;
}

void Bat::update(sf::Time dt){
	if(m_MovingLeft){
		if(m_Position.x + m_Shape.getSize().x + m_Speed * dt.asSeconds() >= m_RightQuarterLimit){
			m_Position.x -= m_Speed * dt.asSeconds();
		}
	}

	if(m_MovingRight){
		if(m_Position.x + m_Shape.getSize().x + m_Speed * dt.asSeconds() <= 1920){
			m_Position.x += m_Speed * dt.asSeconds();
		}
	}

	if(m_MovingUp){
		if(m_Position.y - m_Speed * dt.asSeconds() >= 0){
			m_Position.y -= m_Speed * dt.asSeconds();
		}
	}

	if(m_MovingDown){
		if(m_Position.y + m_Shape.getSize().y + m_Speed * dt.asSeconds() <= 1080){
			m_Position.y += m_Speed * dt.asSeconds();
		}
	}

	// Check if the special ability is active
	if(m_IsSpecialAbilityActive){
		// Check if the special ability duration has elapsed
		if(m_CooldownTimer.getElapsedTime().asSeconds() >= 10.0f){
			// Disable the special ability
			m_IsSpecialAbilityActive = false;

			// Set the size back to normal
			m_Shape.setSize(m_NormalSize);

			// Start the cooldown timer
			m_CooldownTimer.restart();
		}
	}
	else{
		// Check if the cooldown has elapsed
		if(m_CooldownTimer.getElapsedTime().asSeconds() >= 30.0f){
			// Activate the special ability when space bar is pressed
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				m_IsSpecialAbilityActive = true;

				m_CooldownTimer.restart();

				// Set the increased size during the special ability
				m_Shape.setSize(m_IncreasedSize);
			}
		}
	}

	m_Shape.setPosition(m_Position);

	// Update the sprite's position to match the RectangleShape
	m_Sprite.setPosition(m_Position);
}