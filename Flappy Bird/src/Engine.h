#pragma once

//Підключаємо необхідні бібліотеки та клас
#include "pch.h"
#include "PlayingState.h"

class Engine
{
public:
	// Конструктор
	Engine();

	//Обробляння івентів, функції оновлення та рендерингу (відображання)
	void pollEvents();
	void update();
	void render();

	//Головна функція ран
	void run();
	
private:
	//Декларуємо вікно, іконку та бул змінну яка зберігатиме стан гри (чи вона закінчена)
	sf::RenderWindow mWindow;
	sf::Image icon;
	bool gameOver;

	//Бул змінна, яка зберігає стан чи почата гра
	bool gameStateOn;

	// Об'єкт класу плейінг стейт щоб використовувати тут його функції 
	PlayingState gameState;
};