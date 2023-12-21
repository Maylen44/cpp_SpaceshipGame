#include "Background.h"

Background::Background(const sf::Texture& texture, const sf::Vector2f& boundaries)
	: m_backgroundSprites(4)
	, m_size(boundaries.x, boundaries.y)
	, m_scrollSpeed(0.3f)
	, m_passiveStriveDirection(0.1f, 0.1f)
	, m_passiveStriveSpeed(0.2f)
{
	for (int i = 0; i < 4; ++i)
	{
		m_backgroundSprites[i].setTexture(texture);
		m_backgroundSprites[i].setOrigin(0.f, 0.f);
		if (i == 1)
		{
			m_backgroundSprites[i].setPosition(m_size.x, 0.f);
		}
		else if (i == 2)
		{
			m_backgroundSprites[i].setPosition(0.f, -m_size.y);
		}
		else if (i == 3)
		{
			m_backgroundSprites[i].setPosition(m_size.x, -m_size.y);
		}
	}
}

void Background::update(const Status& eventStatus, const sf::Vector2f& boundaries)
{
	updateDuePlayerInputs(eventStatus);
}

void Background::handleEvent(Status& eventStatus)
{
}

void Background::draw(sf::RenderWindow& window)
{
	for (auto& sprite : m_backgroundSprites)
	{
		window.draw(sprite);
	}
}

void Background::resetPositionWithin(const sf::Vector2f& boundaries)
{
}


void Background::resetBackground(sf::Sprite& sprite)
{
	float spriteWidth = m_size.x;
	float spriteHeight = m_size.y;

	float spriteX = sprite.getPosition().x;
	float spriteY = sprite.getPosition().y;

	if (spriteX + spriteWidth < 0)
	{
		sprite.setPosition(spriteX + m_size.x * 2, spriteY);
	}
	else if (spriteX > m_size.x)
	{
		sprite.setPosition(spriteX - m_size.x * 2, spriteY);
	}

	if (spriteY + spriteHeight < 0)
	{
		sprite.setPosition(spriteX, spriteY + m_size.y * 2);
	}
	else if (spriteY > m_size.y)
	{
		sprite.setPosition(spriteX, spriteY - m_size.y * 2);
	}
}

sf::Vector2f Background::rotateVector(const sf::Vector2f& vector, float angle)
{
	float x = vector.x * std::cos(angle) - vector.y * std::sin(angle);
	float y = vector.x * std::sin(angle) + vector.y * std::cos(angle);
	return sf::Vector2f(x, y);
}

void Background::updateDuePlayerInputs(const Status& eventStatus)
{
	for (auto& sprite : m_backgroundSprites)
	{
		switch (eventStatus)
		{
		case MovingPlayerUp:
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + m_scrollSpeed);
			m_passiveStriveDirection = { 0.0f, m_passiveStriveSpeed };
			break;
		case MovingPlayerDown:
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - m_scrollSpeed);
			m_passiveStriveDirection = { 0.0f, -m_passiveStriveSpeed };
			break;
		case MovingPlayerLeft:
			sprite.setPosition(sprite.getPosition().x + m_scrollSpeed, sprite.getPosition().y);
			m_passiveStriveDirection = { m_passiveStriveSpeed, 0.0f };
			break;
		case MovingPlayerRight:
			sprite.setPosition(sprite.getPosition().x - m_scrollSpeed, sprite.getPosition().y);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, 0.0f };
			break;
		case MovingPlayerUpLeftDiagonal:
			sprite.setPosition(sprite.getPosition().x + m_scrollSpeed, sprite.getPosition().y + m_scrollSpeed);
			m_passiveStriveDirection = { m_passiveStriveSpeed, m_passiveStriveSpeed };
			break;
		case MovingPlayerUpRightDiagonal:
			sprite.setPosition(sprite.getPosition().x - m_scrollSpeed, sprite.getPosition().y + m_scrollSpeed);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, m_passiveStriveSpeed };
			break;
		case MovingPlayerDownLeftDiagonal:
			sprite.setPosition(sprite.getPosition().x + m_scrollSpeed, sprite.getPosition().y - m_scrollSpeed);
			m_passiveStriveDirection = { m_passiveStriveSpeed, -m_passiveStriveSpeed };
			break;
		case MovingPlayerDownRightDiagonal:
			sprite.setPosition(sprite.getPosition().x - m_scrollSpeed, sprite.getPosition().y - m_scrollSpeed);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, -m_passiveStriveSpeed };
			break;
		default:
			sprite.move(m_passiveStriveDirection);
			break;
		}
		resetBackground(sprite);
	}
}
