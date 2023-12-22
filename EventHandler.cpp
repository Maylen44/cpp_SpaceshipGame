#include "EventHandler.h"

ApplicationStatus EventHandler::fetchApplicationStatus(sf::Event& windowPollEvent)
{
    ApplicationStatus status = Processing;

    updateKeyboardState(windowPollEvent);
    updateMouseState(windowPollEvent);

    if (isClossingApplication(windowPollEvent))
    {
        status = ClossingApplication;
    }
    else if (isRestartingApplication())
    {
        status = RestartingApplication;
    }
    return status;
}

KeyboardEvent EventHandler::fetchKeyboardEvent()
{
    KeyboardEvent result = NoKeyboardInput;

    if (areKeysPressed(W, A))
        result = MoveUpLeft;
    else if (areKeysPressed(W, D))
        result = MoveUpRight;
    else if (areKeysPressed(S, A))
        result = MoveDownLeft;
    else if (areKeysPressed(S, D))
        result = MoveDownRight;
    else if (areKeysPressed(Up, Left))
        result = MoveUpLeft;
    else if (areKeysPressed(Up, Right))
        result = MoveUpRight;
    else if (areKeysPressed(Down, Left))
        result = MoveDownLeft;
    else if (areKeysPressed(Down, Right))
        result = MoveDownRight;

    else if (isKeyPressed(W))
        result = MoveUp;
    else if (isKeyPressed(Up))
        result = MoveUp;
    else if (isKeyPressed(S))
        result = MoveDown;
    else if (isKeyPressed(Down))
        result = MoveDown;
    else if (isKeyPressed(A))
        result = MoveLeft;
    else if (isKeyPressed(Left))
        result = MoveLeft;
    else if (isKeyPressed(D))
        result = MoveRight;
    else if (isKeyPressed(Right))
        result = MoveRight;

    return result;
}

MouseEvent EventHandler::fetchMouseEvent()
{
    MouseEvent result = NoMouseInput;

    if (areMousePressed(MouseLeft, MouseRight))
        result = RightAndLeftClick;
    else if (isKeyPressed(Space))
        result = RightClick;
    else if (isMousePressed(MouseLeft))
        result = LeftClick;
    else if (isMousePressed(MouseRight))
        result = RightClick;

    return result;
}

void EventHandler::updateKeyboardState(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
        keyboardState[static_cast<InputEvent>(event.key.code)] = true;
    else if (event.type == sf::Event::KeyReleased)
        keyboardState[static_cast<InputEvent>(event.key.code)] = false;
}

void EventHandler::updateMouseState(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        mouseState[static_cast<InputEvent>(event.mouseButton.button)] = true;
    else if (event.type == sf::Event::MouseButtonReleased)
        mouseState[static_cast<InputEvent>(event.mouseButton.button)] = false;
}

bool EventHandler::isMousePressed(const InputEvent button)
{
    return mouseState[button];
}

bool EventHandler::areMousePressed(const InputEvent button1, const InputEvent button2)
{
    return mouseState[button1] && mouseState[button2];
}

bool EventHandler::isKeyPressed(InputEvent key)
{
    return keyboardState[key];
}

bool EventHandler::areKeysPressed(InputEvent key1, InputEvent key2)
{
    return keyboardState[key1] && keyboardState[key2];
}

bool EventHandler::isClossingApplication(sf::Event& event)
{
    return (event.type == Closed) || isKeyPressed(ESC);
}

bool EventHandler::isRestartingApplication()
{
    return isKeyPressed(R);
}