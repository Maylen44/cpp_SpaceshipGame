#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "IGameObject.h"

class Spaceship : public IGameObject
{
public:
	Spaceship();
	virtual ~Spaceship() = default;

protected:
	const sf::Vector2f m_size;
	sf::RectangleShape m_shape;
	const float m_passiveStriveSpeed;

};

#endif //SPACESHIP_H