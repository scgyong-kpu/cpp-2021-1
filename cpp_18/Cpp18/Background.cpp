#include "Background.h"

Background::Background() : player{ nullptr }
{
	txOuterspace.loadFromFile("res/outerspace.png");
	setTexture(txOuterspace);
}

void Background::setPlayer(Player& player)
{
	this->player = &player;
}
