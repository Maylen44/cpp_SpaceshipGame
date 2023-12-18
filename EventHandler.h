#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "IGameObject.h"

enum Event
{
	Keyrelease = sf::Event::KeyReleased,
	Closed = sf::Event::Closed,

	Up = sf::Keyboard::Up,
	W = sf::Keyboard::W,
	Down = sf::Keyboard::Down,
	S = sf::Keyboard::S,
	Left = sf::Keyboard::Left,
	A = sf::Keyboard::A,
	Right = sf::Keyboard::Right,
	D = sf::Keyboard::D,
	Space = sf::Keyboard::Space,

	ESC = sf::Keyboard::Escape,
	R = sf::Keyboard::R
};

enum Status
{
	Processing,
	ClossingGame,
	RestartingGame,
	MovingPlayerUp,
	MovingPlayerDown,
	MovingPlayerLeft,
	MovingPlayerRight,
	FiringPlayersMissile
};

class EventHandler
{
public:
	EventHandler() = default;
	~EventHandler() = default;
	Status fetchEventStatus(sf::Event& windowPollEvent);
};

#endif //EVENT_HANDLER_H
