#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bat
{
private:
    Vector2f m_Position;

    Sprite m_Sprite;              // normal batter sprite
    Sprite m_SwingSprite;         // batter when swinging
    Texture m_Texture;            // holds the base texture
    Texture m_SwingTexture;       // holds the swing texture

    float m_Speed = 1000.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft = false;

    // Swing mechanics
    bool m_Swinging = false;
    float m_SwingPower = 0.5f; // how strong the current swing is
    Time m_SwingTimer;
    Time m_SwingDuration = milliseconds(220); // how long swing lasts
public:
    Bat(float startX, float startY);
    FloatRect getPosition();  
    Sprite& getShape();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(Time dt);

    // Swing controls
    // start a swing (returns false if already swinging)
    bool startSwing();
    // returns whether currently swinging
    bool isSwinging() const;
    // Returns the current swing power (0.5 to 1)
    float getSwingPower() const;

    void setPosition(float x, float y);

    void resetSwing();
};
