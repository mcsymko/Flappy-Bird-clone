#include "pch.h"
#include "PlayingState.h"

/*ϳ���������� �������� ��� ����������� ����*/
#include <sstream>

/*�����������, � ����� ����������� ����������� ���������� �����*/
PlayingState::PlayingState()
	: map(), pipes(), gameOn(false), gameOverStateOn(false), cScore(0), rScore(0)
{
	initUI();
}

/*����������� ���� ���������� (������, ������, ���� � ��������, ������ �������)*/
void PlayingState::initUI()
{
	/*ϳ���������� �����
	�������������� ����� �� ������
	�������������� ����� ������
	�� ������� ������ */
	font.loadFromFile("Fonts/flappy.ttf");
	currentScore.setFont(font);
	currentScore.setCharacterSize(60);
	currentScore.setPosition(300.f - currentScore.getGlobalBounds().width / 2.f , 100.f);

	/*�������� ������������ � ����� ��� ����������� ������ � ��*/
	currentPoints = std::to_string(cScore);
	currentScore.setString(currentPoints);

	/*�� ���� ����� � ��������� ��������*/
	recordScore.setFont(font);
	recordScore.setCharacterSize(60);
	recordScore.setPosition(302.f, 380.f);

	recordPoints = std::to_string(rScore);
	recordScore.setString(recordPoints);

	/*����������� ����� � ��������, ��� ���� ������� �������:
	�����, ����������� ��� ������� ��������������, ����,
	���� �����, ������� ����� �� �������*/
	scoreBox.setSize(sf::Vector2f(200.f, 200.f));
	scoreBox.setOrigin((sf::Vector2f)scoreBox.getSize() / 2.f);
	scoreBox.setFillColor(sf::Color{ 222, 216, 149 });
	scoreBox.setOutlineColor(sf::Color::Black);
	scoreBox.setOutlineThickness(4.f);
	scoreBox.setPosition(sf::Vector2f(315.f, 350.f));

	/*����������� ������� �� ����� � ������ ���� (���� ������� �������):
	������ SCORE ��
	������ RECORD*/
	scoreBoxCurScore.setFont(font);
	scoreBoxRecScore.setFont(font);
	scoreBoxCurScore.setFillColor(sf::Color{ 252, 120, 88 });
	scoreBoxRecScore.setFillColor(sf::Color{ 252, 120, 88 });
	scoreBoxCurScore.setCharacterSize(30);
	scoreBoxRecScore.setCharacterSize(30);
	scoreBoxCurScore.setString("SCORE");
	scoreBoxRecScore.setString("BEST");
	scoreBoxCurScore.setPosition(scoreBox.getPosition().x - 40.f, scoreBox.getPosition().y - 100.f);
	scoreBoxRecScore.setPosition(scoreBox.getPosition().x - 30.f, scoreBox.getPosition().y);

	/*�� ����, ����� ��� ������ "�������"*/
	restartTexture.loadFromFile("Textures/restart.png");
	restartButton.setTexture(restartTexture);
	restartButton.setScale(0.32f, 0.32f);
	restartButton.setPosition(240.f, 465.f);
}

/*�������, ��� ���������� �������� �� �������� ��� (�� �������� ������� �����)*/
void PlayingState::isGameplayStateOn(bool X)
{
	gameOn = X;
}

/*�������, ��� ������� ��������, �� ������� ������� (�� ���� ��������� ���� � ��������)*/
const bool& PlayingState::isPauseStateOn()
{
	return gameOverStateOn;
}

/*������� ���� ������ ������� ��� ������� �� � ������ ���� � �������� ���� ������*/
const sf::FloatRect PlayingState::getRestartButtonBounds()
{
	return restartButton.getGlobalBounds();
}

/*������� �������� �� �� ���������� ��� (�� ����������� ������� � ����������: ������� ��� ������)
���� ��� - �������� ��� (��������� ���� � ��������)*/
void PlayingState::checkCollision()
{
	if (bird.getGlobalBounds().intersects(base.getGlobalBounds()) ||
		bird.getGlobalBounds().intersects(pipes.getGlobalBoundsPipeUp()) ||
		bird.getGlobalBounds().intersects(pipes.getGlobalBoundsPipeDown()))
	{
		gameOverStateOn = true;
	}
}

/*�������� �� ���������� ������ �����:
���� ��� - ���������� ����*/
void PlayingState::checkScoring()
{
	if (pipes.getPipe1PositionX() == 222.f || pipes.getPipe2PositionX() == 222.f)
	{
		++cScore;
	}
}

/*������� ���������� (����������� �� ������� � ���� Animation*/
void PlayingState::animateCollision()
{
	bird.animateCollision();
}

/*��������� ���� �����(���� � �������� ���� �����������)*/
void PlayingState::pushPauseState()
{
	/*̳������� ������� ����������� �������:
	������ ������ �� ����� � ���� ��� 
	���� ��� � ���� �� ������ "SCORE"*/
	currentScore.setPosition(302.f, 278.f);

	/*���� ��� ������� ����� ������, �� ���������� ����� ������*/
	if(rScore < cScore)
		rScore = cScore;
}

void PlayingState::initGameplay()
{
	/*����������� ��������, ���� ������� ������ ��� �������� �����.
	���� ���, �� - ��������� �����, ������, ������������ ����������� 
	�� ������������� ����.*/
	pipes.update();
	bird.update();
	checkCollision();
	checkScoring();
}

/*����������� ������� (���� ���� �������� ������� ���� ������ �� ��� �� ������� �����
��� ������� �� ������ RESTART*/
void PlayingState::initiateRestart()
{
	/*��� ������ �� �����, �� ���� �����/��� ���� ���� ��� (���� ����) ��� �� ���������*/
	gameOverStateOn = false;

	/*��������� �������*/
	cScore = 0;

	/*�� ��������� ����������� ���� �� ����*/
	currentScore.setPosition(300.f - currentScore.getGlobalBounds().width, 100.f);

	/*��������� ����� �� ������ �� ��������� ��������*/
	pipes.init();
	bird.init();
}

/*������ ������ (����������� �� ������� � ����� Bird.*/
void PlayingState::moveBird()
{
	bird.move();
}

/*���������� �����.
����������� ���� ��� ������� ������ � ������������ ���� � ������.
�������� �� �������� �������, ��� � ���������*/
void PlayingState::updateText()
{
	std::stringstream ss;
	std::stringstream ssTwo;

	ss << cScore;
	currentScore.setString(ss.str());

	ssTwo << rScore;
	recordScore.setString(ssTwo.str());
}

/*������� ��������� ������� � ����� ����.
  � ����� ����� ������� �����, ���� �� ���� ����� �� ���.
  ���� �������� �� �� �������� ����� ��� (������� ����������� � ������� ��� ������).

  ͳ = ����������� ����� ���������, ���� �������� �� �������� ���? (�� �������� ������� �����
  ������ ���)
	��� = ������������ �������� (��������� ���) - ���������� ��� ����, ������ � �.�.
	ͳ  = ������� ������ � ���� ����� �� ��������� ���� ������� ������� �����.
  
  ��� (��� ��������, ������ ������������ � ����������) = ������� ������� ��������
  (������) �� ��������� ���� � �������� (���� �����)*/
void PlayingState::update()
{
	updateText();

	if (!gameOverStateOn)
	{
		base.update();

		if (gameOn)
			initGameplay();

		else if (!gameOn)
		{
			bird.introStateMove();
		}
	}
	else
	{
		animateCollision();
		pushPauseState();
	}
}

/*³������������ ���� ����� (���� � ��������, ������ SCORE, RECORD
������� ����, �� ����������, ��� � ���������
�� ������ �������*/
void PlayingState::drawPauseState(sf::RenderTarget& target)
{
	target.draw(scoreBox);
	target.draw(scoreBoxCurScore);
	target.draw(scoreBoxRecScore);
	target.draw(recordScore);
	target.draw(currentScore);
	target.draw(restartButton);
	
}

/*������� ������������ �������*/
void PlayingState::render(sf::RenderTarget& target)
{
	/*³������������ ��� ���� ��� ��� ��� ��� � ���� �����*/
	map.render(target);
	pipes.render(target);
	base.render(target);
	bird.render(target);
	target.draw(currentScore);

	/*�� ������������� ����� ���� � �������� �� ������ ������� (���� �����)*/
	if (gameOverStateOn)
		drawPauseState(target);
}
