#include "Game.h"

int main(void)
{
	RenderWindow win(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
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
