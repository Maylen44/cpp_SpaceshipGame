#include "Game.h"
#include "PlayerShip.h"
#include "EnemyShipTypeA.h"
#include "EnemyShipTypeB.h"

static void clearObjects(std::vector<IGameObject*>& gameObjects)
{
	for (auto& object : gameObjects)
	{
		delete object;
	}
	gameObjects.clear();
}

Game::Game()
	: m_isPlaying(false)
	, m_gameObjects()
	, m_renderer()
	, m_eventHandler()
	, m_updater()
{
}

void Game::initialize()
{
	m_isPlaying = true;
	PlayerShip* player = new PlayerShip();
	EnemyShipTypeA* enemy1 = new EnemyShipTypeA();
	EnemyShipTypeB* enemy2 = new EnemyShipTypeB();
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	m_renderer.resetWindowContents(m_gameObjects);
}

void Game::run()
{
	initialize();

	while (m_isPlaying)
	{
		Status status = m_eventHandler.fetchStatus(m_renderer.pollWindowEvent());

		if (status == ClossingGame)
		{
			m_isPlaying = false;
			clearObjects(m_gameObjects);
			m_renderer.closeWindow();
		}
		else if (status == RestartingGame)
		{
			clearObjects(m_gameObjects);
			initialize();
		}
		else
		{
			m_updater.update(m_gameObjects, status, m_renderer.m_windowResolution);

		}
		m_renderer.renderWholeContent(m_gameObjects);
	}
}

void Game::reset()
{
}

/*void Game::spawn(IGameObject* gameObject, int numOfObjects)
{
	for (numOfObjects; numOfObjects > 0; --numOfObjects)
	{
		m_gameObjects.push_back(gameObject);
	}
}*/



