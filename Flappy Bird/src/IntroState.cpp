#include "pch.h"
#include "IntroState.h"

IntroState::IntroState()
	:map()
{

}

void IntroState::update()
{
	map.update();
}

void IntroState::render(sf::RenderTarget& target)
{
	map.render(target);
}

