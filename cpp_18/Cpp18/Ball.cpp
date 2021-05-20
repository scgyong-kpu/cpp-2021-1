#include "Ball.h"
#include "Game.h"

Ball::Ball(Texture& texture)
{
	setTexture(texture);
	vector.x = Game::getRandom(100) + 50;
	vector.y = Game::getRandom(100) + 20;
}
