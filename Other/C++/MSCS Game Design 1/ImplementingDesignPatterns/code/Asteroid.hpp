#pragma once

#include "GameObject.hpp"

class Asteroid : public GameObject
{
public:
	Asteroid(sf::Vector2f position, sf::Vector2f velocity = sf::Vector2f(0, 0)); // default velocity of vector2f(0,0)
	void handleInput(sf::Event const& event) override;
	void update(sf::Time dt) override;
	void spawn();
	void destroy();
private:
	sf::Vector2f initialPosition;
	sf::Vector2f velocity;
	bool active;
	static sf::Texture texture;
};