#include "Bat.hpp"

Bat::Bat(float startX, float startY) : m_Position(startX, startY)
{
    m_Texture.loadFromFile("graphics/wood.png");
    m_SwingTexture.loadFromFile("graphics/woodHit.png");

    m_Sprite.setTexture(m_Texture);
    m_SwingSprite.setTexture(m_SwingTexture);

    m_Sprite.setScale(175.0f / m_Sprite.getLocalBounds().width, 25.0f / m_Sprite.getLocalBounds().height);
    m_SwingSprite.setScale(175.0f / m_SwingSprite.getLocalBounds().width, 25.0f / m_SwingSprite.getLocalBounds().height);

    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
    m_SwingSprite.setPosition(m_Position);
}

FloatRect Bat::getPosition()
{
    if (m_Swinging) {
        return m_SwingSprite.getGlobalBounds();
    }
    else {
        return m_Sprite.getGlobalBounds();
    }
}

//swaps sprites if batter is swinging or not
Sprite& Bat::getShape() {
    if (m_Swinging) {
        return m_SwingSprite;
    }
    else {
        return m_Sprite;
    }
}
void Bat::moveLeft()
{
    m_MovingLeft = true;
}
void Bat::moveRight()
{
    m_MovingRight = true;
}
void Bat::stopLeft()
{
    m_MovingLeft = false;
}
void Bat::stopRight(){
    m_MovingRight = false;
}

void Bat::update(Time dt)
{
    if (m_MovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }
    if (m_MovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();
    }

    // keep bat from going off the screen
    if (m_Position.x < 0) {
        m_Position.x = 0;
    }
    if (m_Position.x + m_Sprite.getGlobalBounds().width > 1920) {
        m_Position.x = 1920 - m_Sprite.getGlobalBounds().width;
    }
    if (m_Position.x + m_SwingSprite.getGlobalBounds().width > 1920) {
        m_Position.x = 1920 - m_SwingSprite.getGlobalBounds().width;
    }

    // Handle swing timing
    if (m_Swinging) {
        m_SwingTimer += dt;
        // modulate swing power by timing hits
        if (m_SwingTimer >= m_SwingDuration) {
            m_Swinging = false;
            m_SwingTimer = Time::Zero;
            m_SwingPower = 0.5f;
        }
    }

    // Update sprite positions
    m_Sprite.setPosition(m_Position);
    m_SwingSprite.setPosition(m_Position);

}

// Start a swing, Returns false if already swinging
bool Bat::startSwing() {
    if (m_Swinging) { 
        return false; 
    }
    m_Swinging = true;
    m_SwingTimer = Time::Zero;
    m_SwingPower = 1.0f; // full power
    return true;
}

bool Bat::isSwinging() const { 
    return m_Swinging; 
}

float Bat::getSwingPower() const { 
    return m_SwingPower; 
}

void Bat::setPosition(float x, float y) {
    m_Position.x = x;
    m_Position.y = y;
    m_Sprite.setPosition(m_Position);
    m_SwingSprite.setPosition(m_Position);
}

void Bat::resetSwing()
{
    m_Swinging = false;
    m_SwingTimer = Time::Zero;
    m_SwingPower = 0.5f;
    m_Sprite.setPosition(m_Position);
    m_SwingSprite.setPosition(m_Position);
}