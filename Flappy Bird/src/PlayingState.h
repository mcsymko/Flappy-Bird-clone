#pragma once

#include "GameState.h"
#include "Map.h"
#include "Base.h"
#include "Pipes.h"
#include "Bird.h"

class PlayingState :
    public GameState
{
public:
    PlayingState();

    void initGameplay();

    void checkPressedSpace();

    void moveBird();

    void update();
    void render(sf::RenderTarget& target);
    
private:
    Map map;
    Base base;
    Pipes pipes;
    Bird bird;
        
    bool gameOn;

    sf::Font font;
    sf::Text currentScore;
    int cScore;
};