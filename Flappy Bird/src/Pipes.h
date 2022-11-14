#pragma once

class Pipes
{
public:
	Pipes();

	void init();
	void calculateRandomPosition();
	void checkRespawn();
	void move();

	void update();
	void render(sf::RenderTarget& target);
	
private:
	sf::Texture texturePipeUp, texturePipeDown;
	sf::Sprite pipeUp[2], pipeDown[2];

	const float movingSpeed;
	const float horizontalDistanceBetweenPipes;
	const float verticalDistanceBetweenPipes;

	int randomPosition;
};

