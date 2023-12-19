#include "PlayerShip.h"

PlayerShip::PlayerShip()
	: m_color(sf::Color::Green)
	, m_healthPoints(10)
	, m_speed(3.f)
{
	m_shape.setOrigin(10, 0);
	m_shape.setFillColor(m_color);
}

void PlayerShip::update(const Status& eventStatus, const sf::Vector2f boundaries)
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
