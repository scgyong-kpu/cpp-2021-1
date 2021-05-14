#include "Game.h"

float Game::frameTime;

Game::Game(RenderWindow& win) : win{ win }
{
	txBg.loadFromFile("res/outerspace.png");
	spBg.setTexture(txBg);

	txPlayer.loadFromFile("res/player.png");
	spPlayer.setTexture(txPlayer);

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
}

void Game::draw(void)
{
	win.draw(spBg);
	for (auto& ball : balls) {
		win.draw(ball);
	}
	win.draw(spPlayer);
}

void Game::generateBall(void)
{
	MovingSprite ball;
	ball.setTexture(txBall);
	Vector2f vector;
	vector.x = (float)(rnd_engine() % 100 + 50);
	vector.y = (float)(rnd_engine() % 100 + 20);
	ball.setVector(vector);
	balls.push_back(ball);
}
