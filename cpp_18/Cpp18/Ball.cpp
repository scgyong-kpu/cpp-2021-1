#include "Ball.h"

Ball::Ball(Texture& texture)
{
	setTexture(texture);
	vector.x = 120;// (float)(rnd_engine() % 100 + 50);
	vector.y = 100;// (float)(rnd_engine() % 100 + 20);
}
