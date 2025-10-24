#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Planet.hpp"
#include "Asteroid.hpp"
#include "CollisionCounter.hpp"

using namespace sf;
using namespace std;

const int ASTEROID_COUNT = 10;

// for now, our Hud element is a global variable
CollisionCounter collisionCounter(Vector2f(750, 25));

// Game Loop and auxiliary functions
void gameLoop(RenderWindow& window, vector<GameObject*>& gameObjects);
void handleInput(RenderWindow& window, vector<GameObject*>& gameObjects);
void updateGame(vector<GameObject*>& gameObjects, Time dt);
void renderScene(RenderWindow& window, vector<GameObject*>& gameObjects);

void initializeGame(vector<GameObject*>& gameObjects);
void finalizeGame(vector<GameObject*>& gameObjects);

int main() 
{
	VideoMode vm(1024, 1024);
	RenderWindow window(vm, "Lab 3");

	View view(FloatRect(0, 0, 1024, 1024));
	window.setView(view);

	vector<GameObject*> gameObjects;
	initializeGame(gameObjects);
	gameLoop(window, gameObjects);
	finalizeGame(gameObjects);

	return 0;
}

void gameLoop(RenderWindow& window, vector<GameObject*>& gameObjects)
{
	Clock clock;
	while (window.isOpen()) {
		Time dt = clock.restart();
		handleInput(window, gameObjects);
		updateGame(gameObjects, dt);
		renderScene(window, gameObjects);
	}
}

void handleInput(RenderWindow& window, vector<GameObject*>& gameObjects)
{
	Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window.close();
			return;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape) {
				window.close();
				return;
			}
		default:
			break; // intentionally does nothing
		}

		for (auto obj : gameObjects) {
			obj->handleInput(event);
		}
	}
}

void updateGame(vector<GameObject*>& gameObjects, Time dt) 
{
	for (auto obj : gameObjects) {
		obj->update(dt);
	}
	// planet is the first element in initializeGame function
	// failed dynamic cast will result in a null pointer
	auto planet = dynamic_cast<Planet*>(gameObjects.front());
	for (auto obj : gameObjects) {
		auto asteroid = dynamic_cast<Asteroid*>(obj);
		// same as if(asteroid != nullptr)
		if (asteroid) {
			if (asteroid->getCollider().intersects(planet->getCollider())) {
				asteroid->destroy();
				planet->hit();
			}
		}
	}
}

void renderScene(RenderWindow& window, vector<GameObject*>& gameObjects)
{
	window.clear();
	for (auto obj : gameObjects) {
		window.draw(*obj);
	}
	window.draw(collisionCounter);
	window.display();
}

void initializeGame(vector<GameObject*>& gameObjects) 
{
	const int RADIUS = 512;
	const Vector2f center(512, 512);

	gameObjects.push_back(new Planet(center));

	auto planet = dynamic_cast<Planet*>(gameObjects.front());
	planet->addObserver(&collisionCounter);

	for (int i = 0; i < ASTEROID_COUNT; i++)
	{
		float angle = 2 * acos(-1) * i / ASTEROID_COUNT;
		float dx = cos(angle) * RADIUS;
		float dy = sin(angle) * RADIUS;
		Vector2f pos(center.x + dx, center.y + dy);

		float speed = 0.5f + (rand() / static_cast<float>(RAND_MAX));
		gameObjects.push_back(new Asteroid(pos, speed * (center - pos)));
	}
}

void finalizeGame(vector<GameObject*>& gameObjects)
{
	for (auto obj : gameObjects) {
		delete obj; // frees up the memory that was pointed to
	}
}