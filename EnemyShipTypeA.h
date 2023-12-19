#ifndef ENEMY_SHIP_TYPE_A_H
#define ENEMY_SHIP_TYPE_A_H

#include "Spaceship.h"

class EnemyShipTypeA : public Spaceship
{
public:
	EnemyShipTypeA();
	virtual ~EnemyShipTypeA() = default;

	void update(const Status& eventStatus, const sf::Vector2f boundaries) override;
	void handleEvent(Status& eventStatus) override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(sf::Vector2f& boundaries) override;

private:
	void updateDuePlayerInputs(const Status& eventStatus);
	void updateRotation(const sf::Vector2f& boundaries, sf::Vector2f& directionToMiddle, const float length);
	void updateFollowBehavior(const sf::Vector2f& boundaries, const sf::Vector2f& directionToMiddle, const float length);

	const sf::Color m_color;
	int m_healthPoints;
	float m_speed;
	const float m_reactionDelay;
	const float m_innerStopRadius;
	const float m_outerStopRadius;
	float m_rotationSpeed;


};

#endif //ENEMY_SHIP_TYPE_A_H