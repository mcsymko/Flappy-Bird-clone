#pragma once

#include "Animation.h"

enum class Directions
{
	UP, DOWN
};

class Bird
{
public:
	Bird();

	void manageDirections();
	void introStateMove();
	void move();

	void update();
	void render(sf::RenderTarget& target);

private:
	Animation birdAnimation;

	float movingSpeed;

	bool gameON;
	
	Directions dir;
};

