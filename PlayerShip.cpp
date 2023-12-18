#include "PlayerShip.h"

PlayerShip::PlayerShip()
	: m_color(sf::Color::Green)
	, m_healthPoints(10)
	, m_speed(3.f)
	, m_movementDirection()
{
	m_shape.setFillColor(m_color);
}

void PlayerShip::update(sf::Clock& deltaTime)
{
}

void PlayerShip::handleEvent(Status& eventStatus)
{
}

void PlayerShip::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void PlayerShip::resetPositionWithin(sf::Vector2f& boundaries)
{
	m_shape.setPosition(boundaries.x / 2, boundaries.y / 2);
}


//m_shape.setPosition(boundaries.x / 2.f, boundaries.y / 2.f);
//make reset position after initializing