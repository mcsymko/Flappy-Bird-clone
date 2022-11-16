#include "PlayingState.h"

PlayingState::PlayingState()
	: map(), pipes(), gameOn(false), cScore(0)
{
	font.loadFromFile("Fonts/flappy.ttf");
	currentScore.setFont(font);
	currentScore.setCharacterSize(65);
	currentScore.setPosition(300.f - currentScore.getGlobalBounds().width, 100.f);

	currentScore.setString("0");
}

void PlayingState::initGameplay()
{
	pipes.update();
	bird.birdFalling();
}

void PlayingState::checkPressedSpace()
{
	if (!gameOn && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		gameOn = true;
	}
}

void PlayingState::moveBird()
{
	bird.move();
}

void PlayingState::update()
{
	base.update();
	bird.animateWings();

	if (gameOn)
		initGameplay();
	else 
	{
		checkPressedSpace();
		bird.introStateMove();
	}
}

void PlayingState::render(sf::RenderTarget& target)
{
	map.render(target);
	//pipes.render(target);
	base.render(target);
	target.draw(currentScore);
	bird.render(target);
}
