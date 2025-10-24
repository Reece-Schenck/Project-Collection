#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include "SoundObserver.h"

using namespace sf;

class SoundManager
{
private:
	// The buffers
	SoundBuffer m_FireBuffer;
	SoundBuffer m_FallInFireBuffer;
	SoundBuffer m_FallInWaterBuffer;
	SoundBuffer m_JumpBuffer;
	SoundBuffer m_ReachGoalBuffer;

	// The Sounds
	Sound m_Fire1Sound;
	Sound m_Fire2Sound;
	Sound m_Fire3Sound;
	Sound m_FallInFireSound;
	Sound m_FallInWaterSound;
	Sound m_JumpSound;
	Sound m_ReachGoalSound;

	// Which sound should we use next, fire 1, 2 or 3
	int m_NextSound = 1;

	// For the observer pattern
	std::vector<SoundObserver*> observers;

public:

	void addObserver(SoundObserver* observer);
	void removeObserver(SoundObserver* observer);

	SoundManager();

	void playFire(Vector2f emitterLocation, Vector2f listenerLocation);
	void playFallInFire();
	void playFallInWater();
	void playJump();
	void playReachGoal();

	void notifyFire(Vector2f emitterLocation, Vector2f listenerLocation);
	void notifyFallInFire();
	void notifyFallInWater();
	void notifyJump();
	void notifyReachGoal();
};