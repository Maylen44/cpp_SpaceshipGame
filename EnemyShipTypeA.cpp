#include <cmath>
#include <ctime>
#include <cstdlib>
#include "EnemyShipTypeA.h"

EnemyShipTypeA::EnemyShipTypeA(const sf::Texture& texture)
	: m_healthPoints(1)
	, m_speed(1.0f)
	, m_ingameSpeed(m_passiveStriveSpeed + m_speed)
	, m_rotationSpeed(0.01f)
	, m_reactionDelay(2.0f)
	, m_stopZoneRange(100.0f, 150.0f)
	, m_spawnOffset(40.0f)
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	m_sprite.setOrigin(m_size.x / 2, 0);
}

void EnemyShipTypeA::update(const Status& eventStatus, const sf::Vector2f& boundaries)
{
	updateDuePlayerInputs(eventStatus);
	sf::Vector2f directionToMiddle = sf::Vector2f(boundaries.x / 2, boundaries.y / 2) - m_sprite.getPosition();
	float length = std::sqrt(directionToMiddle.x * directionToMiddle.x + directionToMiddle.y * directionToMiddle.y);
	updateRotation(boundaries, directionToMiddle, length);
	updateFollowBehavior(boundaries, directionToMiddle, length);
}

void EnemyShipTypeA::handleEvent(Status& eventStatus)
{
}

void EnemyShipTypeA::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void EnemyShipTypeA::resetPositionWithin(const sf::Vector2f& boundaries)
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
	m_sprite.setPosition(spawnPosition.x, spawnPosition.y);
}

void EnemyShipTypeA::updateDuePlayerInputs(const Status& eventStatus)
{
	switch (eventStatus)
	{
	case MovingPlayerUp:
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerDown:
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - m_ingameSpeed);
		break;
	case MovingPlayerLeft:
		m_sprite.setPosition(m_sprite.getPosition().x + m_ingameSpeed, m_sprite.getPosition().y);
		break;
	case MovingPlayerRight:
		m_sprite.setPosition(m_sprite.getPosition().x - m_ingameSpeed, m_sprite.getPosition().y);
		break;
	case MovingPlayerUpLeftDiagonal:
		m_sprite.setPosition(m_sprite.getPosition().x + m_ingameSpeed, m_sprite.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerUpRightDiagonal:
		m_sprite.setPosition(m_sprite.getPosition().x - m_ingameSpeed, m_sprite.getPosition().y + m_ingameSpeed);
		break;
	case MovingPlayerDownLeftDiagonal:
		m_sprite.setPosition(m_sprite.getPosition().x + m_ingameSpeed, m_sprite.getPosition().y - m_ingameSpeed);
		break;
	case MovingPlayerDownRightDiagonal:
		m_sprite.setPosition(m_sprite.getPosition().x - m_ingameSpeed, m_sprite.getPosition().y - m_ingameSpeed);
		break;
	default:
		break;
	}
}

void EnemyShipTypeA::updateRotation(const sf::Vector2f& boundaries, sf::Vector2f& directionToMiddle, const float length)
{
	if (length != 0)
	{
		directionToMiddle /= length;
	}
	float targetAngle = std::atan2(directionToMiddle.y, directionToMiddle.x) * 180.0f / static_cast<float>(3.14f);
	float currentRotation = m_sprite.getRotation();
	float rotationDiff = targetAngle - currentRotation;
	if (rotationDiff > 180.0f)
	{
		rotationDiff -= 360.0f;
	}
	else if (rotationDiff < -180.0f)
	{
		rotationDiff += 360.0f;
	}
	m_sprite.setRotation(currentRotation + m_rotationSpeed * rotationDiff);
}

void EnemyShipTypeA::updateFollowBehavior(const sf::Vector2f& boundaries, const sf::Vector2f& directionToMiddle, const float length)
{
	//retreate back to safezone
	if (length < m_stopZoneRange.x)
	{
		m_sprite.setPosition(m_sprite.getPosition() - directionToMiddle / (m_ingameSpeed * m_reactionDelay));
	}
	//rotate clockwise or anti clockwise in safe zone
	else if (length < m_stopZoneRange.y)
	{
		float angle = std::atan2(directionToMiddle.y, directionToMiddle.x);
		if (m_sprite.getPosition().x > boundaries.x / 2)
		{
			angle += m_speed;
		}
		else
		{
			angle -= m_speed;
		}
		sf::Vector2f circularMotion(std::cos(angle), std::sin(angle));
		m_sprite.setPosition(m_sprite.getPosition() - circularMotion / (m_ingameSpeed * m_reactionDelay));
	}
	//move towards middle
	else
	{
		m_sprite.setPosition(m_sprite.getPosition() + directionToMiddle / (m_ingameSpeed * m_reactionDelay));
	}
}