#include "Highscore.h"
#include "Game.h"
#include <fstream>
#include <iostream>

#define SCORE_FILENAME "score.dat"
#define MAX_SCORE_LIST 5

Highscore::Highscore()
{
	font.loadFromFile("res/lucon.ttf");
	load();
}

void Highscore::add(float score)
{
	ScoreEntry e;
	e.time = time(NULL);
	e.score = score;
	//scores.push_back(e);

	lastIndex = 0;
	bool inserted = false;
	for (auto it = scores.begin(); it != scores.end(); it++) {
		if (score > it->score) {
			scores.insert(it, e);
			inserted = true;
			break;
		}
		lastIndex++;
	}
	if (!inserted) {
		scores.push_back(e);
	}
	if (scores.size() > MAX_SCORE_LIST) {
		scores.pop_back();
	}

	save();
	//printf("Scores now stores %d entries\n", scores.size());
}

void Highscore::save() const
{
	std::ofstream file{ SCORE_FILENAME };
	if (!file) {
		return;
	}
	for (auto it = scores.begin(); it != scores.end(); it++) {
		file << it->time << " " << it->score << std::endl;
	}
}

void Highscore::load()
{
	std::ifstream file{ SCORE_FILENAME };
	if (!file) {
		std::cout << SCORE_FILENAME << " not found" << std::endl;
		return;
	}
	scores.clear();

	ScoreEntry e;
	while (file >> e.time >> e.score) {
		std::cout << e.time << ' ' << e.score << std::endl;
		scores.push_back(e);
	}
}

void Highscore::draw(RenderTarget& target, RenderStates states) const
{
	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);

	char sbuf[256], tbuf[128];
	float x = 140, y = WINDOW_HEIGHT * 3 / 5;
	int index = 0;
	for (auto it = scores.begin(); it != scores.end(); it++, y += 40, index++) {
		auto& e = *it;
		text.setPosition(x, y);
		strftime(tbuf, sizeof(tbuf), "%Y-%m-%d %H:%M:%S", localtime(&e.time));
		sprintf(sbuf, "%s %6.1f", tbuf, e.score);
		text.setString(sbuf);
		text.setFillColor(lastIndex == index ? Color::Yellow : Color::White);
		target.draw(text);
	}
}

