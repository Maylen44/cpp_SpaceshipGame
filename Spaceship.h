#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "IGameObject.h"

enum MovementDirection
{
	Default = sf::Vector2f { 0, 0 },
	Up = sf::Vector2f,
	Down,
	Left,
	Right
};

class Spaceship : public IGameObject
{
public:
	Spaceship();
	virtual ~Spaceship() = default;

protected:
	const sf::Vector2f m_size;
	sf::RectangleShape m_shape;

};

#endif //SPACESHIP_H