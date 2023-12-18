#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "Spaceship.h"

class PlayerShip : public Spaceship
{
public:
	PlayerShip();
	virtual ~PlayerShip() = default;

	void update(sf::Clock& deltaTime) override;
	void handleEvent(sf::Event& event) override;
	void draw(sf::RenderWindow& window) override;

private:
	const sf::Color m_color;
	int m_healthPoints;
	float m_speed;

};

#endif //PLAYER_SHIP_H