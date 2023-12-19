#include "Renderer.h"

Renderer::Renderer()
	: m_windowResolution(800.f, 600.f)
	, m_windowMode(m_windowResolution.x, m_windowResolution.y)
	, m_windowTitel("SPACESHIP")
	, m_windowStyle(sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
	, m_window(m_windowMode, m_windowTitel, m_windowStyle)
	, m_backgroundTexture()
	, m_backgroundSprites(5)
{
	m_backgroundTexture.loadFromFile("bkgd_1.png", sf::IntRect(0, 0, m_windowResolution.x, m_windowResolution.y));
	
	for (int i = 0; i < 4; ++i)
	{
		m_backgroundSprites[i].setTexture(m_backgroundTexture);
		m_backgroundSprites[i].setOrigin(0.f, 0.f);
		if (i == 1)
		{
			m_backgroundSprites[i].setPosition(m_windowResolution.x, 0.f);
		}
		else if (i == 2)
		{
			m_backgroundSprites[i].setPosition(0.f, -m_windowResolution.y);
		}
		else if (i == 3)
		{
			m_backgroundSprites[i].setPosition(m_windowResolution.x, -m_windowResolution.y);
		}
	}
}

sf::Event& Renderer::pollWindowEvent()
{
	sf::Event pollRequest;
	m_window.pollEvent(pollRequest);
	return pollRequest;
}

void const Renderer::renderWholeContent(const std::vector<IGameObject*>& objects)
{
	m_window.clear();

	
	for (auto& sprite : m_backgroundSprites)
	{
		m_window.draw(sprite);

		//sprite.move(0.0f, -0.1f);
		sprite.move(-0.1f, 0.0f);
		//sprite.move(-0.1f, -0.1f);
		//sprite.move(0.0f, 0.0f);
		resetBackground(sprite);
		m_window.draw(sprite);
	}

	for (auto& object : objects)
	{
		object->draw(m_window);
	}

	m_window.display();
}

void Renderer::resetWindowContents(const std::vector<IGameObject*>& objects)
{
	for (auto& object : objects)
	{
		object->resetPositionWithin(m_windowResolution);
	}
}

void Renderer::closeWindow()
{
	m_window.close();
}

void Renderer::resetBackground(sf::Sprite& sprite)
{
	float spriteWidth = m_backgroundTexture.getSize().x;
	float spriteHeight = m_backgroundTexture.getSize().y;

	float spriteX = sprite.getPosition().x;
	float spriteY = sprite.getPosition().y;

	if (spriteX + spriteWidth < 0)
	{
		sprite.setPosition(spriteX + m_windowResolution.x * 2, spriteY);
	}
	else if (spriteX > m_windowResolution.x)
	{
		sprite.setPosition(spriteX - m_windowResolution.x * 2, spriteY);
	}

	if (spriteY + spriteHeight < 0)
	{
		sprite.setPosition(spriteX, spriteY + m_windowResolution.y * 2);
	}
	else if (spriteY > m_windowResolution.y)
	{
		sprite.setPosition(spriteX, spriteY - m_windowResolution.y * 2);
	}
}
