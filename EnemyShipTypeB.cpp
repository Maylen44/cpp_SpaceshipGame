#include "EnemyShipTypeB.h"

EnemyShipTypeB::EnemyShipTypeB()
	: m_color(sf::Color::Yellow)
	, m_healthPoints(3)
	, m_speed(2.f)
{
	m_shape.setFillColor(m_color);
	m_shape.setPosition(100, 200);

}

void EnemyShipTypeB::update(sf::Clock& deltaTime)
{
}

void EnemyShipTypeB::handleEvent(sf::Event& event)
{
}

void EnemyShipTypeB::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}
