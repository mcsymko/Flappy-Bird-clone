#include "pch.h"
#include "Pipes.h"

Pipes::Pipes()
	:movingSpeed(1.f), horizontalDistanceBetweenPipes(350.f), verticalDistanceBetweenPipes(650.f)
{
	texturePipeUp.loadFromFile("Textures/pipeU.png");
	texturePipeDown.loadFromFile("Textures/pipeD.png");

	init();
}

void Pipes::init()
{
	for (int i = 0; i < 2; i++)
	{
		pipeUp[i].setTexture(texturePipeUp);
		pipeDown[i].setTexture(texturePipeDown);

		pipeUp[i].setScale(1.8f, 1.5f);	
		pipeDown[i].setScale(1.8f, 1.5f);
	}
	calculateRandomPosition();

	pipeUp[0].setPosition(600.f, 800.f - pipeUp->getGlobalBounds().height + randomPosition);
	pipeDown[0].setPosition(600.f, pipeUp[0].getPosition().y - verticalDistanceBetweenPipes);

	calculateRandomPosition();

	pipeUp[1].setPosition(pipeUp[0].getPosition().x + horizontalDistanceBetweenPipes, 800.f - pipeUp->getGlobalBounds().height + randomPosition);
	pipeDown[1].setPosition(pipeDown[0].getPosition().x + horizontalDistanceBetweenPipes, pipeUp[1].getPosition().y - verticalDistanceBetweenPipes);

}

void Pipes::calculateRandomPosition()
{
	randomPosition = rand() % 380 - 100;
}

void Pipes::checkRespawn()
{
	for (int i = 0; i < 2; i++)
	{
		if (pipeUp[i].getPosition().x + pipeUp[i].getGlobalBounds().width < 0.f)
		{
			calculateRandomPosition();

			pipeUp[i].setPosition(600.f, 800.f - pipeUp->getGlobalBounds().height + randomPosition);
			pipeDown[i].setPosition(600.f, pipeUp[i].getPosition().y - verticalDistanceBetweenPipes);
		}
	}
}

void Pipes::move()
{
	for (int i = 0; i < 2; i++)
	{
		pipeUp[i].setPosition(pipeUp[i].getPosition().x - movingSpeed, pipeUp[i].getPosition().y);
		pipeDown[i].setPosition(pipeDown[i].getPosition().x - movingSpeed, pipeDown[i].getPosition().y);

		checkRespawn();
	}
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
