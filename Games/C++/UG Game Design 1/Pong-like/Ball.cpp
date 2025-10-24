#include "Ball.h"
#include <iostream>

// This the constructor function
Ball::Ball(float startX, float startY){
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);

	// No initial boost
	m_SpeedBoostFactor = 1.0f;

	// the texture loads but doesn't actually appear on screen for some reason
	sf::Texture ballTexture;
	if(ballTexture.loadFromFile("graphics/ball.png")){
		m_Sprite.setTexture(ballTexture);
		std::cout << "Ball texture loaded successfully." << std::endl;
	}
	else {
		std::cout << "Ball texture has failed to load." << std::endl;
	}

	// Set the sprite's initial position to match the RectangleShape
	m_Sprite.setPosition(m_Position);

	// Set the sprite's size to match the RectangleShape
	m_Sprite.setScale(m_Shape.getSize().x / m_Sprite.getLocalBounds().width, m_Shape.getSize().y / m_Sprite.getLocalBounds().height);
}

FloatRect Ball::getPosition(){
	return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape(){
	return m_Shape;
}

Sprite Ball::getSprite() {
	return m_Sprite;
}

float Ball::getXVelocity(){
	return m_DirectionX;
}

void Ball::reboundSides(){
	m_DirectionX = -m_DirectionX;

	m_DirectionX *= m_SpeedBoostFactor;
}

void Ball::reboundTop(){
	m_DirectionY = -m_DirectionY;

	m_DirectionX *= m_SpeedBoostFactor;
}

void Ball::reboundBat() {
	m_DirectionX = -m_DirectionX;

	// Apply the speed boost when the ball hits the bat
	m_DirectionX *= m_SpeedBoostFactor;
}

void Ball::reboundBottom(){
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = -m_DirectionY;

	m_DirectionX *= m_SpeedBoostFactor;
}

void Ball::update(Time dt){
	// Update the ball position variables
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);

	// Update the sprite's position to match the RectangleShape
	m_Sprite.setPosition(m_Position);
}