#pragma once

#include "GameObject.hpp"

enum class GameEvent { COLLISION_EVENT };

/// <summary>
/// Abstract base class for objects that observe game objects.
/// </summary>
class GameObserver 
{
public:
	// Pure-virtual functions do not provide an implementation.
	// Subclasses MUST override this method with an actual implementation.
	virtual void onNotify(GameObject const& obj, GameEvent evt) = 0;
};