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
	map.update();

	checkPressedSpace();
	if (gameOn)
	{
		initGameplay();
		std::cout << "PRESSED\n";
	}
}

void PlayingState::render(sf::RenderTarget& target)
{
	map.render(target);
	pipes.render(target);
}
