#pragma once

#include "GameState.h"
#include "Map.h"
#include "Pipes.h"

class PlayingState :
    public GameState
{
public:
    PlayingState();

    void update();
    void render(sf::RenderTarget& target);
    
private:
    Map map;
    Pipes pipes;
};

