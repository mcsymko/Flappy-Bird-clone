#pragma once

#include "GameState.h"
#include <stack>

class StateManager
{
public:
	void addState(GameState* state);
	void deleteState();
	const GameState* returnState();

	void isGameOn(bool X);

	void moveBird();
	void update();
	void render(sf::RenderTarget& target);

private:
	std::stack<GameState*> states;
};

