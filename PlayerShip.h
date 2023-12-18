#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "Spaceship.h"

class PlayerShip : public Spaceship
{
public:
	PlayerShip();
	virtual ~PlayerShip() = default;

	void update(sf::Clock& deltaTime) override;
	void handleEvent(Status& eventStatus) override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(sf::Vector2f& boundaries) override;


private:
	const sf::Color m_color;
	int m_healthPoints;
	float m_speed;
	sf::Vector2f m_movementDirection;


};

#endif //PLAYER_SHIP_H