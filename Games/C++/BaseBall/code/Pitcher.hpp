#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Pitcher {
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;

    float m_Speed = 750.0f;
    bool m_MovingLeft = false;
    bool m_MovingRight = false;
    bool m_MovingUp = false;
    bool m_MovingDown = false;

public:
    Pitcher(float startX = 960.0f, float startY = 220.0f);

    FloatRect getPosition() const;
    Sprite& getShape();

    // Movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    // freeMovement toggles whether pitcher is restricted to mound area or not
    // before the pitch (false) or allowed full movement after pitch (true).
    void update(Time dt, bool freeMovement);

    // used to compute hit direction
    float getCenterX() const;
    void setPosition(float x, float y);
};