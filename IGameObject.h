#ifndef I_GAME_OBJECT_H
#define I_GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class IGameObject
{
public:
	IGameObject() = default;
	virtual ~IGameObject() = default;

	virtual void update(sf::Clock& deltaTime) {};
	virtual void handleEvent(sf::Event& event) {};
	virtual void draw(sf::RenderWindow& window) {};

};

#endif //I_GAME_OBJECT_H