#ifndef UPDATER_H
#define UPDATER_H

#include <SFML/Graphics.hpp>
#include "IGameObject.h"

enum Status;

class Updater
{
public:
	Updater();
	~Updater() = default;

	void update(const std::vector<IGameObject*>& objects, const Status& eventStatus, const sf::Vector2f& boundaries);


private:
	sf::Clock m_deltaClock;
	sf::Time m_deltaTime;
	float m_frameTime;

};

#endif //UPDATER_H