#include "Pitcher.hpp"

Pitcher::Pitcher(float startX, float startY) : m_Position(startX, startY) {
    m_Texture.loadFromFile("graphics/pitcher.png");
    m_Sprite.setTexture(m_Texture);

    m_Sprite.setScale(80.0f / m_Sprite.getLocalBounds().width, 100.0f / m_Sprite.getLocalBounds().height);

    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
}

FloatRect Pitcher::getPosition() const {
    return m_Sprite.getGlobalBounds();
}

Sprite& Pitcher::getShape() { 
    return m_Sprite; 
}

// movement
void Pitcher::moveLeft()
{
    m_MovingLeft = true;
}
void Pitcher::moveRight()
{
    m_MovingRight = true;
}
void Pitcher::moveUp()
{
    m_MovingUp = true;
}
void Pitcher::moveDown()
{
    m_MovingDown = true;
}
void Pitcher::stopLeft()
{
    m_MovingLeft = false;
}
void Pitcher::stopRight()
{
    m_MovingRight = false;
}
void Pitcher::stopUp()
{
    m_MovingUp = false;
}
void Pitcher::stopDown()
{
    m_MovingDown = false;
}

void Pitcher::update(Time dt, bool freeMovement) {
    float seconds = dt.asSeconds();
    // after pitch - almost full free movment
    if (freeMovement) {
        // so pitcher can't chase the pitch down and instantly catch the ball when hit
        float limitBottom = 500.0f;

        if (m_MovingLeft) {
            m_Position.x -= m_Speed * seconds;
        }
        if (m_MovingRight) {
            m_Position.x += m_Speed * seconds;
        }
        if (m_MovingUp) {
            m_Position.y -= m_Speed * seconds;
        }
        if (m_MovingDown) {
            m_Position.y = std::min(limitBottom, m_Position.y + m_Speed * seconds);
        }
    }
    else {
        // before pitch - restrict to the mound
        float moundTop = 50.0f;
        float moundBottom = 350.0f;
        float moundLeft = 760.0f;
        float moundRight = 1160.0f;

        // Only update vertical if flag is set and keep within mound area
        if (m_MovingUp) m_Position.y = std::max(moundTop, m_Position.y - m_Speed * seconds);
        if (m_MovingDown) m_Position.y = std::min(moundBottom, m_Position.y + m_Speed * seconds);

        // Horizontal movement also limited to mound region
        if (m_MovingLeft) m_Position.x = std::max(moundLeft, m_Position.x - m_Speed * seconds);
        if (m_MovingRight) m_Position.x = std::min(moundRight, m_Position.x + m_Speed * seconds);
    }

    // screen bounds
    const float screenW = (float)VideoMode::getDesktopMode().width;
    const float screenH = (float)VideoMode::getDesktopMode().height;
    float halfW = m_Sprite.getGlobalBounds().width * 0.5f;
    float halfH = m_Sprite.getGlobalBounds().height * 0.5f;

    m_Position.x = std::max(halfW, std::min(m_Position.x, screenW - halfW));
    m_Position.y = std::max(halfH, std::min(m_Position.y, screenH - halfH));

    m_Sprite.setPosition(m_Position);
}

float Pitcher::getCenterX() const {
    return m_Position.x;
}

void Pitcher::setPosition(float x, float y) {
    m_Position.x = x;
    m_Position.y = y;
    m_Sprite.setPosition(m_Position);
}