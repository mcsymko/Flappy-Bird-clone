#include "pch.h"
#include "Base.h"

Base::Base()
	:movingSpeed(2.f)
{
	/*������������� �������� � �����
	  �������������� �������� �� �������
	  �� �������������� ����� �������*/
	baseTexture.loadFromFile("Textures/base.png");
	mBase.setTexture(baseTexture);
	mBase.setScale(2.f, 1.f);
}

/*��������� �������� �����*/
const sf::FloatRect Base::getGlobalBounds()
{
	return mBase.getGlobalBounds();
}

/*������ ���������*/
void Base::move()
{
	/*��� �� ������ ���������� ���������, �� ������������� �� �� ����� ������� ����
	  �� ����� ���� ������ ����� ������� �� ���� (x)*/
	if (mBase.getPosition().x + mBase.getGlobalBounds().width < 600)
		mBase.setPosition(sf::Vector2f(-26.f, 700.f));

	/*������ ��������� �� ���� �� ������ ��������*/
	mBase.setPosition(sf::Vector2f(mBase.getPosition().x - movingSpeed, 700.f));
}

/*��������� �������*/
void Base::update()
{
	move();
}

/*³����������� �������*/
void Base::render(sf::RenderTarget& target)
{
	target.draw(mBase);
}
