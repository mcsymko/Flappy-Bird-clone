#pragma once

/*Підключаємо інші класи, які беруть участь у грі*/
#include "Map.h"
#include "Base.h"
#include "Pipes.h"
#include "Bird.h"

class PlayingState
{
public:
    /*Конструктор*/
    PlayingState();

    /*Ініціалізація текстів, вікна, кнопки (Юзер Інтерфейс)*/
    void initUI();

    /*Функція, яка читає чи гра активна, чи ще в стані інтро*/
    void isGameplayStateOn(bool X);

    /*Функція, яка повертає значення
    і дає знати чи стоїть зараз гра на паузі (вікно з очками)*/
    const bool& isPauseStateOn();

    /*Функція, яка повертає грані кнопки рестарт*/
    const sf::FloatRect getRestartButtonBounds();

    /*Функції, які дивляться чи не відбулося зіштовхнення пташки з трубами
      І функція, яка читає чи не набрала пташка очко*/
    void checkCollision();
    void checkScoring();

    /*Функція, яка виконує анімацію зіштовхнення 
    та Функція, яка запускає стан паузи (вікно з результатом)*/
    void animateCollision();
    void pushPauseState();

    /*Функції які ініціалізують геймплей та рестарт*/
    void initGameplay();
    void initiateRestart();

    /*Рухати пташку*/
    void moveBird();

    /*Оновлювати текст та головна оновлююча функція*/
    void updateText();
    void update();

    /*Малюючі функції, в стані паузи та головна*/
    void drawPauseState(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
    
private:
    /*Створюються об'єкти гри*/
    Map map;
    Base base;
    Pipes pipes;
    Bird bird;
     
    /*Бул змінні,які зберігають значення:
    чи почалась гра
    чи пора запускати стан паузи*/
    bool gameOn;
    bool gameOverStateOn;

    /*Відображення очок, як тимчасових*/
    sf::Font font;
    sf::Text currentScore;
    std::string currentPoints;
    int cScore;

    /*Так і рекордних*/
    sf::Text recordScore;
    std::string recordPoints;
    int rScore;

    /*Відображення вікна з результатом набраних очок*/
    sf::RectangleShape scoreBox;
    sf::Text scoreBoxCurScore, scoreBoxRecScore;

    /*Та кнопки рестарт*/
    sf::Texture restartTexture;
    sf::Sprite restartButton;
};