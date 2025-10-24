#pragma once
#include <SFML/System/Vector2.hpp>

class SoundObserver {
public:
    virtual ~SoundObserver() = default;
    virtual void notifyFire(const sf::Vector2f& emitterLocation, const sf::Vector2f& listenerLocation) = 0;
    virtual void notifyFallInFire() = 0;
    virtual void notifyFallInWater() = 0;
    virtual void notifyJump() = 0;
    virtual void notifyReachGoal() = 0;
};