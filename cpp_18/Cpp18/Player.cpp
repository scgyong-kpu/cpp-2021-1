#include "Player.h"
#include "Game.h"

#define SPEED 300

void Player::handleEvent(Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) {
			if (vector.x >= 0) vector.x -= SPEED;
		}
		else if (e.key.code == Keyboard::Right) {
			if (vector.x <= 0) vector.x += SPEED;
		}
		else if (e.key.code == Keyboard::Up) {
			if (vector.y >= 0) vector.y -= SPEED;
		}
		else if (e.key.code == Keyboard::Down) {
			if (vector.y <= 0) vector.y += SPEED;
		}
	} else if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) {
			if (vector.x <= 0) vector.x += SPEED;
		}
		else if (e.key.code == Keyboard::Right) {
			if (vector.x >= 0) vector.x -= SPEED;
		}
		else if (e.key.code == Keyboard::Up) {
			if (vector.y <= 0) vector.y += SPEED;
		}
		else if (e.key.code == Keyboard::Down) {
			if (vector.y >= 0) vector.y -= SPEED;
		}
	}
}

void Player::moveToCenter(void)
{
	//const Texture& texture = *getTexture();
	//Vector2u size = texture.getSize();
	Vector2u size = getTexture()->getSize();
	Vector2f pos(
		WINDOW_WIDTH / 2 - (float)(size.x / 2), 
		WINDOW_HEIGHT / 2 - (float)(size.y / 2)
	);
	setPosition(pos);
}
