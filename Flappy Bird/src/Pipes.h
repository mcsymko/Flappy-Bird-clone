#pragma once

class Pipes
{
public:
	/*�����������*/
	Pipes();

	/*�����������*/
	void init();

	/*�������, �� ���������� ����� ���� ���� ���� ��� �������� �����������*/
	const sf::FloatRect getGlobalBoundsPipeUp();
	const sf::FloatRect getGlobalBoundsPipeDown();

	/*�������, �� ���������� �������� �� ���� (x)
	  ��� �������� ������������� ���� ������*/
	const float& getPipe1PositionX();
	const float& getPipe2PositionX();

	/*������� ������������ ��������� ������� ����
	  �������� �� ���� ����������
	  �� ������� ���������� ����*/
	void calculateRandomPosition();
	void checkRespawn();
	void move();

	/*������� ��������� �� ��������������*/
	void update();
	void render(sf::RenderTarget& target);
	
private:
	/*�������� ���� ������ �� ����� ��
	  3 ������� ��� ����� � ���*/
	sf::Texture texturePipeUp, texturePipeDown;
	sf::Sprite pipeUp[2], pipeDown[2];

	/*��������� ���� (����, �� �� ����� �������) �������� ����,
	  ������������� ������� �� �������
	  ����������� ������� �� �������*/
	const float movingSpeed;
	const float horizontalDistanceBetweenPipes;
	const float verticalDistanceBetweenPipes;

	/*�������� ��������� ������� ����*/
	int randomPosition;
};

