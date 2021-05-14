#include "MovingSprite.h"

void MovingSprite::setVector(const Vector2f &vector)
{
	this->vector = vector;
}

const Vector2f& MovingSprite::getVector()
{
	return vector;
}

extern float frameTime;

void MovingSprite::update()
{
	float dx = vector.x * frameTime;
	float dy = vector.y * frameTime;
	move(dx, dy);
}
