#pragma once
#include "MovingSprite.h"
class Ball : public MovingSprite
{
public:
	Ball(Texture &texture, bool randomSized = true);
	bool isOutOfScreen(void);
};

