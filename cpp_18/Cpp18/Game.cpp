#include "Game.h"

#define MAX_BALL_COUNT 10

float Game::frameTime;

Game::Game(RenderWindow& win) : win{ win }
{
	txBg.loadFromFile("res/outerspace.png");
	spBg.setTexture(txBg);

	txBall.loadFromFile("res/missile.png");
}

void Game::update(void)
{
	Time diff = clock.restart();
	frameTime = diff.asSeconds();

	spPlayer.update();

	for (auto& ball : balls) {
		ball.update();
	}

	for (auto it = balls.begin(); it != balls.end(); it++) {
		Ball &ball = *it;
		if (ball.isOutOfScreen()) {
			balls.erase(it);
			printf("[-]Ball count = %d\n", balls.size());
			break;
		}
		if (spPlayer.collides(ball)) {
			balls.erase(it);
			printf("[Collision !!!] %d\n", balls.size());
			break;
		}
	}

	if (balls.size() < MAX_BALL_COUNT) {
		generateBall();
	}
}

void Game::draw(void)
{
	win.draw(spBg);
	for (auto& ball : balls) {
		win.draw(ball);
	}
	spPlayer.draw(win);
	//win.draw(spPlayer);
}

void Game::handleEvent(Event& e)
{
	//if (e.type == Event::KeyPressed) {
	//	if (e.key.code == Keyboard::Space) {
	//		generateBall();
	//	}
	//}

	spPlayer.handleEvent(e);
}

void Game::generateBall(void)
{
	Ball ball(txBall);
	balls.push_back(ball);
	printf("[+]Ball count = %d\n", balls.size());
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
