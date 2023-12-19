#include "Updater.h"

Updater::Updater()
	: m_deltaClock()
	, m_deltaTime(m_deltaClock.getElapsedTime())
    , m_frameTime(0.0001f)
{}

void Updater::update(const std::vector<IGameObject*>& objects, const Status& eventStatus, const sf::Vector2f boundaries)
{
    m_deltaTime = m_deltaClock.getElapsedTime();
    if (m_deltaTime > sf::seconds(m_frameTime))
    {
        for (auto& object : objects)
        {
            object->update(eventStatus, boundaries);
        }
        m_deltaClock.restart();
    }

}