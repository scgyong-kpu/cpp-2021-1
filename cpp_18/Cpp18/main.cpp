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

	Vector2f playerVector;

	while (win.isOpen()) {
		Event e;
		while (win.pollEvent(e)) {
			if (e.type == Event::Closed) {
				win.close();
				break;
			}
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Left) {
					playerVector.x = -0.1;
				} else if (e.key.code == Keyboard::Right) {
					playerVector.x = 0.1;
				}
			} else if (e.type == Event::KeyReleased) {
				playerVector.x = 0;
			}
		}

		spPlayer.move(playerVector);

		win.draw(spBg);
		win.draw(spPlayer);
		win.display();
	}
	return 0;
}
