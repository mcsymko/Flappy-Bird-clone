#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"

Engine::Engine()
	:gameOver(false), gameStateOn(false)
{
	mWindow.create(sf::VideoMode(600, 800), "Flappy Bird", sf::Style::Close);
	mWindow.setFramerateLimit(120);
	mWindow.setKeyRepeatEnabled(false);

	icon.loadFromFile("Textures/icon.png");
	mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	gameStates.addState(new PlayingState);
}

void Engine::pollEvents()
{
	sf::Event ev;

	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameOver = true;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameOver = true;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
		{
			if (!gameStateOn)
			{
				gameStateOn = true;
				gameStates.isGameOn(gameStateOn);
			}

			gameStates.moveBird();
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
