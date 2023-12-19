#include <cmath>
#include "EnemyShipTypeB.h"

EnemyShipTypeB::EnemyShipTypeB()
	: m_color(sf::Color::Yellow)
	, m_healthPoints(3)
	, m_speed(0.7f)
	, m_reactionDelay(220.0f)
	, m_innerStopRadius(150.0f)
	, m_outerStopRadius(200.0f)
	, m_rotationSpeed(0.00005f)
{
	m_shape.setOrigin(10, 0);
	m_shape.setFillColor(m_color);
	m_shape.setPosition(100, 200);

}

void EnemyShipTypeB::update(const Status& eventStatus, const sf::Vector2f boundaries)
{
	updateDuePlayerInputs(eventStatus);
	sf::Vector2f directionToMiddle = sf::Vector2f(boundaries.x / 2, boundaries.y / 2) - m_shape.getPosition();
	float length = std::sqrt(directionToMiddle.x * directionToMiddle.x + directionToMiddle.y * directionToMiddle.y);
	updateRotation(boundaries, directionToMiddle, length);
	updateFollowBehavior(boundaries, directionToMiddle, length);

}

void EnemyShipTypeB::handleEvent(Status& eventStatus)
{
}

void EnemyShipTypeB::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void EnemyShipTypeB::resetPositionWithin(sf::Vector2f& boundaries)
{
}

void EnemyShipTypeB::updateDuePlayerInputs(const Status& eventStatus)
{
	switch (eventStatus)
	{
	case MovingPlayerUp:
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + (m_passiveStriveSpeed + m_speed));
		break;
	case MovingPlayerDown:
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y - (m_passiveStriveSpeed + m_speed));
		break;
	case MovingPlayerLeft:
		m_shape.setPosition(m_shape.getPosition().x + (m_passiveStriveSpeed + m_speed), m_shape.getPosition().y);
		break;
	case MovingPlayerRight:
		m_shape.setPosition(m_shape.getPosition().x - (m_passiveStriveSpeed + m_speed), m_shape.getPosition().y);
		break;
	default:
		break;
	}
}

void EnemyShipTypeB::updateRotation(const sf::Vector2f& boundaries, sf::Vector2f& directionToMiddle, const float length)
{
	if (length != 0)
	{
		directionToMiddle /= length;
	}
	float targetAngle = std::atan2(directionToMiddle.y, directionToMiddle.x) * 180.0f / static_cast<float>(3.14f);
	float currentRotation = m_shape.getRotation();
	float rotationDiff = targetAngle - currentRotation;
	if (rotationDiff > 180.0f)
	{
		rotationDiff -= 360.0f;
	}
	else if (rotationDiff < -180.0f)
	{
		rotationDiff += 360.0f;
	}
	m_shape.setRotation(currentRotation + m_rotationSpeed * rotationDiff);
}

void EnemyShipTypeB::updateFollowBehavior(const sf::Vector2f& boundaries, const sf::Vector2f& directionToMiddle, const float length)
{
	if (length < m_innerStopRadius)
	{
		m_shape.setPosition(m_shape.getPosition() - directionToMiddle / ((m_passiveStriveSpeed + m_speed) * m_reactionDelay));
	}
	else if (length < m_outerStopRadius)
	{
		float angle = std::atan2(directionToMiddle.y, directionToMiddle.x);
		if (m_shape.getPosition().x > boundaries.x / 2)
		{
			angle += m_speed;
		}
		else
		{
			angle -= m_speed;
		}
		sf::Vector2f circularMotion(std::cos(angle), std::sin(angle));
		m_shape.setPosition(m_shape.getPosition() + (directionToMiddle + circularMotion) / ((m_passiveStriveSpeed + m_speed) * m_reactionDelay));
	}
	else
	{
		m_shape.setPosition(m_shape.getPosition() + directionToMiddle / ((m_passiveStriveSpeed + m_speed) * m_reactionDelay));
	}
}