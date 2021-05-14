#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "MovingSprite.h"

using namespace sf;

class Game
{
public:
	Game(RenderWindow &win);
	void update(void);
	void draw(void);
	void handleEvent(Event& e);
	void generateBall(void);

	static float frameTime;

private:
	RenderWindow& win;

	Sprite spBg;
	Texture txBg;

	MovingSprite spPlayer;
	Texture txPlayer;

	std::vector<MovingSprite> balls;
	Texture txBall;

	Clock clock;
	std::mt19937 rnd_engine;
};

