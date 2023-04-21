#include "pch.h"
#include "PlayingState.h"

/*Підключається бібліотека для відображення очок*/
#include <sstream>

/*Конструктор, в якому проводиться ініціалізація початкових даних*/
PlayingState::PlayingState()
	: map(), pipes(), gameOn(false), gameOverStateOn(false), cScore(0), rScore(0)
{
	initUI();
}

/*Ініціалізація Юзер Інтерфейсу (текстів, шрифтів, меню з рахунком, кнопки рестарт)*/
void PlayingState::initUI()
{
	/*Підгружається шрифт
	встановлюється шрифт до тексту
	встановлюється розмір шрифту
	та позиція тексту */
	font.loadFromFile("Fonts/flappy.ttf");
	currentScore.setFont(font);
	currentScore.setCharacterSize(60);
	currentScore.setPosition(300.f - currentScore.getGlobalBounds().width / 2.f , 100.f);

	/*Інтеджер конвертується в текст для відображення зверху в грі*/
	currentPoints = std::to_string(cScore);
	currentScore.setString(currentPoints);

	/*Те саме тільки з рекордним рахунком*/
	recordScore.setFont(font);
	recordScore.setCharacterSize(60);
	recordScore.setPosition(302.f, 380.f);

	recordPoints = std::to_string(rScore);
	recordScore.setString(recordPoints);

	/*Ініціалізація боксу з рахунком, вже коли гравець програв:
	розмір, централізція для легшого позиціонування, колір,
	колір рамки, грубість рамки та позиція*/
	scoreBox.setSize(sf::Vector2f(200.f, 200.f));
	scoreBox.setOrigin((sf::Vector2f)scoreBox.getSize() / 2.f);
	scoreBox.setFillColor(sf::Color{ 222, 216, 149 });
	scoreBox.setOutlineColor(sf::Color::Black);
	scoreBox.setOutlineThickness(4.f);
	scoreBox.setPosition(sf::Vector2f(315.f, 350.f));

	/*Ініціалізація надписів на цьому ж самому меню (коли гравець програв):
	надпис SCORE та
	надпис RECORD*/
	scoreBoxCurScore.setFont(font);
	scoreBoxRecScore.setFont(font);
	scoreBoxCurScore.setFillColor(sf::Color{ 252, 120, 88 });
	scoreBoxRecScore.setFillColor(sf::Color{ 252, 120, 88 });
	scoreBoxCurScore.setCharacterSize(30);
	scoreBoxRecScore.setCharacterSize(30);
	scoreBoxCurScore.setString("SCORE");
	scoreBoxRecScore.setString("BEST");
	scoreBoxCurScore.setPosition(scoreBox.getPosition().x - 40.f, scoreBox.getPosition().y - 100.f);
	scoreBoxRecScore.setPosition(scoreBox.getPosition().x - 30.f, scoreBox.getPosition().y);

	/*Те саме, тільки для кнопки "Рестарт"*/
	restartTexture.loadFromFile("Textures/restart.png");
	restartButton.setTexture(restartTexture);
	restartButton.setScale(0.32f, 0.32f);
	restartButton.setPosition(240.f, 465.f);
}

/*Функція, яка встановлює значення чи почалась гра (чи натиснув гравець пробіл)*/
void PlayingState::isGameplayStateOn(bool X)
{
	gameOn = X;
}

/*Функція, яка повертає значення, чи програв гравець (чи пора запускати меню з рахунком)*/
const bool& PlayingState::isPauseStateOn()
{
	return gameOverStateOn;
}

/*Повертає грані кнопки рестарт для читання чи є курсор миші в границях цієї кнопки*/
const sf::FloatRect PlayingState::getRestartButtonBounds()
{
	return restartButton.getGlobalBounds();
}

/*Функція перевіряє чи не закінчилась гра (чи зіштовхнувся гравець з перешкодою: трубами або землею)
якщо так - закінчити гру (запустити меню з рахунком)*/
void PlayingState::checkCollision()
{
	if (bird.getGlobalBounds().intersects(base.getGlobalBounds()) ||
		bird.getGlobalBounds().intersects(pipes.getGlobalBoundsPipeUp()) ||
		bird.getGlobalBounds().intersects(pipes.getGlobalBoundsPipeDown()))
	{
		gameOverStateOn = true;
	}
}

/*Перевіряє чи проскочила пташка труби:
якщо так - зарахувати очко*/
void PlayingState::checkScoring()
{
	if (pipes.getPipe1PositionX() == 222.f || pipes.getPipe2PositionX() == 222.f)
	{
		++cScore;
	}
}

/*Анімація зіштовхення (викликається ця функція в класі Animation*/
void PlayingState::animateCollision()
{
	bird.animateCollision();
}

/*Запустити стан паузи(меню з рахунком після зіштовхнення)*/
void PlayingState::pushPauseState()
{
	/*Міняється позиція теперішнього рахунку:
	замість зверху по центрі в стані гри 
	воно стає в бокс під надпис "SCORE"*/
	currentScore.setPosition(302.f, 278.f);

	/*Якщо цей рахунок побив рекорд, то призначити новий рекорд*/
	if(rScore < cScore)
		rScore = cScore;
}

void PlayingState::initGameplay()
{
	/*Ініціалізація геймплею, якщо гравець перший раз натиснув пробіл.
	Якщо так, то - рухаються труби, пташка, перевіряється зіштовхнення 
	та зараховуються очки.*/
	pipes.update();
	bird.update();
	checkCollision();
	checkScoring();
}

/*Запускається рестарт (коли після програшу гравець хоче зіграти ще раз та натискає пробіл
або натискає на кнопку RESTART*/
void PlayingState::initiateRestart()
{
	/*Йде сигнал до змінної, що стан паузи/або стан кінця гри (Гейм овер) вже не правдивий*/
	gameOverStateOn = false;

	/*Анулювати рахунок*/
	cScore = 0;

	/*Та повернути відображення очок на верх*/
	currentScore.setPosition(300.f - currentScore.getGlobalBounds().width, 100.f);

	/*Повернути труби та пташку на початкове значення*/
	pipes.init();
	bird.init();
}

/*Рухати пташку (викликається ця функція з класу Bird.*/
void PlayingState::moveBird()
{
	bird.move();
}

/*Оновлювати текст.
Створюються змінні для читання тексту і відображенння його в потоці.
Читається як теперішній рахунок, так і рекордний*/
void PlayingState::updateText()
{
	std::stringstream ss;
	std::stringstream ssTwo;

	ss << cScore;
	currentScore.setString(ss.str());

	ssTwo << rScore;
	recordScore.setString(ssTwo.str());
}

/*Головна оновлююча функція в цьому класі.
  В першу чергу оновлює текст, який би стан зараз не був.
  Потім дивиться чи не закінчена часом гра (гравець зіштовхнувся з трубами або землею).

  Ні = оновлюється нижня платформа, потім перевіряє чи почалась гра? (чи натиснув гравець пробіл
  перший раз)
	Так = ініціалізувати Геймплей (розпочати гру) - оновлювати рух труб, пташки і т.д.
	Ні  = Анімація пташки в стані інтро та очікувати коли гравець натисне пробіл.
  
  Так (гра закінчена, пташка зіштовхнулась з перешкодою) = зробити анімацію програшу
  (падіння) та запустити меню з рахунком (стан паузи)*/
void PlayingState::update()
{
	updateText();

	if (!gameOverStateOn)
	{
		base.update();

		if (gameOn)
			initGameplay();

		else if (!gameOn)
		{
			bird.introStateMove();
		}
	}
	else
	{
		animateCollision();
		pushPauseState();
	}
}

/*Відмальовувати стан паузи (меню з рахунком, надпис SCORE, RECORD
кількість очків, як тимчасових, так і рекордних
та кнопку рестарт*/
void PlayingState::drawPauseState(sf::RenderTarget& target)
{
	target.draw(scoreBox);
	target.draw(scoreBoxCurScore);
	target.draw(scoreBoxRecScore);
	target.draw(recordScore);
	target.draw(currentScore);
	target.draw(restartButton);
	
}

/*Головна відмальовуюча функція*/
void PlayingState::render(sf::RenderTarget& target)
{
	/*Відмальовувати все якщо гра або йде або в стані інтро*/
	map.render(target);
	pipes.render(target);
	base.render(target);
	bird.render(target);
	target.draw(currentScore);

	/*Та відмальовувати тільки меню з рахунком та кнопки рестарт (стан паузи)*/
	if (gameOverStateOn)
		drawPauseState(target);
}
