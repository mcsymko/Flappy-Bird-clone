#include "pch.h"
#include "Animation.h"

Animation::Animation()
	:numberOfTexture(0)
{
	birdTextures[0].loadFromFile("Textures/flappy1.png");
	birdTextures[1].loadFromFile("Textures/flappy2.png");
	birdTextures[2].loadFromFile("Textures/flappy3.png");

	bird.setScale(2.f, 2.f);

	sf::FloatRect textRect = bird.getLocalBounds();
	bird.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	bird.setPosition(250.f, 400.f);

	bird.setTexture(birdTextures[0]);
}

const sf::Vector2f& Animation::getBirdPosition()
{
	return bird.getPosition();
}

void Animation::birdMove(float X, float Y)
{
	bird.move(X, Y);
}

void Animation::animateIntro()
{
	if (timer.getElapsedTime().asSeconds() > 0.1f)
	{
		if (++numberOfTexture > 2)
		{
			numberOfTexture = 0;
		}
		bird.setTexture(birdTextures[numberOfTexture]);
		timer.restart();
	}
}

void Animation::update()
{
	animateIntro();
}

void Animation::render(sf::RenderTarget& target)
{
	target.draw(bird);
}
