#include "Background.h"

Background::Background(const sf::Texture& texture, const sf::Vector2f& boundaries)
	: m_backgroundSprites(4)
	, m_size(boundaries.x, boundaries.y)
	, m_scrollSpeed(0.3f)
	, m_passiveStriveDirection(0.1f, 0.1f)
	, m_passiveStriveSpeed(0.2f)
	, m_boostMultiplier(2.0f)
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

void Background::update(const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries)
{
	updateDuePlayerInputs(keyPress, mousePress);
}

void Background::handleEvent()
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

void Background::updateDuePlayerInputs(const KeyboardEvent& keyPress, const MouseEvent& mousePress)
{
	float ingameSpeed = m_scrollSpeed;
	if (mousePress == RightClick || mousePress == RightAndLeftClick)
	{
		ingameSpeed *= m_boostMultiplier;
	}

	for (auto& sprite : m_backgroundSprites)
	{
		switch (keyPress)
		{
		case MoveUp:
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + ingameSpeed);
			m_passiveStriveDirection = { 0.0f, m_passiveStriveSpeed };
			break;
		case MoveDown:
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - ingameSpeed);
			m_passiveStriveDirection = { 0.0f, -m_passiveStriveSpeed };
			break;
		case MoveLeft:
			sprite.setPosition(sprite.getPosition().x + ingameSpeed, sprite.getPosition().y);
			m_passiveStriveDirection = { m_passiveStriveSpeed, 0.0f };
			break;
		case MoveRight:
			sprite.setPosition(sprite.getPosition().x - ingameSpeed, sprite.getPosition().y);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, 0.0f };
			break;
		case MoveUpLeft:
			sprite.setPosition(sprite.getPosition().x + ingameSpeed, sprite.getPosition().y + ingameSpeed);
			m_passiveStriveDirection = { m_passiveStriveSpeed, m_passiveStriveSpeed };
			break;
		case MoveUpRight:
			sprite.setPosition(sprite.getPosition().x - ingameSpeed, sprite.getPosition().y + ingameSpeed);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, m_passiveStriveSpeed };
			break;
		case MoveDownLeft:
			sprite.setPosition(sprite.getPosition().x + ingameSpeed, sprite.getPosition().y - ingameSpeed);
			m_passiveStriveDirection = { m_passiveStriveSpeed, -m_passiveStriveSpeed };
			break;
		case MoveDownRight:
			sprite.setPosition(sprite.getPosition().x - ingameSpeed, sprite.getPosition().y - ingameSpeed);
			m_passiveStriveDirection = { -m_passiveStriveSpeed, -m_passiveStriveSpeed };
			break;
		default:
			sprite.move(m_passiveStriveDirection);
			break;
		}
		resetBackground(sprite);
	}
}
