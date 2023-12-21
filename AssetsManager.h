#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "IGameObject.h"

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager() = default;
	void const runManager();
	const void playSong(); //NEED to change argument!
	const sf::Texture& getTexture(const GameObjectType& type);

private:
	void const loadTextures();


	std::map<GameObjectType, sf::Texture> m_textures;
	//std::map<GameObjectType, sf::Music> m_songs;
	//sf::Music m_song1;

};

#endif //ASSETS_MANAGER_H