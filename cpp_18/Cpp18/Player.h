#pragma once
#include "MovingSprite.h"

#define PLAYER_FULL_LIFE 5

class Player : public MovingSprite
{
	int life;
	Texture texture;
	Texture redHeartTexture, whiteHeartTexture;
	Sprite hearts[PLAYER_FULL_LIFE];

public:
	Player();
	void draw(RenderWindow& win);
	void handleEvent(Event& e);
	void moveToCenter(void);
	virtual void update();
	bool decreaseLife();

private:
	void updateHearts();
};

