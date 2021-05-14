#include <SFML/Graphics.hpp>
#include <random>

#include "Game.h"

using namespace sf;
//using namespace std;

//float frameTime;

int main(void)
{
	RenderWindow win(VideoMode(800, 600), "Game");
	Game game(win);

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
					game.generateBall();
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

		game.update();

		game.draw();
		win.display();
	}
	return 0;
}
