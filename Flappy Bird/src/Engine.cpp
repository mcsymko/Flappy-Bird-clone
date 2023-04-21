//Бібліотеки та підключення класів необіхдні для використання функцій цих же самих класів
#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"

/*Конструктор який запускається в першу чергу та лише одноразово
* після двокрапки йде ініціалізація змінних
*/
Engine::Engine()
	:gameOver(false), gameStateOn(false)
{
	/*Створюється вікно з такими параметрами, 
	як ширина, висота, назва вікна, та можливість закривати по кнопці
	*/
	mWindow.create(sf::VideoMode(600, 800), "Flappy Bird", sf::Style::Close);

	/*Тут ставимо обмеження на фпс для плавного відображення
	щоб дорівнювало герцовці монітору*/
	mWindow.setFramerateLimit(120);
	/*Виключаємо повторення натискання клавіші для нормального керування пташкою*/
	mWindow.setKeyRepeatEnabled(false);

	/*Завантажуємо текстуру іконки вікна та встановлюємо іконку на вікно*/
	icon.loadFromFile("Textures/icon.png");
	mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

/*Тут обробляємо події під час гри (натискання клавіш клавіатури, мишки та кнопок вікна*/
void Engine::pollEvents()
{
	/*Змінна для захоплення вводу*/
	sf::Event ev;

	/*Дві змінні необхідні для читання натискання клавіш миші
	Перша - позиція курсору миші у вікні
	Друга - та сама позиція у вікні, тільки переведена у координати вікна*/
	auto mouse_position = sf::Mouse::getPosition(mWindow);
	auto translated_position = mWindow.mapPixelToCoords(mouse_position);

	/*Читаємо ввід*/
	while (mWindow.pollEvent(ev))
	{
		/*Якщо вікно хрестик вікна натистуний - закрити вікно*/
		if (ev.type == sf::Event::Closed)
			gameOver = true;

		/*Натиснутий ескейп - закрити гру*/
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameOver = true;

		/*Натиснутий пробіл?
		йдемо далі*/
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
		{
			/*Гра не почата? - почати гру*/
			if (!gameStateOn)
			{
				gameStateOn = true;
				gameState.isGameplayStateOn(gameStateOn);
			}
			/*Гра була на паузі? - відновити гру*/
			else if (gameState.isPauseStateOn())
			{
				gameState.initiateRestart();
			}

			/*Пташка рухається при натисканні пробілу*/
			gameState.moveBird();
		}
		/*Курсор миші наведений на кнопку рестарт та натиснута ліва клавіша миші?
		Рестартнути гру та зробити 1 рух пташкою*/
		else if (gameState.getRestartButtonBounds().contains(translated_position)
			&& ev.type == sf::Event::MouseButtonPressed && ev.key.code == sf::Mouse::Left)
		{
			gameState.initiateRestart();
			gameState.moveBird();
		}
	}
}

/*В апдейт передається обробляння подій та апдейт іншого класу*/
void Engine::update()
{
	pollEvents();
	gameState.update();
}

/*Чистимо вікно
  Рендеримо
  Відображаємо*/
void Engine::render()
{
	mWindow.clear(sf::Color::Black);
	gameState.render(mWindow);

	mWindow.display();
}

/*Це все працює, поки не закінчена гра, якщо закінчена - вікно закривається*/
void Engine::run()
{
	while (!gameOver)
	{
		update();
		render();
	}
}
