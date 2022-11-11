#pragma once

class Pipes
{
public:
	Pipes();

	void move();

	void update();
	void render(sf::RenderTarget& target);
	
private:
	sf::Texture texturePipe;
	sf::Sprite pipeUp[2], pipeDown[2];

	const float speed;
};

