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
	bool gameOver;
	
	sf::Font mFont;
	sf::Text mText;

	StateManager gameStates;
};