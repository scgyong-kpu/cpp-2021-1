#pragma once
#include "MovingSprite.h"

#define PLAYER_FULL_LIFE 5

class Player : public MovingSprite
{
	int life;
	Texture texture;

public:
	Player();
	void draw(RenderWindow& win);
	void handleEvent(Event& e);
	void moveToCenter(void);
	virtual void update();
};

