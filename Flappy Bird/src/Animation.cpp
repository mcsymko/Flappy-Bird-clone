#include "pch.h"
#include "Animation.h"

Animation::Animation()
	:numberOfTexture(0), upwardsRotation(-5.f), downwardsRotation(0.f),
	birdJumpingSpeed(-5.f), birdFallingSpeed(0.f)
{
	birdTextures[0].loadFromFile("Textures/flappy1.png");
	birdTextures[1].loadFromFile("Textures/flappy2.png");
	birdTextures[2].loadFromFile("Textures/flappy3.png");

	bird.setScale(2.f, 2.f);

	/*bird.setOrigin((sf::Vector2f)birdTextures[1].getSize() / 2.f);*/

	bird.setPosition(250.f, 400.f);

	bird.setTexture(birdTextures[0]);
}

const sf::Vector2f& Animation::getBirdPosition()
{
	return bird.getPosition();
}

void Animation::introBirdAnimation(float x, float y)
{
	bird.move(x, y);
}

void Animation::birdMove(float X, float Y)
{
	birdFallingSpeed = -5.f;
	downwardsRotation = -40.f;
}

void Animation::birdFalling()
{
	if (timerOne.getElapsedTime().asSeconds() > 0.006f)
	{
		if (birdFallingSpeed > 4.f)
			birdFallingSpeed = 4.f;

		if (downwardsRotation > 90.f)
		{
			bird.setTexture(birdTextures[1]);
			downwardsRotation = 90.f;
		}
		else if (downwardsRotation <= 0.f)
		{
			downwardsRotation += 0.5f;
		}
		else
		{
			bird.setTexture(birdTextures[1]);
			downwardsRotation += 2.f;
		}

		birdFallingSpeed += 0.14f;

		bird.move(0.f, birdFallingSpeed);
		bird.setRotation(downwardsRotation);

		timerOne.restart();
	}

	/*bird.move(0.f, 3.7f);*/
}

void Animation::animateWings()
{
	
	if (timerTwo.getElapsedTime().asSeconds() > 0.1f)
	{
		if (++numberOfTexture > 2)
		{
			numberOfTexture = 0;
		}
		bird.setTexture(birdTextures[numberOfTexture]);
	
		timerTwo.restart();
	}
}

void Animation::update()
{
	animateWings();
}

void Animation::render(sf::RenderTarget& target)
{
	target.draw(bird);
}
