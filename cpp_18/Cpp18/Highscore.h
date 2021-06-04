#pragma once

//#include "Game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

struct ScoreEntry {
	time_t time;
	float score;
};

class Highscore : public Drawable {
public:
	Highscore();
	void add(float score);
	void save() const;
	void load();
	virtual void draw(RenderTarget& target, RenderStates states = RenderStates::Default) const;
protected:
	Font font;
	int lastIndex;
	std::vector<ScoreEntry> scores;
	//ScoreEntry scores[10];
};
