#include <cmath>
#include "EnemyShipTypeB.h"

EnemyShipTypeB::EnemyShipTypeB()
	: m_color(sf::Color::Yellow)
	, m_healthPoints(3)
	, m_speed(0.7f)
	, m_ingameSpeed(m_passiveStriveSpeed + m_speed)
	, m_rotationSpeed(0.015f)
	, m_reactionDelay(2.0f)
	, m_stopZoneRange(150.0f, 200.0f)
	, m_spawnOffset(40.0f)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	m_shape.setOrigin(m_size.x / 2, 0);
	m_shape.setFillColor(m_color);
}

void EnemyShipTypeB::update(const Status& eventStatus, const sf::Vector2f& boundaries)
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

void EnemyShipTypeB::resetPositionWithin(const sf::Vector2f& boundaries)
{
	sf::Vector2f spawnPosition = { 0.0f, 0.0f };

	if (rand() % 2 == 0)
	{
		spawnPosition.x = (rand() % 2 == 0) ? -m_spawnOffset : boundaries.x + m_spawnOffset;
		spawnPosition.y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (boundaries.y - m_spawnOffset * 2) + m_spawnOffset;
	}
	else
	{
		spawnPosition.x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (boundaries.x - m_spawnOffset * 2) + m_spawnOffset;
		spawnPosition.y = (rand() % 2 == 0) ? -m_spawnOffset : boundaries.y + m_spawnOffset;
	}
	m_shape.setPosition(spawnPosition.x, spawnPosition.y);
}

void EnemyShipTypeB::updateDuePlayerInputs(const Status& eventStatus)
{
	switch (eventStatus)
	{
	case MovingPlayerUp:
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerDown:
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y - m_ingameSpeed);
		break;
	case MovingPlayerLeft:
		m_shape.setPosition(m_shape.getPosition().x + m_ingameSpeed, m_shape.getPosition().y);
		break;
	case MovingPlayerRight:
		m_shape.setPosition(m_shape.getPosition().x - m_ingameSpeed, m_shape.getPosition().y);
		break;
	case MovingPlayerUpLeftDiagonal:
		m_shape.setPosition(m_shape.getPosition().x + m_ingameSpeed, m_shape.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerUpRightDiagonal:
		m_shape.setPosition(m_shape.getPosition().x - m_ingameSpeed, m_shape.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerDownLeftDiagonal:
		m_shape.setPosition(m_shape.getPosition().x + m_ingameSpeed, m_shape.getPosition().y - m_ingameSpeed);
		break;
	case MovingPlayerDownRightDiagonal:
		m_shape.setPosition(m_shape.getPosition().x - m_ingameSpeed, m_shape.getPosition().y - m_ingameSpeed);
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
	//retreate back to safezone
	if (length < m_stopZoneRange.x)
	{
		m_shape.setPosition(m_shape.getPosition() - directionToMiddle / (m_ingameSpeed * m_reactionDelay));
	}
	//rotate clockwise or anti clockwise in safe zone
	else if (length < m_stopZoneRange.y)
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
		m_shape.setPosition(m_shape.getPosition() + circularMotion / (m_ingameSpeed * m_reactionDelay));
	}
	//move towards middle
	else
	{
		m_shape.setPosition(m_shape.getPosition() + directionToMiddle / (m_ingameSpeed * m_reactionDelay));
	}
}

GameObjectType EnemyShipTypeB::getObjectTyp()
{
	return EnemyTypB;
}
