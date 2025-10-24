#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter;

class CharacterState {
public:
    virtual ~CharacterState() = default;
    virtual void Input(PlayableCharacter& character) = 0;
    virtual void update(PlayableCharacter& character, float elapsedTime) = 0;
};