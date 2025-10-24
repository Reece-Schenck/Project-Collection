#pragma once

#include "GameObserver.hpp"

class CollisionCounter : public GameObserver, public sf::Drawable
{
public:
	CollisionCounter(sf::Vector2f pos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void onNotify(GameObject const& obj, GameEvent evt) override;
private:
	static sf::Font font;
	sf::Text text;
	int count;
};