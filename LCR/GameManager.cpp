//    Class by Tyler Downey
//    SceneManager Class
//
//    Manages the game flow

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <vector>
#include <random>
#include "h/Constants.h"
#include "Player.cpp"
#include "h/SceneManager.h"

using namespace std;

static Player PC;
static vector<Player> table;

class GameManager {
private:

public:

	static void initialize() {
		table.clear();
		table.push_back(PC);
	};

	static int addplayer(Player p) {
		table.push_back(p);
		return table.size() - 1;
	};

	static void startGame(string pcname, int ante, int numplayers) {
		table[0].setChips(ante);
		table[0].setName(pcname);
		int p;
		for (int i = 0; i < numplayers - 1; i++) {
			p = addplayer(Player::generatePlayer());
			table[p].setChips(ante);
		}
	}

};

#endif