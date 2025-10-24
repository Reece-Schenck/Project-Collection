#include "Planet.hpp"

using namespace sf;
using namespace std;

Texture Planet::texture; // must initialize the static variable

Planet::Planet(Vector2f center) : health(100) // initialize the variable
{
	texture.loadFromFile("graphics/planet.png");
	sprite.setTexture(texture);
	sprite.setOrigin(static_cast<Vector2f>(texture.getSize()) / 2.0f); // center the planet
	sprite.setPosition(center);
}

void Planet::hit()
{
	if (health > 0) {
		health--;
		notify(*this, GameEvent::COLLISION_EVENT);
		if (health <= 0) {
			destroy();
		}
	}
}

void Planet::destroy()
{
	// move it off screen
	sprite.setPosition(numeric_limits<float>::infinity(), 
		               numeric_limits<float>::infinity());
}

void Planet::notify(GameObject const& obj, GameEvent evt)
{
	for (auto observer : observers) {
		observer->onNotify(obj, evt);
		// or:
		//(*observer).onNotify(obj, evt);
	}
}

void Planet::addObserver(GameObserver* obj)
{
	observers.insert(obj);
}

void Planet::removeObserver(GameObserver* obj)
{
	observers.erase(obj);
}