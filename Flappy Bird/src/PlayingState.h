#pragma once

#include "GameState.h"
#include "Map.h"
#include "Base.h"
#include "Pipes.h"

class PlayingState :
    public GameState
{
public:
    PlayingState();

    void initGameplay();

    void checkPressedSpace();

    void update();
    void render(sf::RenderTarget& target);
    
private:
    Map map;
    Base base;
    Pipes pipes;
        
    bool gameOn;
};

