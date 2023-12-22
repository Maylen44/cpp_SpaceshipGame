#include "Updater.h"
#include <SFML/Audio.hpp>

Updater::Updater()
	: m_deltaClock()
    //, m_SFXClock()
	, m_deltaTime(m_deltaClock.getElapsedTime())
    //, m_SFXTime(m_SFXClock.getElapsedTime())
    , m_frameTime(0.01f)
{}

void Updater::update(const std::vector<IGameObject*>&objects, const KeyboardEvent & keyPress, const MouseEvent & mousePress, const sf::Vector2f & boundaries)
{
    m_deltaTime = m_deltaClock.getElapsedTime();
    if (m_deltaTime > sf::seconds(m_frameTime))
    {
        for (auto& object : objects)
        {
            object->update(keyPress, mousePress, boundaries);
        }
        m_deltaClock.restart();
    }
}

/*
sf::Time& Updater::getSFXTime()
{
    return m_SFXTime = m_SFXClock.getElapsedTime();
}

void Updater::restartSFXclock()
{
    m_SFXClock.restart();
}
*/
