#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	// Update the shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

	// Update the shader parameters
	m_WaveShader.setUniform("amplitude", 5.0f);
	m_WaveShader.setUniform("frequency", 2.0f);
	m_WaveShader.setUniform("time", m_GameTimeTotal.asSeconds());

	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);

		// Draw the background, complete with shader effectasdawdsa
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);


		// commented out because the shaders didn't work

		// Draw fire hazard tiles with the new shader effect
		//if (m_ArrayLevel[currentY][currentX] == 2) // Fire hazard tile
		//{
		//	m_Window.draw(m_BackgroundSprite, &m_WaveShader);
		//}

		// Draw water hazard tiles with the new shader effect
		//else if (m_ArrayLevel[currentY][currentX] == 3) // Water hazard tile
		//{
		//	m_Window.draw(m_BackgroundSprite, &m_WaveShader);
		//}

		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw the Level
		/*
		for (int x = 0; x < m_LM.getLevelSize().x; ++x)
		{
			for (int y = 0; y < m_LM.getLevelSize().y; ++y)
			{
				// Draw fire hazard tiles with the new shader effect
				if (m_ArrayLevel[currentY][currentX] == 2 || m_ArrayLevel[currentY][currentX] == 3) // Fire hazard tile
				{
					// Create a sprite for the hazard tile
					hazardTile.setTexture(m_TextureTiles);
					hazardTile.setTextureRect(sf::IntRect(0, 100, 50, 50)); // left, top, height, width
					hazardTile.setPosition(x * TILE_SIZE, y * TILE_SIZE);

					// Draw the hazard tile with the wave shader effect
					m_Window.draw(hazardTile, &m_WaveShader);
				}
			}
		}
		*/
		m_Window.draw(m_VALevel, &m_TextureTiles);


		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		if (switchP2 == 1) {
			// Draw bob
			m_Window.draw(m_Bob.getSprite());
		}
		else {
			// Draw Sara
			m_Window.draw(m_Sara.getSprite());
		}

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}
	}
	else
	{
		// Split-screen view is active

		// First draw Thomas' side of the screen

		// Switch to background view
		m_Window.setView(m_BGLeftView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);

		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_LeftView
		m_Window.setView(m_LeftView);

		// Draw the Level
		for (int x = 0; x < m_LM.getLevelSize().x; ++x)
		{
			for (int y = 0; y < m_LM.getLevelSize().y; ++y)
			{
				// Draw fire hazard tiles with the new shader effect
				if (m_ArrayLevel[currentY][currentX] == 2 || m_ArrayLevel[currentY][currentX] == 3) // Fire hazard tile
				{
					// Create a sprite for the hazard tile
					hazardTile.setTexture(m_TextureTiles);
					hazardTile.setTextureRect(sf::IntRect(0, 100, 50, 50)); // left, top, height, width
					hazardTile.setPosition(x * TILE_SIZE, y * TILE_SIZE);

					// Draw the hazard tile with the wave shader effect
					m_Window.draw(hazardTile, &m_WaveShader);
				}
			}
		}
		m_Window.draw(m_VALevel, &m_TextureTiles);


		if (switchP2 == 1) {
			// Draw bob
			m_Window.draw(m_Bob.getSprite());
		}
		else {
			// Draw Sara
			m_Window.draw(m_Sara.getSprite());
		}

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

		// Now draw Bob's side of the screen

		// Switch to background view
		m_Window.setView(m_BGRightView);
		// Draw the background
		//m_Window.draw(m_BackgroundSprite);

		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_RightView
		m_Window.setView(m_RightView);

		// Draw the Level
		for (int x = 0; x < m_LM.getLevelSize().x; ++x)
		{
			for (int y = 0; y < m_LM.getLevelSize().y; ++y)
			{
				// Draw fire hazard tiles with the new shader effect
				if (m_ArrayLevel[currentY][currentX] == 2 || m_ArrayLevel[currentY][currentX] == 3) // Fire hazard tile
				{
					// Create a sprite for the hazard tile
					hazardTile.setTexture(m_TextureTiles);
					hazardTile.setTextureRect(sf::IntRect(0, 100, 50, 50)); // left, top, height, width
					hazardTile.setPosition(x * TILE_SIZE, y * TILE_SIZE);

					// Draw the hazard tile with the wave shader effect
					m_Window.draw(hazardTile, &m_WaveShader);
				}
			}
		}
		m_Window.draw(m_VALevel, &m_TextureTiles);


		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		if (switchP2 == 1) {
			// Draw bob
			m_Window.draw(m_Bob.getSprite());
		}
		else {
			// Draw Sara
			m_Window.draw(m_Sara.getSprite());
		}

		// Draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

	}

	// Draw the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}


	// Show everything we have just drawn
	m_Window.display();
}