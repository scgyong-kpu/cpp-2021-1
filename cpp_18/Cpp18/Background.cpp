#include "Background.h"
#include "Game.h"

Background::Background() : player{ nullptr }
{
	txOuterspace.loadFromFile("res/outerspace.png");
	setTexture(txOuterspace);

	txStars.loadFromFile("res/stars.png");
	spStars.setTexture(txStars);
}

void Background::update()
{
	auto &pos = player->getPosition();
	setPosition(-pos.x / 20.0f, -pos.y / 20.0f);

	spStars.setPosition(-pos.x / 10.0f, -pos.y / 10.0f);
}

void Background::setPlayer(Player& player)
{
	this->player = &player;
}

void Background::draw(RenderWindow& win)
{
	win.draw(*this);
	win.draw(spStars);
}
