#pragma once

class Map
{
public:
	Map();

	void render(sf::RenderTarget& target);
	
private:
	sf::Texture backgroundTexture;
	sf::Sprite mBackground;
};

