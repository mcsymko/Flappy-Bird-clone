#include "pch.h"
#include "Bird.h"

/*Конструктор, який ініціалізує дані*/
Bird::Bird()
	:staticMovingSpeed(0.45f), gameON(false)
{
	introDir = IntroStateDirections::UP;
}

/*Ініціалізація пташки*/
void Bird::init()
{
	birdAnimation.init();
}

/*Повертання рамок спрайту пташки*/
const sf::FloatRect Bird::getGlobalBounds()
{
	return birdAnimation.getGlobalBounds();
}

/*Повертання позиції пташки*/
const sf::Vector2f& Bird::getBirdPosition()
{
	return birdAnimation.getBirdPosition();
}

/*Виклик функції падіння пташки*/
void Bird::birdFalling()
{
	birdAnimation.birdFalling();
}

/*Керувати напрямками*/
void Bird::manageDirections()
{
	switch (introDir)
	{
		/*Якщо напрямок "ВВЕРХ", то рухати вверх по ігрику (y)*/
	case IntroStateDirections::UP:
		birdAnimation.introBirdAnimation(0.f, -staticMovingSpeed);
		break;
		/*Аналогічно з низом*/
	case IntroStateDirections::DOWN:
		birdAnimation.introBirdAnimation(0.f, staticMovingSpeed);
		break;
	}
}

/*Реалізація руху Інтро стану*/
void Bird::introStateMove()
{
	/*В першу чергу анімація крил та 
	  керувати напрямками*/
	animateWings();
	manageDirections();

	/*І вже тоді читати позицію пташки, якщо вона досягла певної висоти то направити вниз*/
	if (birdAnimation.getBirdPosition().y < 390.f)
		introDir = IntroStateDirections::DOWN;

	/*Те саме тут, якщо пташка впала досить низько, повернути її вверх*/
	if (birdAnimation.getBirdPosition().y > 410.f)
		introDir = IntroStateDirections::UP;
}

/*Викликається функція move() класу Animation*/
void Bird::move()
{
	birdAnimation.birdMove();
}

/*Анімація руху крил*/
void Bird::animateWings()
{
	birdAnimation.animateWings();
}

/*Анімація зіштовхнення пташки*/
void Bird::animateCollision()
{
	birdAnimation.animateCollision();
}

/*Оновлення пташки*/
void Bird::update()
{
	birdFalling();
	birdAnimation.update();
}

/*Відмальовування*/
void Bird::render(sf::RenderTarget& target)
{
	birdAnimation.render(target);
}
