#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"

enum GameObjectType
{
	BackgroundType,
	ShipType,
	PlayerType,
	EnemyTypAType,
	EnemyTypBType,
	NotSpecifiedType
};

class IGameObject
{
public:
	IGameObject() = default;
	virtual ~IGameObject() = default;

	virtual void update(const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries) {};
	virtual void handleEvent() {};
	virtual void draw(sf::RenderWindow& window) {};
	virtual void resetPositionWithin(const sf::Vector2f& boundaries) {};
	virtual GameObjectType getObjectTyp() { return NotSpecifiedType; };
};

#endif //I_GAME_OBJECT_H