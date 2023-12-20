#include "EventHandler.h"

static bool areKeysPressed(Event key1, Event key2)
{
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key1)) &&
        sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key2));
}

static bool isKeyPressed(Event key)
{
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

static bool isMousePressed(Event key)
{
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key));
}

static bool isClossingApplication(sf::Event& event) //left event here for windowpoll event in case if game is in window mode. otherwise just delete event from here
{
    return (event.type == Closed) || isKeyPressed(ESC);
}

static bool isRestartingApplication()
{
    return isKeyPressed(R);
}

static bool isUserInputingCommands(Status& status)
{
    bool result = true;

    //diagonal movement keys
    if (areKeysPressed(W, A))
        status = MovingPlayerUpLeftDiagonal;
    else if (areKeysPressed(W, D))
        status = MovingPlayerUpRightDiagonal;
    else if (areKeysPressed(S, A))
        status = MovingPlayerDownLeftDiagonal;
    else if (areKeysPressed(S, D))
        status = MovingPlayerDownRightDiagonal;
    else if (areKeysPressed(Up, Left))
        status = MovingPlayerUpLeftDiagonal;
    else if (areKeysPressed(Up, Right))
        status = MovingPlayerUpRightDiagonal;
    else if (areKeysPressed(Down, Left))
        status = MovingPlayerDownLeftDiagonal;
    else if (areKeysPressed(Down, Right))
        status = MovingPlayerDownRightDiagonal;
    //4 ways movement keys
    else if (isKeyPressed(W))
        status = MovingPlayerUp;
    else if (isKeyPressed(Up))
        status = MovingPlayerUp;
    else if (isKeyPressed(S))
        status = MovingPlayerDown;
    else if (isKeyPressed(Down))
        status = MovingPlayerDown;
    else if (isKeyPressed(A))
        status = MovingPlayerLeft;
    else if (isKeyPressed(Left))
        status = MovingPlayerLeft;
    else if (isKeyPressed(D))
        status = MovingPlayerRight;
    else if (isKeyPressed(Right))
        status = MovingPlayerRight;
    //action keys
    else if (isKeyPressed(Space))
        status = FiringPlayersMissile;
    else if (isMousePressed(MouseLeft))
        status = FiringPlayersMissile;
    else if (isMousePressed(MouseRight))
        status = BoostingPlayersSpeed;

    else result = false;

    return result;
}

Status EventHandler::fetchStatus(sf::Event& windowPollEvent)
{
    Status status = Processing;
    if (isClossingApplication(windowPollEvent))
    {
        status = ClossingApplication;
    }
    else if (isRestartingApplication())
    {
        status = RestartingApplication;
    }
    else if(isUserInputingCommands(status)){}
    return status;
}