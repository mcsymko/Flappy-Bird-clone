#include "pch.h"
#include "Bird.h"

/*�����������, ���� �������� ���*/
Bird::Bird()
	:staticMovingSpeed(0.45f), gameON(false)
{
	introDir = IntroStateDirections::UP;
}

/*����������� ������*/
void Bird::init()
{
	birdAnimation.init();
}

/*���������� ����� ������� ������*/
const sf::FloatRect Bird::getGlobalBounds()
{
	return birdAnimation.getGlobalBounds();
}

/*���������� ������� ������*/
const sf::Vector2f& Bird::getBirdPosition()
{
	return birdAnimation.getBirdPosition();
}

/*������ ������� ������ ������*/
void Bird::birdFalling()
{
	birdAnimation.birdFalling();
}

/*�������� ����������*/
void Bird::manageDirections()
{
	switch (introDir)
	{
		/*���� �������� "�����", �� ������ ����� �� ������ (y)*/
	case IntroStateDirections::UP:
		birdAnimation.introBirdAnimation(0.f, -staticMovingSpeed);
		break;
		/*��������� � �����*/
	case IntroStateDirections::DOWN:
		birdAnimation.introBirdAnimation(0.f, staticMovingSpeed);
		break;
	}
}

/*��������� ���� ����� �����*/
void Bird::introStateMove()
{
	/*� ����� ����� ������� ���� �� 
	  �������� ����������*/
	animateWings();
	manageDirections();

	/*� ��� ��� ������ ������� ������, ���� ���� ������� ����� ������ �� ��������� ����*/
	if (birdAnimation.getBirdPosition().y < 390.f)
		introDir = IntroStateDirections::DOWN;

	/*�� ���� ���, ���� ������ ����� ������ ������, ��������� �� �����*/
	if (birdAnimation.getBirdPosition().y > 410.f)
		introDir = IntroStateDirections::UP;
}

/*����������� ������� move() ����� Animation*/
void Bird::move()
{
	birdAnimation.birdMove();
}

/*������� ���� ����*/
void Bird::animateWings()
{
	birdAnimation.animateWings();
}

/*������� ����������� ������*/
void Bird::animateCollision()
{
	birdAnimation.animateCollision();
}

/*��������� ������*/
void Bird::update()
{
	birdFalling();
	birdAnimation.update();
}

/*³�������������*/
void Bird::render(sf::RenderTarget& target)
{
	birdAnimation.render(target);
}
