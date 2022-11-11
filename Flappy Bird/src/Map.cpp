#include "pch.h"
#include "Map.h"

Map::Map()
{
	backgroundTexture.loadFromFile("Textures/background.png");
	baseTexture.loadFromFile("Textures/base.png");
	mBackground.setTexture(backgroundTexture);
	mBase.setTexture(baseTexture);

	mBackground.setScale(2.1f, 1.7f);
	mBase.setScale(2.f, 1.f);

	mBase.setPosition(sf::Vector2f(0.f, 700.f));
}

//const sf::Vector2f& Map::getMapBounds()
//{
//	
//}

void Map::update()
{
	
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(mBackground);
	target.draw(mBase);
}