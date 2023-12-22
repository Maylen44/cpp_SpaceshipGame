#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IGameObject.h"

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager() = default;
	void const playSFX(int soundID);//change argument to status or something!

	const sf::Texture& getTexture(const GameObjectType& type);

private:
	std::map<GameObjectType, sf::Texture> m_textures;
	sf::SoundBuffer laserSFXBuffer, laserHitSFXBuffer;
	sf::Sound laserSFX, laserHitSFX;

};

#endif //ASSETS_MANAGER_H