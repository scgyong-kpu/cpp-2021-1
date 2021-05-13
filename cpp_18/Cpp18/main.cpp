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

	while (win.isOpen()) {
		Event e;
		while (win.pollEvent(e)) {
			if (e.type == Event::Closed) {
				win.close();
				break;
			}
		}
		win.draw(spBg);
		win.display();
	}
	return 0;
}
