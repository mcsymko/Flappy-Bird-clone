#include "PlayingState.h"

PlayingState::PlayingState()
	: map(), pipes()
{

}

void PlayingState::update()
{
	map.update();
	
}

void PlayingState::render(sf::RenderTarget& target)
{
	map.render(target);
}
