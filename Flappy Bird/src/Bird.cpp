#include "pch.h"
#include "Bird.h"

Bird::Bird()
	:movingSpeed(0.45f), gameON(false)
{
	tBird1.loadFromFile("Textures/flappy1.png");
	tBird2.loadFromFile("Textures/flappy2.png");
	tBird3.loadFromFile("Textures/flappy3.png");

	bird.setTexture(tBird2);
	bird.setScale(2.f, 2.f);
	
	sf::FloatRect textRect = bird.getLocalBounds();
	bird.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);

	bird.setPosition(250.f, 400.f);

	dir = Directions::UP;
}

void Bird::manageDirections()
{
	switch (dir)
	{
	case Directions::UP:
		bird.move(0.f, -movingSpeed);
		break;
	case Directions::DOWN:
		bird.move(0.f, movingSpeed);
		break;
	}

}

void Bird::introStateMove()
{
	manageDirections();

	if (bird.getPosition().y < 390.f)
		dir = Directions::DOWN;

	if (bird.getPosition().y > 410.f)
		dir = Directions::UP;
}

void Bird::move()
{
	/*while (!gameON)
	{
		bird.move(0.f, -movingSpeed);

		movingSpeed = 2.f;
		bird.move(0.f, movingSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		gameON = true;*/
}

void Bird::update()
{
	move();
}

void Bird::render(sf::RenderTarget& target)
{
	target.draw(bird);
}
