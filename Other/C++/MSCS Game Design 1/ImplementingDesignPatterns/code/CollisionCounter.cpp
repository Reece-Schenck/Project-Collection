#include "CollisionCounter.hpp"

using namespace sf;
using namespace std;


Font CollisionCounter::font; // static variable initialization

CollisionCounter::CollisionCounter(Vector2f pos)
	: count(0)
{
	font.loadFromFile("../../SFML-2.6.0/examples/opengl/resources/tuffy.ttf");
	text.setFont(font);
	text.setCharacterSize(48);
	text.setString("Collisions: " + to_string(count));
	text.setPosition(pos);
}

void CollisionCounter::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(text);
}

void CollisionCounter::onNotify(GameObject const& obj, GameEvent evt)
{
	if (evt == GameEvent::COLLISION_EVENT) {
		count++;
		text.setString("Collisions: " + to_string(count));
	}
}