#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "Sara.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"
#include "SoundObserver.h"

using namespace sf;

class Engine : public SoundObserver {
private:
	// 1 = bob, 2 = sara
	int switchP2 = 1;

	SoundManager* soundManager; // Add a pointer to SoundManager

	// The texture holder
	TextureHolder th;

	// create a particle system
	ParticleSystem m_PS;

	// Thomas and his friend, Bob
	Thomas m_Thomas;
	Bob m_Bob;
	Sara m_Sara;

	// A class to manage all the levels
	LevelManager m_LM;

	// Create a SoundManager
	SoundManager m_SM;

	// The Hud
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	// Declare a shader for the background
	Shader m_RippleShader;

	Shader m_WaveShader;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;

	// Start in full screen mode
	bool m_SplitScreen = false;

	// How much time is left in the current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// The vertex array for the level design
	VertexArray m_VALevel;

	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	Sprite hazardTile;
	int currentX = 0;
	int currentY = 0;

	// Texture for the background and the level tiles
	Texture m_TextureTiles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new level
	void loadLevel();

	// Run will call all the private functions
	bool detectCollisions(PlayableCharacter& character);

	// Make a vector of the best places to emit sounds from
	void populateEmitters(vector <Vector2f>& vSoundEmitters,
		int** arrayLevel);

	// A vector of Vector2f for the fire emiiter locations
	vector <Vector2f> m_FireEmitters;

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

	// Implement the SoundObserver interface
	void notifyFire(const sf::Vector2f& emitterLocation, const sf::Vector2f& listenerLocation) override;
	void notifyFallInFire() override;
	void notifyFallInWater() override;
	void notifyJump() override;
	void notifyReachGoal() override;
};