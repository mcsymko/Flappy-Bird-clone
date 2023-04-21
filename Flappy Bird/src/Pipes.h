#pragma once

class Pipes
{
public:
	/*Конструктор*/
	Pipes();

	/*Ініціалізатор*/
	void init();

	/*Функції, які повертають рамки обох видів труб для перевірки зіштовхнення*/
	const sf::FloatRect getGlobalBoundsPipeUp();
	const sf::FloatRect getGlobalBoundsPipeDown();

	/*Функції, які повертають значення по іксу (x)
	  для перевірки зараховування очка гравцю*/
	const float& getPipe1PositionX();
	const float& getPipe2PositionX();

	/*Функції встановлення випадкової позиції труб
	  Перевірка чи пора респавнити
	  та Функція переміщення труб*/
	void calculateRandomPosition();
	void checkRespawn();
	void move();

	/*Функції оновлення та відмальовування*/
	void update();
	void render(sf::RenderTarget& target);
	
private:
	/*Текстури труб верхніх та нижніх та
	  3 спрайти для кожної з них*/
	sf::Texture texturePipeUp, texturePipeDown;
	sf::Sprite pipeUp[2], pipeDown[2];

	/*Константні змінні (змінні, які не можна поміняти) швидкість руху,
	  Горизонтальна відстань між трубами
	  Вертикальна відстань між трубами*/
	const float movingSpeed;
	const float horizontalDistanceBetweenPipes;
	const float verticalDistanceBetweenPipes;

	/*Інтеджер випадкової позиції труб*/
	int randomPosition;
};

