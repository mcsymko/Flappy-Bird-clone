#include "pch.h"
#include "Pipes.h"

Pipes::Pipes()
	:speed(-1.f)
{
	texturePipe.loadFromFile("Textures/pipe.png");
	
	for (int i = 0; i < 2; i++)
	{
		pipeUp[i].setTexture(texturePipe);
		pipeDown[i].setTexture(texturePipe);
	}
}

void Pipes::move()
{

}

void Pipes::update()
{

}

void Pipes::render(sf::RenderTarget& target)
{
	for (int i = 0; i < 2; i++)
	{
		target.draw(pipeUp[i]);
		target.draw(pipeDown[i]);
	}
}
