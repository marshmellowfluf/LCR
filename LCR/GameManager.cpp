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
#include "TableScene.cpp"

using namespace std;

static Player PC;
static vector<Player> players;
static TableScene* table_scene;

class GameManager {
private:


public:

	static void initialize() {
		players.clear();
		players.push_back(PC);
	};

	static int addplayer(Player p) {
		players.push_back(p);
		return players.size() - 1;
	};

	static void startGame(string pcname, int ante, int numplayers) {
		players[0].setChips(ante);
		players[0].setName(pcname);
		int p;
		for (int i = 0; i < numplayers - 1; i++) {
			p = addplayer(Player::generatePlayer());
			players[p].setChips(ante);
		}
		delete table_scene;
		table_scene = new TableScene(players);
		SceneManager::transition(table_scene);
	}

};

#endif