#include "pch.h"
#include "Map.h"

Map::Map()
{
	backgroundTexture.loadFromFile("Textures/background.png");
	mBackground.setTexture(backgroundTexture);
	mBackground.setScale(2.1f, 1.7f);
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(mBackground);
}
