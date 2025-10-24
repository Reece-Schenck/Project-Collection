#include "Engine.h"
#include "SoundManager.h"


Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Thomas was late",
		Style::Fullscreen);

	// Initialize the full screen view
	m_MainView.setSize(resolution);
	m_HudView.reset(
		FloatRect(0, 0, resolution.x, resolution.y));

	// Inititialize the split-screen Views
	m_LeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_RightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BGLeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_BGRightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	soundManager = new SoundManager();
	soundManager->addObserver(this); // Register the Engine as an observer

	// Can this graphics card use shaders?
	if (!sf::Shader::isAvailable())
	{
		// Time to get a new PC
		m_Window.close();
	}
	else
	{
		// Load two shaders (1 vertex, 1 fragment)
		m_RippleShader.loadFromFile("shaders/vertShader.vert", "shaders/rippleShader.frag");

		m_WaveShader.loadFromFile("shaders/waveShader.vert", "shaders/waveShader.frag");
	}

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);


	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");

	// Initialize the particle system
	m_PS.init(1000);

	m_SM.addObserver(this);

}// End Engine constructor

void Engine::notifyFire(const sf::Vector2f& emitterLocation, const sf::Vector2f& listenerLocation) {
	// Handle fire notification, play sound or do other actions
	m_SM.playFire(emitterLocation, listenerLocation);
}

void Engine::notifyFallInFire() {
	// Handle fall in fire notification, play sound or do other actions
	m_SM.playFallInFire();
}

void Engine::notifyFallInWater() {
	// Handle fall in water notification, play sound or do other actions
	m_SM.playFallInWater();
}

void Engine::notifyJump() {
	// Handle jump notification, play sound or do other actions
	m_SM.playJump();
}

void Engine::notifyReachGoal() {
	// Handle reach goal notification, play sound or do other actions
	m_SM.playReachGoal();
}

void Engine::run()
{
	// Timing 	
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}