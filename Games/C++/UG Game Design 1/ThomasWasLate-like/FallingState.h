#pragma once
#include "CharacterState.h"

class FallingState : public CharacterState {
public:
    void Input(PlayableCharacter& character) override;
    void update(PlayableCharacter& character, float elapsedTime) override;
};