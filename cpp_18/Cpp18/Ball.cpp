#include "Ball.h"
#include "Game.h"

#define _USE_MATH_DEFINES
#include <math.h>
const double pi = M_PI;

Ball::Ball(Texture& texture, bool randomSized)
{
	setTexture(texture);
	//Vector2u size = texture.getSize();
	if (randomSized) {
		float scale = Game::getRandom() * 0.5f + 0.5f;
		setScale(scale, scale);
		size.x = (unsigned)(size.x * scale);
		size.y = (unsigned)(size.y * scale);
	}

	Vector2f pos;
	pos.x = (float)(Game::getRandom(WINDOW_WIDTH) - size.x / 2);
	pos.y = (float)(Game::getRandom(WINDOW_HEIGHT) - size.y / 2);

	//const double pi = atan(1) * 4;
	double angle = (double)Game::getRandom() * 2 * pi;
	int speed = Game::getRandom(100) + 100;
	vector.x = (float)(speed * cos(angle));
	vector.y = (float)(speed * sin(angle));

	int side = Game::getRandom(4);
	switch (side) {
	case 0:
		pos.x = 0;
		if (vector.x < 0) vector.x = -vector.x;
		break;
	case 1:
		pos.y = 0;
		if (vector.y < 0) vector.y = -vector.y;
		break;
	case 2:
		pos.x = WINDOW_WIDTH - size.x / 2.f;
		if (vector.x > 0) vector.x = -vector.x;
		break;
	case 3: 
		pos.y = WINDOW_HEIGHT - size.y / 2.f;
		if (vector.y > 0) vector.y = -vector.y;
		break;
	}
	setPosition(pos);
	printf("%.2f, %.2f\n", vector.x, vector.y);
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

	//Vector2u size = getTexture()->getSize();
	if (pos.x < -(int)size.x) {
		return true;
	}
	if (pos.y < -(int)size.y) {
		return true;
	}

	return false;
}
