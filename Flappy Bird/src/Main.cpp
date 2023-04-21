// Підключаємо потрібні бібліотеки (precompiled headers) та клас енджин
#include "pch.h"
#include "Engine.h"

//Головна функція мейн
int main()
{
	// Функція для рандомайзера, яка генерує випадкове число
	srand(static_cast<unsigned>(time(NULL)));

	// Об'єкт класу енджин
	Engine engine;

	//Головна функція класу - ран
	engine.run();
}