#pragma once
#include "pch.h"

class GameState
{
public:
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

