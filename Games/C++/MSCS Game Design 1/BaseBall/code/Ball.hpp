#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ball
{
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;

    float m_Speed = 1000.0f;
    float m_DirX = .2f;
    float m_DirY = .2f;

    // State flags
    bool m_InFlight = false;   // true after pitch and after hit (ball is active)
    bool m_HitByBat = false;   // true after bat hits the ball (ball going upwards)
public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    Sprite& getShape();
    float getXVelocity();
    void reboundSides();
    void reboundBatOrTop();
    void reboundBottom();

    void update(Time dt);

    enum PitchType { FASTBALL, CURVEBALL, CHANGEUP };

    void throwPitch(PitchType pitch, float startX, float startY);
    bool isInFlight() const;
    bool wasHitByBat() const;

    void hitByBat(float swingPower, float batCenterX);

    // Reset to "waiting" state
    void reset(float startX, float startY);
};
