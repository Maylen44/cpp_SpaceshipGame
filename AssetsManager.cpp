#include "AssetsManager.h"

AssetsManager::AssetsManager()
	: m_textures()
	//, m_songs()
	//, m_song1()
{}

void const AssetsManager::runManager()
{
	loadTextures();
}

const void AssetsManager::playSong()
{
	
}

const sf::Texture& AssetsManager::getTexture(const GameObjectType& type)
{
	return m_textures[type];
}

void const AssetsManager::loadTextures()
{
	sf::Texture error, background, playerShip, enemyAShip, enemyBShip;

	error.loadFromFile("failsafe.png");
	background.loadFromFile("bkgd_1.png");
	playerShip.loadFromFile("imageedit_3_4247255388.png");
	enemyAShip.loadFromFile("imageedit_6_8538846178.png");
	enemyBShip.loadFromFile("imageedit_11_7958019659.png");

	m_textures[NotSpecifiedType] = error;
	m_textures[BackgroundType] = background;
	m_textures[PlayerType] = playerShip;
	m_textures[EnemyTypAType] = enemyAShip;
	m_textures[EnemyTypBType] = enemyBShip;
}