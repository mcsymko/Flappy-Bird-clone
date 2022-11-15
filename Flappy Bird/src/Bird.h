#pragma once

enum class Directions
{
	UP, DOWN
};

class Bird
{
public:
	Bird();

	void manageDirections();
	void introStateMove();
	void move();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture tBird1, tBird2, tBird3;
	sf::Sprite bird;

	float movingSpeed;

	bool gameON;
	
	Directions dir;
};

