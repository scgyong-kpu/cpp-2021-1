#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player;

class Background: public Sprite
{
public:
	Background();
	void update();
	void setPlayer(Player& player);
	void draw(RenderWindow& win);

protected:
	Player* player;
	Texture txOuterspace;

	Sprite spStars;
	Texture txStars;
};

