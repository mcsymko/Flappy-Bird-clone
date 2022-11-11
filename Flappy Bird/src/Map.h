#pragma once

class Map
{
public:
	Map();

	const sf::Vector2f& getMapBounds();

	void update();
	void render(sf::RenderTarget& target);
	
private:
	sf::Texture backgroundTexture;
	sf::Texture baseTexture;
	sf::Sprite mBackground;
	sf::Sprite mBase;
};

