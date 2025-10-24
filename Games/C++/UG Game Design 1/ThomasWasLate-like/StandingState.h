#pragma once
#include "CharacterState.h"

class StandingState : public CharacterState {
public:
    void Input(PlayableCharacter& character) override;
    void update(PlayableCharacter& character, float elapsedTime) override;
};