#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat{
private:
	Vector2f m_Position;

	// A RectangleShape object
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;

	bool m_MovingUp = false;
	bool m_MovingDown = false;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;
	float m_RightQuarterLimit;
	Sprite m_Sprite;

	Vector2f m_NormalSize;
	Vector2f m_IncreasedSize;
	bool m_IsSpecialAbilityActive;
	Clock m_CooldownTimer;

public:
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	Sprite getSprite();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void moveUp();

	void moveDown();

	void stopUp();

	void stopDown();

	void update(Time dt);

};