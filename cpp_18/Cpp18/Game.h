#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "MovingSprite.h"
#include "Ball.h"

using namespace sf;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Dodge Game 2021"

class Game
{
public:
	Game(RenderWindow &win);
	void update(void);
	void draw(void);
	void handleEvent(Event& e);
	void generateBall(void);

	static float frameTime;
	static unsigned getRandom(int bound);

private:
	RenderWindow& win;

	Sprite spBg;
	Texture txBg;

	MovingSprite spPlayer;
	Texture txPlayer;

	std::vector<Ball> balls;
	Texture txBall;

	Clock clock;
};

