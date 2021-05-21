#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class MovingSprite : public Sprite
{
public:
	void setVector(const Vector2f &vector);
	const Vector2f &getVector();
	virtual void update();
	bool collides(MovingSprite &sprite);
	void setTexture(const Texture& texture);
	Vector2f getCenter();
	float getRadius();
protected:
	Vector2f vector;
	Vector2u size;
};

