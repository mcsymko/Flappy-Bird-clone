#include "pch.h"
#include "Map.h"

Map::Map()
{
	/*Завантажується текстура з папки "Textures"
	  Встановлюється ця текстура до спрайту
	  та виставляється розмір*/
	backgroundTexture.loadFromFile("Textures/background.png");
	mBackground.setTexture(backgroundTexture);
	mBackground.setScale(2.1f, 1.7f);
}

/*Звичайне відмальовування, яка передаватиметься в основний клас, де малюватиме вікно*/
void Map::render(sf::RenderTarget& target)
{
	target.draw(mBackground);
}
