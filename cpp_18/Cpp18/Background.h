#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player;

class Background: public Sprite
{
public:
	Background();
	void update();
	//void draw(RenderWindow& win);
	void setPlayer(Player& player);

protected:
	Player* player;
	Texture txOuterspace;
};

