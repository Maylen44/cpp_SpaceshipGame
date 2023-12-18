#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "IGameObject.h"

class Renderer
{
public:
	Renderer();
	~Renderer() = default;
	sf::Event& pollWindowEvent();
	void const renderWholeContent(const std::vector<IGameObject*>& objects);
	void resetWindowContents(const std::vector<IGameObject*>& objects);
	void closeWindow();

private:
	sf::Vector2f m_windowResolution;
	sf::VideoMode m_windowMode;
	const std::string m_windowTitel;
	const sf::Uint64 m_windowStyle;
	sf::RenderWindow m_window;

};

#endif //RENDERER_H