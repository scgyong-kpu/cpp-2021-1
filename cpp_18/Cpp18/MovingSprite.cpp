#include "MovingSprite.h"
#include "Game.h"

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
	float dx = vector.x * Game::frameTime;
	float dy = vector.y * Game::frameTime;
	move(dx, dy);
}

bool MovingSprite::collides(MovingSprite& sprite)
{
	return false;
}
