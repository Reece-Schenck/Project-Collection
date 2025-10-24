#include "Asteroid.hpp"

using namespace sf;
using namespace std;

Texture Asteroid::texture; // must initialize the static variable

Asteroid::Asteroid(Vector2f position, Vector2f velocity)
	: initialPosition(position), velocity(velocity), active(true) // initialize the variables
{
	if (texture.getSize().x == 0) {
		texture.loadFromFile("graphics/moon.png");
	}
	sprite.setTexture(texture);
	sprite.setOrigin(static_cast<Vector2f>(texture.getSize()) / 2.0f);
	sprite.setPosition(position);	// center the asteroid
}

void Asteroid::handleInput(Event const& event)
{
	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Space) {
			if (!active) {
				spawn();
			}
		}
	}
}

void Asteroid::update(Time dt)
{
	if (active) {
		Vector2f newPosition = sprite.getPosition() + velocity * dt.asSeconds();
		sprite.setPosition(newPosition);
	}
}

void Asteroid::spawn()
{
	sprite.setPosition(initialPosition);
	active = true;
}

void Asteroid::destroy()
{
	// moves it off screen
	sprite.setPosition(numeric_limits<float>::infinity(),
		               numeric_limits<float>::infinity());
	active = false;
}
