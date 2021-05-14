#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "MovingSprite.h"

using namespace sf;

class Game
{
public:
	Game();
	void update(void);
	void draw(RenderWindow& win);
	void generateBall();

	static float frameTime;

private:
	Sprite spBg;
	Texture txBg;

	MovingSprite spPlayer;
	Texture txPlayer;

	std::vector<MovingSprite> balls;
	Texture txBall;

	Clock clock;
	std::mt19937 rnd_engine;
};

