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
	, m_deltaTime()
	, m_gameObjects()
	, m_renderer()
	, m_eventHandler()
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
}

void Game::run()
{
	initialize();

	while (m_isPlaying)
	{
		Status status = m_eventHandler.fetchEventStatus(m_renderer.pollWindowEvent());

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
			if (status == MovingPlayerUp || status == MovingPlayerDown ||
				status == MovingPlayerLeft || status == MovingPlayerRight ||
				status == FiringPlayersMissile)
			{

			}
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

void Game::update()
{
}



