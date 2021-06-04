#pragma once
#pragma warning(disable: 4996)

#include <SFML/Graphics.hpp>
#include <random>
#include "MovingSprite.h"
#include "Ball.h"
#include "Player.h"
#include "Highscore.h"
#include "Background.h"

using namespace sf;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Dodge Game 2021"

enum GameState {
	GameState_Ready,
	GameState_InPlay,
	GameSatet_GameOver
};

enum GameLevel {
	Level_Easy,
	Level_Medium,
	Level_Hard,
	Level_Insane,
	Level_Count
};

class Game
{
public:
	Game(RenderWindow &win);
	void update(void);
	void draw(void);
	void handleEvent(Event& e);

	static float frameTime;
	static unsigned getRandom(int bound);
	static float getRandom(void);

private:
	void startGame(void);
	void readyGame(void);
	void generateBall(void);
	void generateItem(void);
	void updateScore(void);
	void updateLevelString(void);
	RenderWindow& win;

	Highscore highscore;

	Background background;

	Player spPlayer;
	GameState gameState;

	std::vector<Ball> balls;
	Texture txBall;

	std::vector<Ball> items;
	Texture txItem;

	Sprite spGameOver;
	Texture txGameOver;

	//int maxBallCount;
	float scoreValue;
	Font scoreFont;
	Text scoreText;

	GameLevel level;

	Clock clock;
};

