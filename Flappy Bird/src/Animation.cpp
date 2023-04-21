#include "pch.h"
#include "Animation.h"

Animation::Animation()
	:numberOfTexture(0), downwardsRotation(0.f), birdFallingSpeed(0.f)
{
	/*Підгрузка текстур локально з папки*/
	birdTextures[0].loadFromFile("Textures/flappy1.png");
	birdTextures[1].loadFromFile("Textures/flappy2.png");
	birdTextures[2].loadFromFile("Textures/flappy3.png");

	/*Встановлюються розміри пташки,
	  її центр
	  та початкова текстура*/
	bird.setScale(2.f, 2.f);
	bird.setOrigin((sf::Vector2f)birdTextures[1].getSize() / 2.f);
	bird.setTexture(birdTextures[0]);

	/*Ініціалізація додаткових даних*/
	init();
}

void Animation::init()
{
	/*Позиція
	  Текстура
	  Ротація
	  Швидкість падіння*/
	bird.setPosition(250.f, 400.f);
	numberOfTexture = 0;
	downwardsRotation = 0.f;
	birdFallingSpeed = 0.f;
}

/*Функція, яка повертає позицію пташки*/
const sf::Vector2f& Animation::getBirdPosition()
{
	return bird.getPosition();
}

/*Її рамки для перевірки чи не відбулось зіштовхнення*/
const sf::FloatRect Animation::getGlobalBounds()
{
	return bird.getGlobalBounds();
}

/*Переміщення пташки у стані Інтро за заданими даним*/
void Animation::introBirdAnimation(float x, float y)
{
	bird.move(x, y);
}

/*Переміщення пташки в стані гри*/
void Animation::birdMove()
{
	birdFallingSpeed = -5.f;
	downwardsRotation = -40.f;
}

/*Падіння пташки*/
void Animation::birdFalling()
{
	/*Для плавного відображення використовується таймер по закінченню якого
	буде відбуватися певна дія, по закінченню якої таймер анульовуватиметься*/
	if (timerOne.getElapsedTime().asSeconds() > 0.006f)
	{
		/*Якщо пташка набрала кінцевої швидкості, то зберігати її*/
		if (birdFallingSpeed > 4.f)
			birdFallingSpeed = 4.f;

		/*Якщо пташка повернулась головою вниз при падінні, не розвертати її надалі*/
		if (downwardsRotation > 90.f)
		{
			/*Та зупинити анімацію крил*/
			bird.setTexture(birdTextures[1]);
			downwardsRotation = 90.f;
		}

		/*Якщо ротація пташки (голова 0 градусів або менше, то помаленько повертати її вниз*/
		else if (downwardsRotation <= 0.f)
		{
			downwardsRotation += 0.5f;
		}

		/*Якщо більше ніж 0 але менше ніж 90, то повертати швидше і не 
		анімувати крила*/
		else
		{
			bird.setTexture(birdTextures[1]);
			downwardsRotation += 2.f;
		}

		/*Пришвидшувати падіння з кожним кадром*/
		birdFallingSpeed += 0.14f;

		/*Рухати пташку по заданій швидкості
		та повертати голову по заданих даних*/
		bird.move(0.f, birdFallingSpeed);
		bird.setRotation(downwardsRotation);

		/*Рестарт таймеру в кінці кадру*/
		timerOne.restart();
	}
}

/*Анімація крил*/
void Animation::animateWings()
{
	/*Те саме по таймеру*/
	if (timerTwo.getElapsedTime().asSeconds() > 0.1f)
	{
		/*Якщо наступний номер текстури більший ніж 2 
		то присвоїти номер текстури до нуля. Це для того, щоб
		брались текстури 0, 1, 2, 0, 1, 2 і т.д.*/
		if (++numberOfTexture > 2)
		{
			numberOfTexture = 0;
		}
		/*Встановлюється текстура по значенню*/
		bird.setTexture(birdTextures[numberOfTexture]);
		
		/*Та рестартиться таймер*/
		timerTwo.restart();
	}
}

/*Суть цієї функції в тому, що при зіштовхненні з перешкодою
 пташка швидко падає на землю і застрягає в землі*/

/*Тут майже все те саме, що і в функції birdFalling() окрім:
1)Перевірки чи пташка знаходиться вище землі та 
2)Швидшого падіння*/
void Animation::animateCollision()
{
	/*Якщо пташка вище землі*/
	if (bird.getPosition().y < 670.f)
	{
		if (timerOne.getElapsedTime().asSeconds() > 0.005f)
		{
			if (birdFallingSpeed > 6.f)
				birdFallingSpeed = 6.f;

			if (downwardsRotation > 90.f)
			{
				bird.setTexture(birdTextures[1]);
				downwardsRotation = 90.f;
			}
			else
			{
				bird.setTexture(birdTextures[1]);
				downwardsRotation += 4.f;
			}

			birdFallingSpeed += 0.3f;

			bird.move(0.f, birdFallingSpeed);

			bird.setRotation(downwardsRotation);

			timerOne.restart();
		}
	}
}

/*Головна функція оновлення, в якій викликається анімація крил*/
void Animation::update()
{
	animateWings();
}

/*Функція відмальовування*/
void Animation::render(sf::RenderTarget& target)
{
	target.draw(bird);
}
