#ifndef PLAYER_H
#define PLAYER_H

#include <random>
#include "h/Constants.h"

using namespace std;

class Player {
private:
	string name;
	int chips;
	int color;

public:
	Player() {
		name = "";
		chips = 0;
		color = 0;
	}

	Player(string n, int col) {
		name = n;
		color = col;
		chips = 0;
	}

	void setChips(int val) {
		chips = val;
	}

	void setName(string val) {
		name = val;
	}

	void setColor(int val) {
		color = val;
	}

	int getColor() {
		return color;
	}

	int getChips() {
		return chips;
	}

	string getName() {
		return name;
	}

	void incChips() {
		chips++;
	}

	void decChips() {
		chips--;
		chips = max(chips, 0);
	}

	static Player generatePlayer() {
		int r = rand() % size(NAME_DICTIONARY);
		string n = NAME_DICTIONARY[r];
		int c = rand() % MAX_COLORS;
		return Player(n, c);
	}
};

#endif