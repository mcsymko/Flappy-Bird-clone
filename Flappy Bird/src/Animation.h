#pragma once

class Animation
{
public:
	Animation();

	const sf::Vector2f& getBirdPosition();

	void birdMove(float X, float Y);
	void animateIntro();
	
	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture birdTextures[3];
	sf::Sprite bird;

	sf::Clock timer;
	int numberOfTexture;
};

