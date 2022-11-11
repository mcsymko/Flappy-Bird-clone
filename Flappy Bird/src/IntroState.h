#pragma once
#include "GameState.h"
#include "Map.h"

class IntroState :
    public GameState
{
public:
    IntroState();

    void update();
    void render(sf::RenderTarget& target);

private:
    Map map;
};

