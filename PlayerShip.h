#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "Spaceship.h"

class PlayerShip : public Spaceship
{
public:
	PlayerShip(const sf::Texture& texture);
	virtual ~PlayerShip() = default;

	void update(const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries) override;
	void handleEvent() override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(const sf::Vector2f& boundaries) override;

	GameObjectType getObjectTyp() override { return PlayerType; };

private:
	void handleRotation(sf::RenderWindow& window);

	int m_healthPoints;
	const float m_speed;
	float m_rotationAngle;



};

#endif //PLAYER_SHIP_H