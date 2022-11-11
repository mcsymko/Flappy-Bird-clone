#pragma once

#include "GameState.h"
#include <stack>

class StateManager
{
public:
	void addState(GameState* state);
	void deleteState();

	void update();
	void render(sf::RenderTarget& target);

private:
	std::stack<GameState*> states;
};

