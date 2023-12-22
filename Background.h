#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "IGameObject.h"

class Background : public IGameObject
{
public:
	Background(const sf::Texture& texture, const sf::Vector2f& boundaries);
	virtual ~Background() = default;

	void update(const KeyboardEvent& keyPress, const MouseEvent& mousePress, const sf::Vector2f& boundaries) override;
	void handleEvent() override;
	void draw(sf::RenderWindow& window) override;
	void resetPositionWithin(const sf::Vector2f& boundaries) override;
	GameObjectType getObjectTyp() override { return BackgroundType; };

private:
	void resetBackground(sf::Sprite& sprite);
	void updateDuePlayerInputs(const KeyboardEvent& keyPress, const MouseEvent& mousePress);
	sf::Vector2f rotateVector(const sf::Vector2f& vector, float angle);

	std::vector <sf::Sprite> m_backgroundSprites;
	const sf::Vector2f m_size;
	const float m_scrollSpeed;
	sf::Vector2f m_passiveStriveDirection;
	const float m_passiveStriveSpeed;
	const float m_boostMultiplier;

	
	

};

#endif //BACKGROUND_H