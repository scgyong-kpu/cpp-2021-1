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
				if (e.key.code == Keyboard::Escape) {
					win.close();
					break;
				}
			}
			game.handleEvent(e);
		}

		game.update();

		game.draw();
		win.display();
	}
	return 0;
}
