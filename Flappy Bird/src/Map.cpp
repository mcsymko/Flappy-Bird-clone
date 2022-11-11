#include "pch.h"
#include "Map.h"

Map::Map()
	: movingSpeed(1.f)
{
	backgroundTexture.loadFromFile("Textures/background.png");
	baseTexture.loadFromFile("Textures/base.png");
	mBackground.setTexture(backgroundTexture);
	mBase.setTexture(baseTexture);

	mBackground.setScale(2.1f, 1.7f);
	mBase.setScale(2.f, 1.f);

	mBase.setPosition(sf::Vector2f(0.f, 700.f));
}

void Map::move()
{
	if (mBase.getPosition().x + mBase.getGlobalBounds().width < 600)
	
		mBase.setPosition(sf::Vector2f(-26.f, 700.f));

	mBase.setPosition(sf::Vector2f(mBase.getPosition().x - movingSpeed, 700.f));
}

void Map::update()
{
	move();
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(mBackground);
	target.draw(mBase);
}
