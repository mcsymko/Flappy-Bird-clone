#pragma once

class Map
{
public:
	Map();
	
	void move();

	//const sf::Vector2f& getBasePosition();
	//void setBasePosition(sf::Vector2f position);

	void update();
	void render(sf::RenderTarget& target);
	
private:
	sf::Texture backgroundTexture;
	sf::Texture baseTexture;
	sf::Sprite mBackground;
	sf::Sprite mBase;

	const float movingSpeed;
};

