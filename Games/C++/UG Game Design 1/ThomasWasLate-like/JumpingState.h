#pragma once
#include "CharacterState.h"

class JumpingState : public CharacterState {
public:
    void Input(PlayableCharacter& character) override;
    void update(PlayableCharacter& character, float elapsedTime) override;
};