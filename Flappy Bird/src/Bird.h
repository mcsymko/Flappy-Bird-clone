#pragma once

#include "Animation.h"

/*�������� ������ � ����� ����*/
enum class IntroStateDirections
{
	UP, DOWN
};

class Bird
{
public:
	/*�����������*/
	Bird();

	/*����������� ���������� �����*/
	void init();

	/*�������
	  1) ������� ����� ������
	  2) ������� ������� ������*/
	const sf::FloatRect getGlobalBounds();
	const sf::Vector2f& getBirdPosition();

	/*������� ������*/
	void birdFalling();

	/*������� ����������� ������
	  ���������� � ����� ����
	  ���������� � �������� ����*/
	void manageDirections();
	void introStateMove();
	void move();

	/*������� ������� ����
	  �� ������� �����������*/
	void animateWings();
	void animateCollision();

	/*������� ��������� �� ��������������*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*��'��� ����� Animation*/
	Animation birdAnimation;

	/*�������� �������� ������ � ����� ����*/
	const float staticMovingSpeed;

	/*��� ����� ��� ���� �� �������� ���*/
	bool gameON;
	
	/*��'��� �������� ������ � ����� ����*/
	IntroStateDirections introDir;
};

