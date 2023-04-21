#pragma once

#include "Animation.h"

/*Напрямки пташки в Інтро стані*/
enum class IntroStateDirections
{
	UP, DOWN
};

class Bird
{
public:
	/*Конструктор*/
	Bird();

	/*Ініціалізація початкових даних*/
	void init();

	/*Геттери
	  1) Повертає рамки пташки
	  2) Повертає позицію пташки*/
	const sf::FloatRect getGlobalBounds();
	const sf::Vector2f& getBirdPosition();

	/*Функція падіння*/
	void birdFalling();

	/*Функції направляння пташки
	  Переміщення в Інтро стані
	  Переміщення в Ігровому стані*/
	void manageDirections();
	void introStateMove();
	void move();

	/*Функції анімації крил
	  та анімації зіштовхнення*/
	void animateWings();
	void animateCollision();

	/*Функції оновлення та відмальовування*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*Об'єкт класу Animation*/
	Animation birdAnimation;

	/*Статична швидкість пташки в Інтро стані*/
	const float staticMovingSpeed;

	/*Бул змінна яка каже чи почалась гра*/
	bool gameON;
	
	/*Об'єкт напрямків пташки в Інтро стані*/
	IntroStateDirections introDir;
};

