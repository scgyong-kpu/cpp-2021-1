#include "Highscore.h"
#include "Game.h"

Highscore::Highscore()
{
	font.loadFromFile("res/lucon.ttf");
}

void Highscore::add(float score)
{
	ScoreEntry e;
	e.time = time(NULL);
	e.score = score;
	//scores.push_back(e);

	bool inserted = false;
	for (auto it = scores.begin(); it != scores.end(); it++) {
		if (score > it->score) {
			scores.insert(it, e);
			inserted = true;
			break;
		}
	}
	if (!inserted) {
		scores.push_back(e);
	}

	printf("Scores now stores %d entries\n", scores.size());
}

void Highscore::save() const
{
}

void Highscore::load()
{
}

void Highscore::draw(RenderTarget& target, RenderStates states) const
{
	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);

	char sbuf[256], tbuf[128];
	float x = 100, y = WINDOW_HEIGHT / 2;
	for (auto it = scores.begin(); it != scores.end(); it++, y += 40) {
		auto& e = *it;
		text.setPosition(x, y);
		strftime(tbuf, sizeof(tbuf), "%Y-%m-%d %H:%M:%S", localtime(&e.time));
		sprintf(sbuf, "%s %6.1f", tbuf, e.score);
		text.setString(sbuf);
		target.draw(text);
	}
}

