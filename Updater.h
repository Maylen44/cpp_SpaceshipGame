#ifndef UPDATER_H
#define UPDATER_H

#include <SFML/Graphics.hpp>
#include "IGameObject.h"

enum KeyboardEvent;
enum MouseEvent;

class Updater
{
public:
	Updater();
	~Updater() = default;

	void update(const std::vector<IGameObject*>& objects, const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries);

	sf::Time& getSFXTime();
	void restartSFXclock();

private:
	sf::Clock m_deltaClock;
	//sf::Clock m_SFXClock;
	sf::Time m_deltaTime;
	//sf::Time m_SFXTime;
	float m_frameTime;

};

#endif //UPDATER_H