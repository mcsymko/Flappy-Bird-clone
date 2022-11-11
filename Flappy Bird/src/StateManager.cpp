#include "StateManager.h"
#include "pch.h"	

void StateManager::addState(GameState* state)
{
	states.push(state);
}

void StateManager::deleteState()
{
	states.pop();
}

void StateManager::update()
{
	states.top()->update();
}

void StateManager::render(sf::RenderTarget& target)
{
	states.top()->render(target);
}
