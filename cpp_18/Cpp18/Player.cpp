#include "Player.h"
#include "Game.h"

#define SPEED 300
#define MARGIN 20

#define SCORE_MARGIN_RIGHT 15
#define SCORE_MARGIN_TOP   15

Player::Player()
{
	texture.loadFromFile("res/player.png");
	setTexture(texture);

	moveToCenter();

	whiteHeartTexture.loadFromFile("res/heart_white.png");
	redHeartTexture.loadFromFile("res/heart_red.png");

	float x = WINDOW_WIDTH - SCORE_MARGIN_RIGHT;
	float y = SCORE_MARGIN_TOP;
	int w = redHeartTexture.getSize().x;
	for (int i = 0; i < PLAYER_FULL_LIFE; i++) {
		x -= w;
		hearts[i].setPosition(x, y);
		//hearts[i].setTexture(redHeartTexture);
	}

	life = PLAYER_FULL_LIFE;
	updateHearts();
}

void Player::draw(RenderWindow& win)
{
	win.draw(*this);
	for (auto &heart: hearts) {
		win.draw(heart);
	}
}

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
	else if (e.type == Event::MouseMoved) {
		target.x = e.mouseMove.x;
		target.y = e.mouseMove.y;
	}
}

void Player::reset(void)
{
	life = PLAYER_FULL_LIFE;
	updateHearts();
	moveToCenter();
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

void Player::update()
{
	//MovingSprite::update();
	const Vector2f& pos = getPosition();

	float dx = target.x - pos.x;
	float dy = target.y - pos.y;
	double angle = atan2(dy, dx);
	double dist = SPEED * Game::frameTime;
	float mx = dist * cos(angle);
	float my = dist * sin(angle);
	move(mx, my);

	//const Vector2f &pos = getPosition();

	const float min_x = MARGIN, max_x = WINDOW_WIDTH - MARGIN - (float)size.x;
	const float min_y = MARGIN, max_y = WINDOW_HEIGHT - MARGIN - (float)size.y;

	if (pos.x < min_x) {
		setPosition(min_x, pos.y);
	}
	else if (pos.x > max_x) {
		setPosition(max_x, pos.y);
	}

	if (pos.y < min_y) {
		setPosition(pos.x, min_y);
	}
	else if (pos.y > max_y) {
		setPosition(pos.x, max_y);
	}
}

bool Player::decreaseLife()
{
	life--;
	updateHearts();
	return life > 0;
}

bool Player::increaseLife()
{
	if (life >= PLAYER_FULL_LIFE) {
		return false;
	}
	life++;
	updateHearts();
	return true;
}

void Player::updateHearts()
{
	for (int i = 0; i < PLAYER_FULL_LIFE; i++) {
		hearts[i].setTexture(i < life ? redHeartTexture : whiteHeartTexture);
	}
}

