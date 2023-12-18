#ifndef ENEMY_SHIP_TYPE_A_H
#define ENEMY_SHIP_TYPE_A_H

#include "Spaceship.h"

class EnemyShipTypeA : public Spaceship
{
public:
	EnemyShipTypeA();
	virtual ~EnemyShipTypeA() = default;

	void update(sf::Clock& deltaTime) override;
	void handleEvent(Status& eventStatus) override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(sf::Vector2f& boundaries) override;

private:
	const sf::Color m_color;
	int m_healthPoints;
	float m_speed;

};

#endif //ENEMY_SHIP_TYPE_A_H