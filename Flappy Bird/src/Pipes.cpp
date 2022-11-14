#include "pch.h"
#include "Pipes.h"

Pipes::Pipes()
	:movingSpeed(1.f)
{
	texturePipeUp.loadFromFile("Textures/pipeU.png");
	texturePipeDown.loadFromFile("Textures/pipeD.png");
	
	init();
}

void Pipes::init()
{
	for (int i = 0; i < 2; i++)
	{
		pipeUp[0].setTexture(texturePipeUp);
		pipeDown[0].setTexture(texturePipeDown);

		pipeUp[0].setScale(1.8f, 1.f);
		pipeDown[0].setScale(1.8f, 1.f);

		pipeUp[0].setPosition(600.f, 800.f - pipeUp->getGlobalBounds().height - 100.f);
		pipeDown[0].setPosition(600.f, 0.f);

	}
}

void Pipes::move()
{
	pipeUp[0].setPosition(pipeUp[0].getPosition().x - movingSpeed, pipeUp[0].getPosition().y);
	pipeDown[0].setPosition(pipeDown[0].getPosition().x - movingSpeed, pipeDown[0].getPosition().y);
}

void Pipes::update()
{
	move();
}

void Pipes::render(sf::RenderTarget& target)
{
	for (int i = 0; i < 2; i++)
	{
		target.draw(pipeUp[i]);
		target.draw(pipeDown[i]);
	}
}
