#include "AssetsManager.h"

AssetsManager::AssetsManager()
	: m_textures()
{
	//Texture initialization
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


	//SFX initialization
	laserSFXBuffer.loadFromFile("laser10.wav");
	laserHitSFXBuffer.loadFromFile("tir.mp3");

	laserSFX.setBuffer(laserSFXBuffer);
	laserHitSFX.setBuffer(laserHitSFXBuffer);

}

void const AssetsManager::playSFX(int soundID)
{
	laserSFX.play();
}

const sf::Texture& AssetsManager::getTexture(const GameObjectType& type)
{
	return m_textures[type];
}