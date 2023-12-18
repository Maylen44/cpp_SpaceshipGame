#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "IGameObject.h"
#include "Renderer.h"
#include "EventHandler.h"


class Game
{
public:
	Game();
	~Game() = default;

	void initialize();

	void run();
	void reset();

	//void spawn(IGameObject* gameObject, int numOfObjects = 1);
	

private:
	void update();

	bool m_isPlaying;
	sf::Clock m_deltaTime;
	std::vector<IGameObject*> m_gameObjects;
	Renderer m_renderer;
	EventHandler m_eventHandler;
};

#endif //GAME_H