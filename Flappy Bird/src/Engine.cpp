//��������� �� ���������� ����� ������� ��� ������������ ������� ��� �� ����� �����
#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"

/*����������� ���� ����������� � ����� ����� �� ���� ����������
* ���� ��������� ��� ����������� ������
*/
Engine::Engine()
	:gameOver(false), gameStateOn(false)
{
	/*����������� ���� � ������ �����������, 
	�� ������, ������, ����� ����, �� ��������� ��������� �� ������
	*/
	mWindow.create(sf::VideoMode(600, 800), "Flappy Bird", sf::Style::Close);

	/*��� ������� ��������� �� ��� ��� �������� �����������
	��� ���������� �������� �������*/
	mWindow.setFramerateLimit(120);
	/*��������� ���������� ���������� ������ ��� ����������� ��������� �������*/
	mWindow.setKeyRepeatEnabled(false);

	/*����������� �������� ������ ���� �� ������������ ������ �� ����*/
	icon.loadFromFile("Textures/icon.png");
	mWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

/*��� ���������� ��䳿 �� ��� ��� (���������� ����� ���������, ����� �� ������ ����*/
void Engine::pollEvents()
{
	/*����� ��� ���������� �����*/
	sf::Event ev;

	/*�� ���� �������� ��� ������� ���������� ����� ����
	����� - ������� ������� ���� � ���
	����� - �� ���� ������� � ���, ����� ���������� � ���������� ����*/
	auto mouse_position = sf::Mouse::getPosition(mWindow);
	auto translated_position = mWindow.mapPixelToCoords(mouse_position);

	/*������ ���*/
	while (mWindow.pollEvent(ev))
	{
		/*���� ���� ������� ���� ���������� - ������� ����*/
		if (ev.type == sf::Event::Closed)
			gameOver = true;

		/*���������� ������ - ������� ���*/
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameOver = true;

		/*���������� �����?
		����� ���*/
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
		{
			/*��� �� ������? - ������ ���*/
			if (!gameStateOn)
			{
				gameStateOn = true;
				gameState.isGameplayStateOn(gameStateOn);
			}
			/*��� ���� �� ����? - �������� ���*/
			else if (gameState.isPauseStateOn())
			{
				gameState.initiateRestart();
			}

			/*������ �������� ��� ��������� ������*/
			gameState.moveBird();
		}
		/*������ ���� ��������� �� ������ ������� �� ��������� ��� ������ ����?
		����������� ��� �� ������� 1 ��� �������*/
		else if (gameState.getRestartButtonBounds().contains(translated_position)
			&& ev.type == sf::Event::MouseButtonPressed && ev.key.code == sf::Mouse::Left)
		{
			gameState.initiateRestart();
			gameState.moveBird();
		}
	}
}

/*� ������ ���������� ���������� ���� �� ������ ������ �����*/
void Engine::update()
{
	pollEvents();
	gameState.update();
}

/*������� ����
  ���������
  ³���������*/
void Engine::render()
{
	mWindow.clear(sf::Color::Black);
	gameState.render(mWindow);

	mWindow.display();
}

/*�� ��� ������, ���� �� �������� ���, ���� �������� - ���� �����������*/
void Engine::run()
{
	while (!gameOver)
	{
		update();
		render();
	}
}
