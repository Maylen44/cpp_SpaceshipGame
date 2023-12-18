#include "EventHandler.h"

static bool isClossingGame(sf::Event& event)
{
    return (event.type == Closed) || ((event.type == Keyrelease) && (event.key.code == ESC));
}

static bool isRestartingGame(sf::Event& event)
{
    return (event.type == Keyrelease) && (event.key.code == R);
}

static bool isPlayerInputingCommands(sf::Event& event, Status& status)
{
    bool result = false;
    if (event.type == Keyrelease)
    {
        switch (event.key.code)
        {
        case Space:
            status = FiringPlayersMissile;
            result = true;
            break;
        case Up:
            status = MovingPlayerUp;
            result = true;
            break;
        case W:
            status = MovingPlayerUp;
            result = true;
            break;
        case Down:
            status = MovingPlayerDown;
            result = true;
            break;
        case S:
            status = MovingPlayerDown;
            result = true;
            break;
        case Left:
            status = MovingPlayerLeft;
            result = true;
            break;
        case A:
            status = MovingPlayerLeft;
            result = true;
            break;
        case Right:
            status = MovingPlayerRight;
            result = true;
            break;
        case D:
            status = MovingPlayerRight;
            result = true;
            break;
        default:
            break;
        }
    }
    return result;
}

Status EventHandler::fetchEventStatus(sf::Event& windowPollEvent)
{
    Status tmp = Processing;
    if (isClossingGame(windowPollEvent))
    {
        tmp = ClossingGame;
    }
    else if (isRestartingGame(windowPollEvent))
    {
        tmp = RestartingGame;
    }
    else if(isPlayerInputingCommands(windowPollEvent, tmp)){}
    return tmp;
}
