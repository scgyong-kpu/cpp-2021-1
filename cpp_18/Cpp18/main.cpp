#include <SFML/Graphics.hpp>

using namespace sf;
//using namespace std;

int main(void)
{
	RenderWindow win(VideoMode(800, 600), "Game");
	Sprite spBg;
	Texture txBg;
	txBg.loadFromFile("res/outerspace.png");
	spBg.setTexture(txBg);

	Sprite spPlayer;
	Texture txPlayer;
	txPlayer.loadFromFile("res/player.png");
	spPlayer.setTexture(txPlayer);

	//Sprite spBall;
	std::vector<Sprite> balls;
	Texture txBall;
	txBall.loadFromFile("res/missile.png");
	//spBall.setTexture(txBall);
	Vector2f ballVector(120, 100);

	Vector2f playerVector;
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
				if (e.key.code == Keyboard::Left) {
					if (playerVector.x >= 0) playerVector.x -= playerSpeed;
				} else if (e.key.code == Keyboard::Right) {
					if (playerVector.x <= 0) playerVector.x += playerSpeed;
				}
				if (e.key.code == Keyboard::Escape) {
					win.close();
					break;
				}
				if (e.key.code == Keyboard::Space) {
					Sprite ball;
					ball.setTexture(txBall);
					balls.push_back(ball);
					//spBall.setPosition(0, 0);
				}
			} else if (e.type == Event::KeyReleased) {
				if (e.key.code == Keyboard::Left) {
					if (playerVector.x <= 0) playerVector.x += playerSpeed;
				} else if (e.key.code == Keyboard::Right) {
					if (playerVector.x >= 0) playerVector.x -= playerSpeed;
				}
			}
		}

		Time diff = clock.restart();
		float frameTime = diff.asSeconds();

		{
			float dx = playerVector.x * frameTime;
			float dy = playerVector.y * frameTime;
			spPlayer.move(dx, dy);
		}

		for (auto &ball: balls)
		{
			float dx = ballVector.x * frameTime;
			float dy = ballVector.y * frameTime;
			ball.move(dx, dy);
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
