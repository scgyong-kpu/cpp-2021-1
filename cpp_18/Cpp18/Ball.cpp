#include "Ball.h"

void Ball::setVector(const Vector2f &vector)
{
	this->vector = vector;
}

const Vector2f& Ball::getVector()
{
	return vector;
}
