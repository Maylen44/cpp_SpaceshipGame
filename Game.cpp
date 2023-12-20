#include "Game.h"
#include "PlayerShip.h"
#include "EnemyShipTypeA.h"
#include "EnemyShipTypeB.h"

static void clearObject(std::vector<IGameObject*>& objectsList, int objectID = -1)
{
	if (objectID == -1)
	{
		for (auto& object : objectsList)
		{
			delete object;
		}
		objectsList.clear();
	}

	//need to work on it! doesnt work as wanted
	/*
	else if (objectID != -1)
	{
		if (objectID > -1)
		{
			objectsList.erase(objectsList.begin() + objectID);
			objectsList.shrink_to_fit();
		}
	}*/

}

Game::Game()
	: m_isPlaying(false)
	, m_gameObjects()
	, m_renderer()
	, m_eventHandler()
	, m_updater()
{}

void Game::initialize()
{
	m_isPlaying = true;
	spawnObject(Player);
	spawnObject(EnemyTypA, 3);
	spawnObject(EnemyTypB, 2);
	m_renderer.resetWindowContents(m_gameObjects);
}

void Game::run()
{
	initialize();

	while (m_isPlaying)
	{
		Status status = m_eventHandler.fetchStatus(m_renderer.pollWindowEvent());

		if (status == ClossingApplication)
		{
			m_isPlaying = false;
			clearObject(m_gameObjects);
			m_renderer.closeWindow();
		}
		else if (status == RestartingApplication)
		{
			reset();
		}
		else
		{
			m_updater.update(m_gameObjects, status, m_renderer.getResolution());
		}
		m_renderer.renderWholeContent(m_gameObjects);
	}
}

void Game::reset()
{
	clearObject(m_gameObjects);
	initialize();
}

void Game::spawnObject(const GameObjectType& type, int numOfObjects)
{
	for (int i = 0; i < numOfObjects > 0; ++i)
	{
		if (type == Ship){}
		else if (type == Player)
		{
			PlayerShip* player = new PlayerShip();
			m_gameObjects.push_back(player);
		}
		else if (type == EnemyTypA)
		{
			EnemyShipTypeA* enemy1 = new EnemyShipTypeA();
			m_gameObjects.push_back(enemy1);
		}
		else if (type == EnemyTypB)
		{
			EnemyShipTypeB* enemy2 = new EnemyShipTypeB();
			m_gameObjects.push_back(enemy2);
		}
		else if (type == NotSpecified){}
	}
}