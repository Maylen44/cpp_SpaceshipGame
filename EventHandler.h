#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>

enum ApplicationStatus
{
	Processing,
	ClossingApplication,
	RestartingApplication
};

enum KeyboardEvent
{
	NoKeyboardInput,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	MoveUpLeft,
	MoveUpRight,
	MoveDownLeft,
	MoveDownRight
};

enum MouseEvent
{
	NoMouseInput,
	RightClick,
	LeftClick,
	RightAndLeftClick

};

enum InputEvent
{
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
	MouseLeft = sf::Mouse::Left,
	MouseRight = sf::Mouse::Right,

	ESC = sf::Keyboard::Escape,
	R = sf::Keyboard::R
};

class EventHandler
{
public:
	EventHandler() = default;
	~EventHandler() = default;
	ApplicationStatus fetchApplicationStatus(sf::Event& windowPollEvent);
	KeyboardEvent fetchKeyboardEvent();
	MouseEvent fetchMouseEvent();

private:
	void updateKeyboardState(sf::Event& event);
	void updateMouseState(sf::Event& event);

	bool isMousePressed(const InputEvent button);
	bool areMousePressed(const InputEvent button1, const InputEvent button2);
	bool isKeyPressed(InputEvent key);
	bool areKeysPressed(InputEvent key1, InputEvent key2);
	bool isClossingApplication(sf::Event& event);
	bool isRestartingApplication();

	std::unordered_map<InputEvent, bool> keyboardState;
	std::unordered_map<InputEvent, bool> mouseState;

};

#endif //EVENT_HANDLER_H