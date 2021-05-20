#include "Ball.h"
#include "Game.h"

Ball::Ball(Texture& texture)
{
	setTexture(texture);
	Vector2u size = texture.getSize();
	Vector2f pos;
	pos.x = (float)(Game::getRandom(WINDOW_WIDTH) - size.x / 2);
	pos.y = (float)(Game::getRandom(WINDOW_HEIGHT) - size.y / 2);
	setPosition(pos);

	vector.x = (float)(Game::getRandom(100) + 50);
	vector.y = (float)(Game::getRandom(100) + 20);
}

bool Ball::isOutOfScreen(void)
{
	const Vector2f& pos = getPosition();
	if (pos.x > WINDOW_WIDTH) {
		return true;
	}
	if (pos.y > WINDOW_HEIGHT) {
		return true;
	}

	Vector2u size = getTexture()->getSize();
	if (pos.x < -(int)size.x) {
		return true;
	}
	if (pos.y < -(int)size.y) {
		return true;
	}

	return false;
}
