#include "pch.h"
#include "Bird.h"

Bird::Bird()
	:movingSpeed(0.45f), gameON(false)
{
	dir = Directions::UP;
}

void Bird::manageDirections()
{
	switch (dir)
	{
	case Directions::UP:
		birdAnimation.birdMove(0.f, -movingSpeed);
		break;
	case Directions::DOWN:
		birdAnimation.birdMove(0.f, movingSpeed);
		break;
	}
}

void Bird::introStateMove()
{
	birdAnimation.update();

	manageDirections();

	if (birdAnimation.getBirdPosition().y < 390.f)
		dir = Directions::DOWN;

	if (birdAnimation.getBirdPosition().y > 410.f)
		dir = Directions::UP;
}

void Bird::move()
{
	
}

void Bird::update()
{
	move();
}

void Bird::render(sf::RenderTarget& target)
{
	birdAnimation.render(target);
}
