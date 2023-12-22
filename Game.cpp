#include "Game.h"
#include "Background.h"
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
	, m_assetsManager()
{}

void Game::initialize()
{
	m_isPlaying = true;
	spawnObject(BackgroundType);
	spawnObject(PlayerType);
	spawnObject(EnemyTypAType, 3);
	spawnObject(EnemyTypBType, 2);
	m_renderer.resetWindowContents(m_gameObjects);
	
}

void Game::run()
{
	initialize();

	while (m_isPlaying)
	{
		ApplicationStatus status = m_eventHandler.fetchApplicationStatus(m_renderer.pollWindowEvent());
		KeyboardEvent keyboardEvent = m_eventHandler.fetchKeyboardEvent();
		MouseEvent mouseEvent = m_eventHandler.fetchMouseEvent();

		if (status == ClossingApplication)
		{
			m_isPlaying = false;
			clearObject(m_gameObjects);
			m_renderer.closeWindow();
		}
		else if (status == RestartingApplication)
		{
			/*
			if (m_updater.getSFXTime() > sf::seconds(1.0f))
			{
				m_assetsManager.playSFX(0);
				m_updater.restartSFXclock();
			}
			*/
			reset();
		}
		m_updater.update(m_gameObjects, keyboardEvent, mouseEvent, m_renderer.getResolution());
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
	for (int i = 0; i < numOfObjects; ++i)
	{
		if (type == ShipType){}
		else if (type == BackgroundType)
		{
			Background* background = new Background(m_assetsManager.getTexture(type), m_renderer.getResolution());
			m_gameObjects.push_back(background);
		}
		else if (type == PlayerType)
		{
			PlayerShip* player = new PlayerShip(m_assetsManager.getTexture(type));
			m_gameObjects.push_back(player);
		}
		else if (type == EnemyTypAType)
		{
			EnemyShipTypeA* enemy1 = new EnemyShipTypeA(m_assetsManager.getTexture(type));
			m_gameObjects.push_back(enemy1);
		}
		else if (type == EnemyTypBType)
		{
			EnemyShipTypeB* enemy2 = new EnemyShipTypeB(m_assetsManager.getTexture(type));
			m_gameObjects.push_back(enemy2);
		}
		else if (type == NotSpecifiedType){}
	}
}