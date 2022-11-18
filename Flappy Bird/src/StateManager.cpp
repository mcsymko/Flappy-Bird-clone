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

const GameState* StateManager::returnState()
{
	return states.top();
}

void StateManager::isGameOn(bool X)
{
	states.top()->isGameOn(X);
}

void StateManager::moveBird()
{
	states.top()->moveBird();
}

void StateManager::update()
{
	states.top()->update();
}

void StateManager::render(sf::RenderTarget& target)
{
	states.top()->render(target);
}
