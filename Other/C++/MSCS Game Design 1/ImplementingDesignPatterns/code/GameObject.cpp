#include "GameObject.hpp"

using namespace sf;

void GameObject::handleInput(Event const& event)
{
	// intentionally left empty
}

void GameObject::update(Time dt)
{
	// intentionally left empty
}

void GameObject::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(sprite, states);
}

FloatRect GameObject::getCollider() const
{
	return sprite.getGlobalBounds();
}