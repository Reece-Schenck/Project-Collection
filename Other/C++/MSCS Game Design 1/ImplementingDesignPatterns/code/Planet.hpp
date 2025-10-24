#pragma once

// Container of unique elements, no duplicates allowed
#include <set> // could use vector if you don't care about duplicates

#include "GameObject.hpp"
#include "GameObserver.hpp"

class Planet : public GameObject
{
public:
	Planet(sf::Vector2f center);
	void hit();
	void destroy();
	void notify(GameObject const& obj, GameEvent evt);
	void addObserver(GameObserver* obj);
	void removeObserver(GameObserver* obj);
private:
	// List of observers
	std::set<GameObserver*> observers;
	int health;
	static sf::Texture texture;
};