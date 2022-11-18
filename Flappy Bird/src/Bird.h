#pragma once

#include "Animation.h"

enum class IntroStateDirections
{
	UP, DOWN
};

class Bird
{
public:
	Bird();

	void birdFalling();
	void manageDirections();
	void introStateMove();
	void move();

	void animateWings();

	void update();
	void render(sf::RenderTarget& target);

private:
	Animation birdAnimation;

	float staticMovingSpeed;
	float dynamicMovingSpeed;

	bool gameON;
	
	IntroStateDirections introDir;
};

