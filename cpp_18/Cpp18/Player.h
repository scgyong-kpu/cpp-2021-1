#pragma once
#include "MovingSprite.h"
class Player : public MovingSprite
{
public:
	void handleEvent(Event& e);
};

