#include "PlayingState.h"

PlayingState::PlayingState()
	: map(), pipes(), gameOn(false)
{
	
}

void PlayingState::initGameplay()
{
	pipes.update();
}

void PlayingState::checkPressedSpace()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		gameOn = true;
}

void PlayingState::update()
{
	base.update();

	checkPressedSpace();
	if (gameOn)
	{
		initGameplay();
	}

}

void PlayingState::render(sf::RenderTarget& target)
{
	map.render(target);
	pipes.render(target);
	base.render(target);
}
