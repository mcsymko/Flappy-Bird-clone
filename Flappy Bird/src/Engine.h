#pragma once

#include "pch.h"
#include "StateManager.h"

class Engine
{
public:
	Engine();

	void pollEvents();

	void update();

	void render();

	void run();
	
private:
	sf::RenderWindow mWindow;
	sf::Image icon;
	bool gameOver;

	sf::Font mFont;
	sf::Text mText;

	StateManager gameStates;
};