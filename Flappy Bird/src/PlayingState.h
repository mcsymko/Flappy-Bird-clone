#pragma once

/*ϳ�������� ���� �����, �� ������ ������ � ��*/
#include "Map.h"
#include "Base.h"
#include "Pipes.h"
#include "Bird.h"

class PlayingState
{
public:
    /*�����������*/
    PlayingState();

    /*����������� ������, ����, ������ (���� ���������)*/
    void initUI();

    /*�������, ��� ���� �� ��� �������, �� �� � ���� �����*/
    void isGameplayStateOn(bool X);

    /*�������, ��� ������� ��������
    � �� ����� �� ����� ����� ��� �� ���� (���� � ������)*/
    const bool& isPauseStateOn();

    /*�������, ��� ������� ���� ������ �������*/
    const sf::FloatRect getRestartButtonBounds();

    /*�������, �� ��������� �� �� �������� ����������� ������ � �������
      � �������, ��� ���� �� �� ������� ������ ����*/
    void checkCollision();
    void checkScoring();

    /*�������, ��� ������ ������� ����������� 
    �� �������, ��� ������� ���� ����� (���� � �����������)*/
    void animateCollision();
    void pushPauseState();

    /*������� �� ����������� �������� �� �������*/
    void initGameplay();
    void initiateRestart();

    /*������ ������*/
    void moveBird();

    /*���������� ����� �� ������� ��������� �������*/
    void updateText();
    void update();

    /*������� �������, � ���� ����� �� �������*/
    void drawPauseState(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
    
private:
    /*����������� ��'���� ���*/
    Map map;
    Base base;
    Pipes pipes;
    Bird bird;
     
    /*��� ����,�� ��������� ��������:
    �� �������� ���
    �� ���� ��������� ���� �����*/
    bool gameOn;
    bool gameOverStateOn;

    /*³���������� ����, �� ����������*/
    sf::Font font;
    sf::Text currentScore;
    std::string currentPoints;
    int cScore;

    /*��� � ���������*/
    sf::Text recordScore;
    std::string recordPoints;
    int rScore;

    /*³���������� ���� � ����������� �������� ����*/
    sf::RectangleShape scoreBox;
    sf::Text scoreBoxCurScore, scoreBoxRecScore;

    /*�� ������ �������*/
    sf::Texture restartTexture;
    sf::Sprite restartButton;
};