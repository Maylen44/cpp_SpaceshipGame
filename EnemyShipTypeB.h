#ifndef ENEMY_SHIP_TYPE_B_H
#define ENEMY_SHIP_TYPE_B_H

#include "Spaceship.h"

class EnemyShipTypeB : public Spaceship
{
public:
	EnemyShipTypeB();
	virtual ~EnemyShipTypeB() = default;

	void update(const Status& eventStatus, const sf::Vector2f& boundaries) override;
	void handleEvent(Status& eventStatus) override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(const sf::Vector2f& boundaries) override;

private:
	void updateDuePlayerInputs(const Status& eventStatus);
	void updateRotation(const sf::Vector2f& boundaries, sf::Vector2f& directionToMiddle, const float length);
	void updateFollowBehavior(const sf::Vector2f& boundaries, const sf::Vector2f& directionToMiddle, const float length);
	
	GameObjectType getObjectTyp() override;

	const sf::Color m_color;
	int m_healthPoints;
	const float m_speed;
	const float m_ingameSpeed;
	float m_rotationSpeed;
	const float m_reactionDelay;
	const sf::Vector2f m_stopZoneRange;
	const float m_spawnOffset;

};


#endif //ENEMY_SHIP_TYPE_B_H