#include "Ball.h"

void MovingSprite::setVector(const Vector2f &vector)
{
	this->vector = vector;
}

const Vector2f& MovingSprite::getVector()
{
	return vector;
}
