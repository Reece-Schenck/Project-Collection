#include "Ball.hpp"
#include <cmath>
#include <cstdlib>

// This the constructor function
Ball::Ball(float startX, float startY) : m_Position(startX,startY)
{   
    m_Texture.loadFromFile("graphics/ball.png");
    m_Sprite.setTexture(m_Texture);

    m_Sprite.setScale(30.0f / m_Sprite.getLocalBounds().width, 30.0f / m_Sprite.getLocalBounds().height);

    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);

    // Initially not in flight
    m_InFlight = false;
    m_HitByBat = false;
    m_Speed = 0.0f;
    m_DirX = 0.0f;
    m_DirY = 0.0f;
}

FloatRect Ball::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Sprite& Ball::getShape() { 
    return m_Sprite; 
}
float Ball::getXVelocity()
{
    return m_DirX;
}

void Ball::reboundSides()
{
    m_DirX = -m_DirX;
}
void Ball::reboundBatOrTop()
{
    m_DirY = -m_DirY;
}
void Ball::reboundBottom()
{
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirY = -m_DirY;
}

void Ball::update(Time dt)
{
    if (!m_InFlight) {
        return;
    }

    // Update the ball's position
    m_Position.y += m_DirY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirX * m_Speed * dt.asSeconds();
    // Move the ball
    m_Sprite.setPosition(m_Position);
}

bool Ball::isInFlight() const { 
    return m_InFlight; 
}

bool Ball::wasHitByBat() const { 
    return m_HitByBat; 
}

// Throw a pitch from (startX,startY) downward toward the batter.
// Pitch types differ by speed and lateral curve.
void Ball::throwPitch(PitchType pitch, float startX, float startY) {
    // Start position and reset flags
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);

    m_HitByBat = false;
    m_InFlight = true;

    // Default direction: downward (positive y)
    m_DirY = 1.0f;

    switch (pitch) {
    case FASTBALL:
        m_Speed = 1300.0f;
        // small random lateral offset so not always perfectly vertical
        m_DirX = (rand() % 3 - 1) * 0.1f;
        break;
    case CURVEBALL:
        m_Speed = 900.0f;
        // curve to the side: random left/right
        m_DirX = (rand() % 2 == 0) ? -0.6f : 0.6f;
        // small random lateral offset so not always the same perfect curve
        m_DirX += (rand() % 3 - 1) * 0.1f;
        break;
    case CHANGEUP:
        m_Speed = 700.0f;
        // small random lateral offset so not always perfectly vertical
        m_DirX = (rand() % 3 - 1) * 0.05f;
        break;
    }

    // normalize direction vector (so speed scales as intended)
    // https://www.sololearn.com/en/Discuss/2397161/how-to-normalize-a-vector
    float len = std::sqrt(m_DirX * m_DirX + m_DirY * m_DirY);
    if (len != 0.0f) {
        m_DirX /= len;
        m_DirY /= len;
    }
}

// Helper to keep a value withing the required bounds
// https://stackoverflow.com/questions/9323903/most-efficient-elegant-way-to-clip-a-number
float clip(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// sets the ball to be in "hit" mode
// batCenterX is used to compute lateral direction so player can aim left/right.
void Ball::hitByBat(float swingPower, float batCenterX) {
    if (!m_InFlight) return;

    m_HitByBat = true;

    // Outgoing speed scales with swingPower and base power
    m_Speed = clip(700.0f + swingPower * 1000.0f, 700.0f, 2600.0f);

    // Ball goes upward
    m_DirY = -1.0f;

    // Lateral direction based on where bat hit relative to bat center:
    float dx = (m_Position.x - batCenterX) * 0.01f;
    // Add minor random movement for variety
    dx += (rand() % 21 - 20) * 0.025f;

    m_DirX = clip(dx, -1.0f, 1.0f);

    // make the ball more likely to go to the left side of the screen
    // also takes away the guarentee that the ball will always bounce the same way
    if(batCenterX < 1920/2 && (rand() % 3) == 0) {
        m_DirX *= -1;
    }
    if (batCenterX >= 1920/2 && (rand() % 3) == 0) {
        m_DirX *= -1;
    }

    // Normalize
    // https://www.sololearn.com/en/Discuss/2397161/how-to-normalize-a-vector
    float len = std::sqrt(m_DirX * m_DirX + m_DirY * m_DirY);
    if (len != 0.0f) {
        m_DirX /= len;
        m_DirY /= len;
    }

    m_InFlight = true;
}

// Reset the ball
void Ball::reset(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
    m_InFlight = false;
    m_HitByBat = false;
    m_Speed = 0.0f;
    m_DirX = 0.0f; m_DirY = 0.0f;
}