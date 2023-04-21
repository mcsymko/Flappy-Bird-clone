#include "pch.h"
#include "Base.h"

Base::Base()
	:movingSpeed(2.f)
{
	/*Завантажується текстура з папки
	  Встановлюється текстура до спрайту
	  та встановлюється розмір спрайту*/
	baseTexture.loadFromFile("Textures/base.png");
	mBase.setTexture(baseTexture);
	mBase.setScale(2.f, 1.f);
}

/*Повертаємо глобальні рамки*/
const sf::FloatRect Base::getGlobalBounds()
{
	return mBase.getGlobalBounds();
}

/*Рухаємо платформу*/
void Base::move()
{
	/*Щоб не робити супердовгу платформу, ми переміщуватемо її за праву сторону вікна
	  як тільки вона пройде якусь відстань по іксу (x)*/
	if (mBase.getPosition().x + mBase.getGlobalBounds().width < 600)
		mBase.setPosition(sf::Vector2f(-26.f, 700.f));

	/*Рухати платформу по іксу по заданій швидкості*/
	mBase.setPosition(sf::Vector2f(mBase.getPosition().x - movingSpeed, 700.f));
}

/*Оновлююча функція*/
void Base::update()
{
	move();
}

/*Відмальовуюча функція*/
void Base::render(sf::RenderTarget& target)
{
	target.draw(mBase);
}
