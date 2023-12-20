#include <cmath>
#include "PlayerShip.h"
#include <iostream>

static float getAngle(float x1, float y1, float x2, float y2)
{
	sf::Vector2f up(0, 1);
	sf::Vector2f p0(x1, y1);
	sf::Vector2f p1(x2, y2);
	sf::Vector2f q = p1 - p0;
	float q_length = sqrtf(q.x * q.x + q.y * q.y);
	q.x /= q_length;
	q.y /= q_length;
	float scalar_product = q.y;
	float angle = acos(scalar_product) * 180.0f / 3.1415f;
	if (x2 - x1 < 0.0f){}
	else
	{
		angle *= -1;
	}
	return angle;
}


PlayerShip::PlayerShip()
	: m_color(sf::Color::Green)
	, m_healthPoints(10)
	, m_speed(3.f)
	, m_rotationAngle(m_shape.getRotation())
{
	m_shape.setOrigin(m_size.x / 2, m_size.x / 2);
	m_shape.setFillColor(m_color);
}

void PlayerShip::update(const Status& eventStatus, const sf::Vector2f& boundaries)
{
	m_shape.setRotation(m_rotationAngle);
	std::cout << "f" << std::endl;
}

void PlayerShip::handleEvent(Status& eventStatus)
{
}

void PlayerShip::draw(sf::RenderWindow& window)
{
	handleRotation(window);
	window.draw(m_shape);
}

void PlayerShip::resetPositionWithin(const sf::Vector2f& boundaries)
{
	m_shape.setPosition(boundaries.x / 2, boundaries.y / 2);
}

GameObjectType PlayerShip::getObjectTyp()
{
	return Player;
}

void PlayerShip::handleRotation(sf::RenderWindow& window)
{
	sf::Vector2i m_pos_new = sf::Mouse::getPosition(window);
	m_rotationAngle = getAngle(m_shape.getPosition().x, m_shape.getPosition().y, m_pos_new.x, m_pos_new.y);
}
