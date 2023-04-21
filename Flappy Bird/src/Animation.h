#pragma once

class Animation
{
public:
	/*�����������*/
	Animation();
	
	/*����������� (�������� ��� ��������, � ������ ������� ������)*/
	void init();

	/*���������� �������, �� ���������� ������� ������ ��� ���������� �� ������ ������� ����
	�� ���������� ������� ������ ��� ��������� �� �� ������������ ������ � �����������*/
	const sf::Vector2f& getBirdPosition();
	const sf::FloatRect getGlobalBounds();

	/*������� ������ � ����� ����
	  ������� ����������
	  �� ������� ������ ������*/
	void introBirdAnimation(float x, float y);
	void birdMove();
	void birdFalling();

	/*������� ����
	  �� �����������*/
	void animateWings();
	void animateCollision();
	
	/*������� ���������
	�� ��������������*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*��� �������� � ����� �������� ���� ��� ������� �������
	  ��� ������ � �������
	  �� ����� ��������, ���������� ��� ������� �������*/
	sf::Texture birdTextures[3];
	sf::Sprite bird;
	int numberOfTexture;

	/*�������, �������� ��� �������� ����������� �������*/
	sf::Clock timerOne, timerTwo;

	/*�����, ��� ������ �������� ������ ��������� �������*/
	float downwardsRotation;

	/*�������� ���������� ������*/
	float birdFallingSpeed;
};