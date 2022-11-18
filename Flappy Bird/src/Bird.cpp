#include "pch.h"
#include "Bird.h"

Bird::Bird()
	:staticMovingSpeed(0.45f), dynamicMovingSpeed(-20.f), gameON(false)
{
	introDir = IntroStateDirections::UP;
}

void Bird::birdFalling()
{
	birdAnimation.birdFalling();
}

void Bird::manageDirections()
{
	switch (introDir)
	{
	case IntroStateDirections::UP:
		birdAnimation.introBirdAnimation(0.f, -staticMovingSpeed);
		break;
	case IntroStateDirections::DOWN:
		birdAnimation.introBirdAnimation(0.f, staticMovingSpeed);
		break;
	}
}

void Bird::introStateMove()
{
	animateWings();
	manageDirections();

	if (birdAnimation.getBirdPosition().y < 390.f)
		introDir = IntroStateDirections::DOWN;

	if (birdAnimation.getBirdPosition().y > 410.f)
		introDir = IntroStateDirections::UP;
}

void Bird::move()
{
	birdAnimation.birdMove(0.f , dynamicMovingSpeed);
}

void Bird::animateWings()
{
	birdAnimation.animateWings();
}

void Bird::update()
{
	birdFalling();
	birdAnimation.update();
}

void Bird::render(sf::RenderTarget& target)
{
	birdAnimation.render(target);
}
