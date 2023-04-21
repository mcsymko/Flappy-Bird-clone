#pragma once

class Map
{
public:
	/*Конструктор*/
	Map();

	/*Функція відмальовування карти*/
	void render(sf::RenderTarget& target);
	
private:
	/*Текстура карти та сама карта (спрайт)*/
	sf::Texture backgroundTexture;
	sf::Sprite mBackground;
};

