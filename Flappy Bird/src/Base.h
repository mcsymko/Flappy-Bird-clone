#pragma once

class Base
{
public:
	/*�����������*/
	Base();

	/*���������� �����, ��� ������ ����� ��������� 
      (��� �������� �� �� ������������ ������ � ���� ����������)*/
	const sf::FloatRect getGlobalBounds();

	/*������� ���������� ���������*/
	void move();

	/*��������� �� ��������������*/
	void update();
	void render(sf::RenderTarget& target);

private:
	/*�������� ��������� �� ���� ���������*/
	sf::Texture baseTexture;
	sf::Sprite mBase;

	/*�� ���������� ��������*/
	const float movingSpeed;
};

