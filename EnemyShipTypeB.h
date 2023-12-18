#ifndef ENEMY_SHIP_TYPE_B_H
#define ENEMY_SHIP_TYPE_B_H

#include "Spaceship.h"

class EnemyShipTypeB : public Spaceship
{
public:
	EnemyShipTypeB();
	virtual ~EnemyShipTypeB() = default;

	void update(sf::Clock& deltaTime) override;
	void handleEvent(sf::Event& event) override;
	void draw(sf::RenderWindow& window) override;

private:
	const sf::Color m_color;
	int m_healthPoints;
	float m_speed;

};


#endif //ENEMY_SHIP_TYPE_B_H