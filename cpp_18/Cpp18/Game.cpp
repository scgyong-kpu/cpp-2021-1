#include "Game.h"

#define INITIAL_MAX_BALL_COUNT 10
#define MAX_ITEM_COUNT 3u

float Game::frameTime;

Game::Game(RenderWindow& win) 
	: win{ win }, scoreValue { 0 }
{
	background.setPlayer(spPlayer);

	txBall.loadFromFile("res/missile.png");
	txItem.loadFromFile("res/item.png");

	txGameOver.loadFromFile("res/game_over.png");
	spGameOver.setTexture(txGameOver);
	Vector2u size = txGameOver.getSize();
	spGameOver.setPosition(
		(WINDOW_WIDTH - size.x) / 2.0f,
		(WINDOW_HEIGHT - size.y) / 2.0f
	);

	scoreFont.loadFromFile("res/lucon.ttf");
	scoreText.setString("Hello world");
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(35);
	scoreText.setStyle(Text::Bold);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20.0f, 20.0f);

	//maxBallCount = INITIAL_MAX_BALL_COUNT;

	//spBg.move(-500, 0);

	inPlay = true;
}

void Game::update(void)
{
	Time diff = clock.restart();
	frameTime = diff.asSeconds();

	if (!inPlay) {
		return;
	}

	scoreValue += frameTime;
	updateScore();

	spPlayer.update();
	background.update();

	for (auto& ball : balls) {
		ball.update();
	}
	for (auto& item : items) {
		item.update();
	}

	for (auto it = balls.begin(); it != balls.end(); it++) {
		Ball &ball = *it;
		if (ball.isOutOfScreen()) {
			balls.erase(it);
			printf("[-]Ball count = %d\n", balls.size());
			break;
		}
		if (spPlayer.collides(ball)) {
			printf("[Collision !!!] %d\n", balls.size());
			balls.erase(it);
			bool alive = spPlayer.decreaseLife();
			if (!alive) {
				inPlay = false;
				highscore.add(scoreValue);
				printf("Dead.\n");
			}
			break;
		}
	}

	for (auto it = items.begin(); it != items.end(); it++) {
		Ball& item = *it;
		if (item.isOutOfScreen()) {
			items.erase(it);
			break;
		}
		if (spPlayer.collides(item)) {
			printf("[Collision !!!] %d\n", items.size());
			items.erase(it);
			bool increased = spPlayer.increaseLife();
			if (!increased) {
				scoreValue += 5.0f;
				updateScore();
			}
			break;
		}
	}

	unsigned maxBallCout = INITIAL_MAX_BALL_COUNT + (int)(scoreValue / 10);
	if (balls.size() < maxBallCout) {
		generateBall();
	}
	if (items.size() < MAX_ITEM_COUNT) {
		generateItem();
	}
}

void Game::draw(void)
{
	//win.draw(background);
	background.draw(win);

	for (auto& ball : balls) {
		win.draw(ball);
	}
	for (auto& item : items) {
		win.draw(item);
	}
	spPlayer.draw(win);

	if (!inPlay) {
		win.draw(spGameOver);
		//draw gameover sprite

		win.draw(highscore);
		//highscore.draw(win);
	}
	win.draw(scoreText);
}

void Game::handleEvent(Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Enter) {
			if (!inPlay) {
				startGame();
			}
		}
	}


	spPlayer.handleEvent(e);
}

void Game::startGame(void)
{
	balls.clear();
	items.clear();
	spPlayer.reset();
	scoreValue = 0.0f;
	inPlay = true;
}

void Game::generateBall(void)
{
	float rate = 1.0f + scoreValue / 60.0f;
	Ball ball(txBall, rate, true);
	balls.push_back(ball);
	printf("[+]Ball count = %d\n", balls.size());
}

void Game::generateItem(void)
{
	Ball item(txItem, 1.0f, false);
	items.push_back(item);
}

void Game::updateScore(void)
{
	char buff[30];
	sprintf(buff, "Score: %.1f", scoreValue);
	scoreText.setString(buff);
}

static std::mt19937 rnd_engine;

unsigned Game::getRandom(int bound)
{
	return rnd_engine() % bound;
}

float Game::getRandom(void)
{
	return rnd_engine() % 1000000 / 1000000.0f;
}
