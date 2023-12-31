#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "IGameObject.h"
#include "Renderer.h"
#include "EventHandler.h"
#include "Updater.h"
#include "AssetsManager.h"

class Game
{
public:
	Game();
	~Game() = default;

	void initialize();

	void run();
	void reset();

	void spawnObject(const GameObjectType& type, int numOfObjects = 1);

private:


	bool m_isPlaying;
	std::vector<IGameObject*> m_gameObjects;
	Renderer m_renderer;
	EventHandler m_eventHandler;
	Updater m_updater;
	AssetsManager m_assetsManager;
};

#endif //GAME_H