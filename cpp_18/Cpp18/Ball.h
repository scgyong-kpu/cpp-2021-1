#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball : public Sprite
{
public:
	void setVector(const Vector2f &vector);
	Vector2f getVector();
private:
	Vector2f vector;
};

