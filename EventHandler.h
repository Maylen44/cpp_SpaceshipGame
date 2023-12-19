#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Graphics.hpp>

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

enum Event
{
	Keyrelease = sf::Event::KeyReleased,
	Keyrpressed = sf::Event::KeyPressed,
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
	/*UpAndLeft = sf::Keyboard::Up && sf::Keyboard::Left 
	|| sf::Keyboard::W && sf::Keyboard::A
	|| sf::Keyboard::W && sf::Keyboard::Left
	|| sf::Keyboard::Up && sf::Keyboard::A,
*/
		
	ESC = sf::Keyboard::Escape,
	R = sf::Keyboard::R
};

class EventHandler
{
public:
	EventHandler() = default;
	~EventHandler() = default;
	Status fetchStatus(sf::Event& windowPollEvent);
};

#endif //EVENT_HANDLER_H
