#include "Background.h"
#include "Game.h"

Background::Background() : player{ nullptr }
{
	txOuterspace.loadFromFile("res/outerspace.png");
	setTexture(txOuterspace);
}

void Background::update()
{
	auto &pos = player->getPosition();
	setPosition(-pos.x / 40.0f, -pos.y / 40.0f);
}

void Background::setPlayer(Player& player)
{
	this->player = &player;
}
