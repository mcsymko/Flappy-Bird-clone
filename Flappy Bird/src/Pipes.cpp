#include "pch.h"
#include "Pipes.h"

Pipes::Pipes()
	:movingSpeed(2.f), horizontalDistanceBetweenPipes(350.f), verticalDistanceBetweenPipes(670.f)
{
	/*Підгружаємо текстури з папки*/
	texturePipeUp.loadFromFile("Textures/pipeU.png");
	texturePipeDown.loadFromFile("Textures/pipeD.png");

	/*Ініціалізуємо початкові значення*/
	init();
}

/*Повертаємо глобальні рамки нижніх труб*/
const sf::FloatRect Pipes::getGlobalBoundsPipeUp()
{
	for (int i = 0; i < 2; i++)
	{
		return pipeUp[i].getGlobalBounds();
	}
}

/*Та верхніх труб*/
const sf::FloatRect Pipes::getGlobalBoundsPipeDown()
{
	for (int i = 0; i < 2; i++)
	{
		return pipeDown[i].getGlobalBounds();
	}
}

/*Повертаємо позицію труби по іксу для перевірки зарахування очка*/
const float& Pipes::getPipe1PositionX()
{
	return pipeDown[0].getPosition().x;
}

/*Те саме тільки з наступною трубою, третю не перевіряємо, бо маємо тільки дві*/
const float& Pipes::getPipe2PositionX()
{
	return pipeDown[1].getPosition().x;
}

/*Стартова ініціалізація труб*/
void Pipes::init()
{
	/*Встановлюємо текстури для труб та їх розміри*/
	for (int i = 0; i < 2; i++)
	{
		pipeUp[i].setTexture(texturePipeUp);
		pipeDown[i].setTexture(texturePipeDown);

		pipeUp[i].setScale(1.8f, 1.5f);	
		pipeDown[i].setScale(1.8f, 1.5f);
	}
	calculateRandomPosition();

	pipeUp[0].setPosition(1000.f, 800.f - pipeUp->getGlobalBounds().height + randomPosition);
	pipeDown[0].setPosition(1000.f, pipeUp[0].getPosition().y - verticalDistanceBetweenPipes);

	calculateRandomPosition();

	pipeUp[1].setPosition(pipeUp[0].getPosition().x + horizontalDistanceBetweenPipes, 800.f - pipeUp->getGlobalBounds().height + randomPosition);
	pipeDown[1].setPosition(pipeDown[0].getPosition().x + horizontalDistanceBetweenPipes, pipeUp[1].getPosition().y - verticalDistanceBetweenPipes);

}

/*Замість того, щоб створювати 1000 труб і рухати їх всіх ми створили лише дві
  (дві верхніх та дві нижніх) для оптимізації гри.
  Якщо труба буде заходити за ліву межу вікна, вона буде респавнитись за правою, що надасть вигляд
  тих самих 1000 труб.*/


/*Тут ми обчислюємо випадкову позицію труби (знизу вверх чи вона буде високою, низькою,
по центру і т.д. верхня труба підлаштовуватиметься. Див. наступну функцію*/
void Pipes::calculateRandomPosition()
{
	randomPosition = rand() % 380 - 100;
}

/*Ця функція перевіряє чи не пора робити респавн труби*/
void Pipes::checkRespawn()
{
	/*Переглядаються обидві труби в масиві*/
	for (int i = 0; i < 2; i++)
	{
		/*Якщо труба повністю виходить за ліву сторону вікна 
		(додається її ширина) щоб повністю вийшла*/
		if (pipeUp[i].getPosition().x + pipeUp[i].getGlobalBounds().width < 0.f)
		{
			/*То обчислюється випадкова позиція нижньої труби (яка дивиться вверх)*/
			calculateRandomPosition();

			/*І встановлюється її позиція згідно цього випадкового значення*/
			pipeUp[i].setPosition(600.f, 800.f - pipeUp->getGlobalBounds().height + randomPosition);

			/*Верхня труба (яка дивиться вниз) підлаштовується по змінній verticalDistanceBetweenPipes*/
			pipeDown[i].setPosition(600.f, pipeUp[i].getPosition().y - verticalDistanceBetweenPipes);
		}
	}
}

/*Рухаємо труби по заданій швидкості та перевіряємо чи не вийшла труба за рамки вікна,
  якщо так = зареспавнити її*/
void Pipes::move()
{
	for (int i = 0; i < 2; i++)
	{
		pipeUp[i].setPosition(pipeUp[i].getPosition().x - movingSpeed, pipeUp[i].getPosition().y);
		pipeDown[i].setPosition(pipeDown[i].getPosition().x - movingSpeed, pipeDown[i].getPosition().y);

		checkRespawn();
	}
}

/*Оновлюємо труби*/
void Pipes::update()
{
	move();
}

/*Відмальовуємо труби*/
void Pipes::render(sf::RenderTarget& target)
{
	for (int i = 0; i < 2; i++)
	{
		target.draw(pipeUp[i]);
		target.draw(pipeDown[i]);
	}
}
