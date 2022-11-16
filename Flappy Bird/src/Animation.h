#pragma once

class Animation
{
public:
	Animation();

	const sf::Vector2f& getBirdPosition();

	void birdUpwardsRotation();
	void introBirdAnimation(float x, float y);
	void birdMove(float X, float Y);
	void animateWings();
	
	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture birdTextures[3];
	sf::Sprite bird;

	sf::Clock timer;
	int numberOfTexture;

	float upwardsRotation;

	float distanceY;
};

