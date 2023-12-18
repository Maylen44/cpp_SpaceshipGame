#include "PlayerShip.h"

PlayerShip::PlayerShip()
	: m_color(sf::Color::Green)
	, m_healthPoints(10)
	, m_speed(3.f)
{
	m_shape.setFillColor(m_color);
	m_shape.setPosition(200, 400);
}

void PlayerShip::update(sf::Clock& deltaTime)
{
}

void PlayerShip::handleEvent(sf::Event& event)
{
}

void PlayerShip::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}


//m_shape.setPosition(boundaries.x / 2.f, boundaries.y / 2.f);
//make reset position after initializing