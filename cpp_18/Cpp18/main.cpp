#include <SFML/Graphics.hpp>
#include <random>

#include "MovingSprite.h"

using namespace sf;
//using namespace std;

float frameTime;

int main(void)
{
	std::mt19937 rnd_engine;

	RenderWindow win(VideoMode(800, 600), "Game");
	Sprite spBg;
	Texture txBg;
	txBg.loadFromFile("res/outerspace.png");
	spBg.setTexture(txBg);

	MovingSprite spPlayer;
	Texture txPlayer;
	txPlayer.loadFromFile("res/player.png");
	spPlayer.setTexture(txPlayer);

	//Sprite spBall;
	std::vector<MovingSprite> balls;
	Texture txBall;
	txBall.loadFromFile("res/missile.png");

	const int playerSpeed = 300;

	Clock clock;

	while (win.isOpen()) {
		Event e;
		while (win.pollEvent(e)) {
			if (e.type == Event::Closed) {
				win.close();
				break;
			}
			if (e.type == Event::KeyPressed) {
				//if (e.key.code == Keyboard::Left) {
				//	if (playerVector.x >= 0) playerVector.x -= playerSpeed;
				//} else if (e.key.code == Keyboard::Right) {
				//	if (playerVector.x <= 0) playerVector.x += playerSpeed;
				//}
				if (e.key.code == Keyboard::Escape) {
					win.close();
					break;
				}
				if (e.key.code == Keyboard::Space) {
					MovingSprite ball;
					ball.setTexture(txBall);
					Vector2f vector;
					vector.x = (float)(rnd_engine() % 100 + 50);
					vector.y = (float)(rnd_engine() % 100 + 20);
					ball.setVector(vector);
					balls.push_back(ball);
					//spBall.setPosition(0, 0);
				}
			} else if (e.type == Event::KeyReleased) {
				//if (e.key.code == Keyboard::Left) {
				//	if (playerVector.x <= 0) playerVector.x += playerSpeed;
				//} else if (e.key.code == Keyboard::Right) {
				//	if (playerVector.x >= 0) playerVector.x -= playerSpeed;
				//}
			}
		}

		Time diff = clock.restart();
		frameTime = diff.asSeconds();

		spPlayer.update();

		for (auto &ball: balls) {
			ball.update();
		}

		win.draw(spBg);
		for (auto &ball : balls) {
			win.draw(ball);
		}
		win.draw(spPlayer);
		win.display();
	}
	return 0;
}
