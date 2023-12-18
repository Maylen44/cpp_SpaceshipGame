#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "IGameObject.h"

class Spaceship : public IGameObject
{
public:
	Spaceship();
	virtual ~Spaceship() = default;

	void draw(sf::RenderWindow& window) override;


protected:
	const sf::Vector2f m_size;
	sf::RectangleShape m_shape;

};

#endif //SPACESHIP_H