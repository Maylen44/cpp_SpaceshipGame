#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "IGameObject.h"

class Background : public IGameObject
{
public:
	Background(const sf::Texture& texture, const sf::Vector2f& boundaries);
	virtual ~Background() = default;

	void update(const Status& eventStatus, const sf::Vector2f& boundaries) override;
	void handleEvent(Status& eventStatus) override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(const sf::Vector2f& boundaries) override;
	GameObjectType getObjectTyp() override { return BackgroundType; };

private:
	void resetBackground(sf::Sprite& sprite);
	sf::Vector2f rotateVector(const sf::Vector2f& vector, float angle);
	void updateDuePlayerInputs(const Status& eventStatus);

	std::vector <sf::Sprite> m_backgroundSprites;
	const sf::Vector2f m_size;
	const float m_scrollSpeed;
	sf::Vector2f m_passiveStriveDirection;
	const float m_passiveStriveSpeed;

	
	

};

#endif //BACKGROUND_H