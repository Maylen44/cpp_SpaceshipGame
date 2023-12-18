#include "EnemyShipTypeA.h"

EnemyShipTypeA::EnemyShipTypeA()
	: m_color(sf::Color::Red)
	, m_healthPoints(1)
	, m_speed(1.f)
{
	m_shape.setFillColor(m_color);
	m_shape.setPosition(500, 500);

}

void EnemyShipTypeA::update(sf::Clock& deltaTime)
{
}

void EnemyShipTypeA::handleEvent(Status& eventStatus)
{
}

void EnemyShipTypeA::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void EnemyShipTypeA::resetPositionWithin(sf::Vector2f& boundaries)
{
}
