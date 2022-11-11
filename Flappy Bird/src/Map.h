#pragma once

class Map
{
public:
	Map();
	
	void move();

	void update();
	void render(sf::RenderTarget& target);
	
private:
	sf::Texture backgroundTexture;
	sf::Texture baseTexture;
	sf::Sprite mBackground;
	sf::Sprite mBase;

	const float movingSpeed;
};

