#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Simple abstrace base class for game objects.
/// </summary>
/// <remarks>
/// All game objects have a sprite and simple collision rectangle.
/// This class alsoprovides for object-specific game loop operations,
/// such as handeling input, updating the object, and drawing the object.
/// </remarks>
class GameObject 
	: public sf::Drawable
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	virtual void handleInput(sf::Event const&);

	/// <summary>
	/// Update the state of this object incramentally 
	/// (i.e., one frame's worth of update)
	/// </summary>
	/// <param name="dt">the elapsed time (in seconds) since the last frame</param>
	virtual void update(sf::Time dt);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::FloatRect getCollider() const;

protected:
	sf::Sprite sprite;
};