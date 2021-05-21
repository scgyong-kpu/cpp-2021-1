#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class MovingSprite : public Sprite
{
public:
	void setVector(const Vector2f &vector);
	const Vector2f &getVector();
	void update();
	bool collides(MovingSprite &sprite);
protected:
	Vector2f vector;
};

