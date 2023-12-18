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

void EnemyShipTypeA::handleEvent(sf::Event& event)
{
}

void EnemyShipTypeA::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}
