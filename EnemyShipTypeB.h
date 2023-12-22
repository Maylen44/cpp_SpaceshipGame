#ifndef ENEMY_SHIP_TYPE_B_H
#define ENEMY_SHIP_TYPE_B_H

#include "Spaceship.h"

class EnemyShipTypeB : public Spaceship
{
public:
	EnemyShipTypeB(const sf::Texture& texture);
	virtual ~EnemyShipTypeB() = default;

	void update(const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries) override;
	void handleEvent() override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(const sf::Vector2f& boundaries) override;

private:
	void updateDuePlayerInputs(const KeyboardEvent& keyPress, const MouseEvent& mousePress);
	void updateRotation(const sf::Vector2f& boundaries, sf::Vector2f& directionToMiddle, const float length);
	void updateFollowBehavior(const sf::Vector2f& boundaries, const sf::Vector2f& directionToMiddle, const float length);
	
	GameObjectType getObjectTyp() override { return EnemyTypBType; };

	int m_healthPoints;
	const float m_baseSpeed;
	const float m_speed;
	const float m_boostMultiplier;
	float m_rotationSpeed;
	const float m_reactionDelay;
	const sf::Vector2f m_stopZoneRange;
	const float m_spawnOffset;

};


#endif //ENEMY_SHIP_TYPE_B_H