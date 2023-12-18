#include "Renderer.h"

Renderer::Renderer()
	: m_windowResolution(800.f, 600.f)
	, m_windowMode(m_windowResolution.x, m_windowResolution.y)
	, m_windowTitel("SPACESHIP")
	, m_windowStyle(sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close)
	, m_window(m_windowMode, m_windowTitel, m_windowStyle)
{}

sf::Event& Renderer::pollWindowEvent()
{
	sf::Event pollRequest;
	m_window.pollEvent(pollRequest);
	return pollRequest;
}

void const Renderer::renderWholeContent(const std::vector<IGameObject*>& objects)
{
	m_window.clear();
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
