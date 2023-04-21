#include "pch.h"
#include "Animation.h"

Animation::Animation()
	:numberOfTexture(0), downwardsRotation(0.f), birdFallingSpeed(0.f)
{
	/*ϳ������� ������� �������� � �����*/
	birdTextures[0].loadFromFile("Textures/flappy1.png");
	birdTextures[1].loadFromFile("Textures/flappy2.png");
	birdTextures[2].loadFromFile("Textures/flappy3.png");

	/*�������������� ������ ������,
	  �� �����
	  �� ��������� ��������*/
	bird.setScale(2.f, 2.f);
	bird.setOrigin((sf::Vector2f)birdTextures[1].getSize() / 2.f);
	bird.setTexture(birdTextures[0]);

	/*����������� ���������� �����*/
	init();
}

void Animation::init()
{
	/*�������
	  ��������
	  �������
	  �������� ������*/
	bird.setPosition(250.f, 400.f);
	numberOfTexture = 0;
	downwardsRotation = 0.f;
	birdFallingSpeed = 0.f;
}

/*�������, ��� ������� ������� ������*/
const sf::Vector2f& Animation::getBirdPosition()
{
	return bird.getPosition();
}

/*�� ����� ��� �������� �� �� �������� �����������*/
const sf::FloatRect Animation::getGlobalBounds()
{
	return bird.getGlobalBounds();
}

/*���������� ������ � ���� ����� �� �������� �����*/
void Animation::introBirdAnimation(float x, float y)
{
	bird.move(x, y);
}

/*���������� ������ � ���� ���*/
void Animation::birdMove()
{
	birdFallingSpeed = -5.f;
	downwardsRotation = -40.f;
}

/*������ ������*/
void Animation::birdFalling()
{
	/*��� �������� ����������� ��������������� ������ �� ��������� �����
	���� ���������� ����� ��, �� ��������� ��� ������ ������������������*/
	if (timerOne.getElapsedTime().asSeconds() > 0.006f)
	{
		/*���� ������ ������� ������ ��������, �� �������� ��*/
		if (birdFallingSpeed > 4.f)
			birdFallingSpeed = 4.f;

		/*���� ������ ����������� ������� ���� ��� �����, �� ���������� �� �����*/
		if (downwardsRotation > 90.f)
		{
			/*�� �������� ������� ����*/
			bird.setTexture(birdTextures[1]);
			downwardsRotation = 90.f;
		}

		/*���� ������� ������ (������ 0 ������� ��� �����, �� ���������� ��������� �� ����*/
		else if (downwardsRotation <= 0.f)
		{
			downwardsRotation += 0.5f;
		}

		/*���� ����� �� 0 ��� ����� �� 90, �� ��������� ������ � �� 
		�������� �����*/
		else
		{
			bird.setTexture(birdTextures[1]);
			downwardsRotation += 2.f;
		}

		/*������������� ������ � ������ ������*/
		birdFallingSpeed += 0.14f;

		/*������ ������ �� ������ ��������
		�� ��������� ������ �� ������� �����*/
		bird.move(0.f, birdFallingSpeed);
		bird.setRotation(downwardsRotation);

		/*������� ������� � ���� �����*/
		timerOne.restart();
	}
}

/*������� ����*/
void Animation::animateWings()
{
	/*�� ���� �� �������*/
	if (timerTwo.getElapsedTime().asSeconds() > 0.1f)
	{
		/*���� ��������� ����� �������� ������ �� 2 
		�� �������� ����� �������� �� ����. �� ��� ����, ���
		������� �������� 0, 1, 2, 0, 1, 2 � �.�.*/
		if (++numberOfTexture > 2)
		{
			numberOfTexture = 0;
		}
		/*�������������� �������� �� ��������*/
		bird.setTexture(birdTextures[numberOfTexture]);
		
		/*�� ������������ ������*/
		timerTwo.restart();
	}
}

/*���� ���� ������� � ����, �� ��� ���������� � ����������
 ������ ������ ���� �� ����� � �������� � ����*/

/*��� ����� ��� �� ����, �� � � ������� birdFalling() ����:
1)�������� �� ������ ����������� ���� ���� �� 
2)�������� ������*/
void Animation::animateCollision()
{
	/*���� ������ ���� ����*/
	if (bird.getPosition().y < 670.f)
	{
		if (timerOne.getElapsedTime().asSeconds() > 0.005f)
		{
			if (birdFallingSpeed > 6.f)
				birdFallingSpeed = 6.f;

			if (downwardsRotation > 90.f)
			{
				bird.setTexture(birdTextures[1]);
				downwardsRotation = 90.f;
			}
			else
			{
				bird.setTexture(birdTextures[1]);
				downwardsRotation += 4.f;
			}

			birdFallingSpeed += 0.3f;

			bird.move(0.f, birdFallingSpeed);

			bird.setRotation(downwardsRotation);

			timerOne.restart();
		}
	}
}

/*������� ������� ���������, � ��� ����������� ������� ����*/
void Animation::update()
{
	animateWings();
}

/*������� ��������������*/
void Animation::render(sf::RenderTarget& target)
{
	target.draw(bird);
}
