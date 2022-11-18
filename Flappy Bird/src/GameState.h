#pragma once
#include "pch.h"

class GameState
{
public:
	virtual void isGameOn(bool) = 0;

	virtual void moveBird() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

