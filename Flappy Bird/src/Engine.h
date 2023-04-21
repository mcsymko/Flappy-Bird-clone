#pragma once

//ϳ�������� �������� �������� �� ����
#include "pch.h"
#include "PlayingState.h"

class Engine
{
public:
	// �����������
	Engine();

	//���������� ������, ������� ��������� �� ���������� (�����������)
	void pollEvents();
	void update();
	void render();

	//������� ������� ���
	void run();
	
private:
	//��������� ����, ������ �� ��� ����� ��� ���������� ���� ��� (�� ���� ��������)
	sf::RenderWindow mWindow;
	sf::Image icon;
	bool gameOver;

	//��� �����, ��� ������ ���� �� ������ ���
	bool gameStateOn;

	// ��'��� ����� ������ ����� ��� ��������������� ��� ���� ������� 
	PlayingState gameState;
};