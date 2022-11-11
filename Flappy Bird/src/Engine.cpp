#include "Engine.h"
#include "pch.h"
#include "IntroState.h"

Engine::Engine()
	:gameOver(false)
{
	mWindow.create(sf::VideoMode(600, 800), "Flappy Bird", sf::Style::Close);
	mWindow.setFramerateLimit(120);

	icon.loadFromFile("Textures/icon.png");
	mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	gameStates.addState(new IntroState);
}

void Engine::pollEvents()
{
	sf::Event ev;

	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameOver = true;
		else if (sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameOver = true;
		else if (sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
		{
			
		}

	}
}

void Engine::update()
{
	pollEvents();
	gameStates.update();
}

void Engine::render()
{
	mWindow.clear(sf::Color::Black);

	gameStates.render(mWindow);


	mWindow.display();
}

void Engine::run()
{
	while (!gameOver)
	{
		update();
		render();
	}
}
