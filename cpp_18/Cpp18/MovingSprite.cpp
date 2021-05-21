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
	Vector2f myCenter = getCenter();
	float myRadius = getRadius();

	Vector2f otherCenter = sprite.getCenter();
	float otherRadius = sprite.getRadius();

	float dx = myCenter.x - otherCenter.x;
	float dy = myCenter.y - otherCenter.y;
	double dist_sq = (double)dx * dx + (double)dy * dy;
	double radius_sum = (double)myRadius + otherRadius;
	if (dist_sq < (radius_sum * radius_sum)) {
		return true;
	}

	return false;
}

void MovingSprite::setTexture(const Texture& texture)
{
	Sprite::setTexture(texture);
	size = texture.getSize();
}

Vector2f MovingSprite::getCenter()
{
	Vector2f myCenter = getPosition();
	myCenter.x += size.x / 2;
	myCenter.y += size.y / 2;
	return myCenter;
}

float MovingSprite::getRadius()
{
	return size.x / 2.f;
}
