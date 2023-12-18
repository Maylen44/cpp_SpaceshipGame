#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"

class IGameObject
{
public:
	IGameObject() = default;
	virtual ~IGameObject() = default;

	virtual void update(sf::Clock& deltaTime) {};
	virtual void handleEvent(Status& eventStatus) {};
	virtual void draw(sf::RenderWindow& window) {};
	virtual void resetPositionWithin(sf::Vector2f& boundaries) {};


};

#endif //I_GAME_OBJECT_H