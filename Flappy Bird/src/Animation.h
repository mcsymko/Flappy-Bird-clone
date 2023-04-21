#pragma once

class Animation
{
public:
	/*Конструктор*/
	Animation();
	
	/*Ініціалізація (початкові дані елементів, в нашому випадку пташки)*/
	void init();

	/*Повертаючі функція, які повертають позицію пташки для перевіряння чи набрав гравець очко
	та повертання границь пташки для перевірння чи не зіштовхнулась пташка з перешкодами*/
	const sf::Vector2f& getBirdPosition();
	const sf::FloatRect getGlobalBounds();

	/*Анімація пташки в Інтро стані
	  Функція переміщення
	  та Функція падіння пташки*/
	void introBirdAnimation(float x, float y);
	void birdMove();
	void birdFalling();

	/*Анімації крил
	  та зіштовхнення*/
	void animateWings();
	void animateCollision();
	
	/*Функції оновлення
	та відмальовування*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*Три текстури з різною позицією крил для анімації польоту
	  Сам спрайт з пташкою
	  та Розмір текстури, необхідний для анімації польоту*/
	sf::Texture birdTextures[3];
	sf::Sprite bird;
	int numberOfTexture;

	/*Таймери, необхідні для плавного відображення анімацій*/
	sf::Clock timerOne, timerTwo;

	/*Змінна, яка зберігає наскільки пташка повернути головою*/
	float downwardsRotation;

	/*Швидкість переміщення пташки*/
	float birdFallingSpeed;
};