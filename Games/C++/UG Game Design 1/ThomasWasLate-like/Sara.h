#pragma once
#include "PlayableCharacter.h"

class Sara : public PlayableCharacter
{
public:
	// A constructor specific to Bob
	Sara();

	// The overriden input handler for Bob
	bool virtual handleInput();

};