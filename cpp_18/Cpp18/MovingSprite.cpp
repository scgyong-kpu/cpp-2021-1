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
	// box
	// distance
	Vector2f myCenter = getPosition();
	myCenter.x += size.x / 2;
	myCenter.y += size.y / 2;
	float myRadius = size.x / 2.0f;

	Vector2f otherCenter = sprite.getPosition();
	Vector2u otherSize = sprite.size;
	otherCenter.x += otherSize.x / 2;
	otherCenter.y += otherSize.y / 2;
	float otherRadius = otherSize.x / 2.0f;

	float dx = myCenter.x - otherCenter.x;
	float dy = myCenter.y - otherCenter.y;
	double dist_sq = (double)dx * dx + (double)dy * dy;
	double radius_sum = (double)myRadius + otherRadius;
	if (sqrt(dist_sq) < radius_sum) {
		return true;
	}

	return false;
}

void MovingSprite::setTexture(const Texture& texture)
{
	Sprite::setTexture(texture);
	size = texture.getSize();
}
