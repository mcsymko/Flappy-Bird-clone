#pragma once

class Base
{
public:
	/*Конструктор*/
	Base();

	/*Константна змінна, яка передає рамки платформи 
      (для перевірки чи не зіштовхнулася пташка з цією платформою)*/
	const sf::FloatRect getGlobalBounds();

	/*Функція переміщення платформи*/
	void move();

	/*Оновлення та відмальовування*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*Текстура платформи та сама платформа*/
	sf::Texture baseTexture;
	sf::Sprite mBase;

	/*Її константна швидкість*/
	const float movingSpeed;
};

