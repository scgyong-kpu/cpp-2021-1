#include "Ball.h"
#include "Game.h"

Ball::Ball(Texture& texture)
{
	setTexture(texture);
	vector.x = (float)(Game::getRandom(100) + 50);
	vector.y = (float)(Game::getRandom(100) + 20);
}
