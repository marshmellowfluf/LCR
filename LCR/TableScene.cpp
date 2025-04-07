#ifndef TABLESCENE_H
#define TABLESCENE_H


#include <iostream>
#include "h/SceneManager.h"
#include "h/Scene.h"
#include "assets/gfx.h"
#include "Player.cpp"

using namespace std;

class TableScene : public Scene {
private:
    int delay;
    int turn;
    int rolling;
    int center_chips;
    int victor;
    vector<Player> players;

public:
    TableScene(vector<Player>& p) {
        state = 0;
        delay = 0;
        turn = 0;
        rolling = 0;
        players = p;
        center_chips = 0;
        victor = -1;
    }

    // Called when the scene starts
    void enter(chrono::milliseconds gametime) {
        
        StringScreen* s = SceneManager::getScreen();
        s->clearscreen();
        for (int i = 0; i < players.size(); i++) {
            s->drawrect(SEAT_POSITIONS[i][0], SEAT_POSITIONS[i][1], SEAT_POSITIONS[i][2], SEAT_POSITIONS[i][3], COLORS[players.at(i).getColor()]);
            s->drawtext(CHIPS_POSITIONS[i][0], CHIPS_POSITIONS[i][1], "CHIPS: " + to_string(players.at(i).getChips()) + "  ");
            s->drawtext(NAMES_POSITIONS[i][0], NAMES_POSITIONS[i][1], players.at(i).getName());
        }
        s->drawtext(CENTER_CHIPS_POSITION[0], CENTER_CHIPS_POSITION[1], "CENTER CHIPS: 0");
        s->savetobuffer();
        if (state == 0) {
            s->drawtext(45, 8, "YOUR TURN");
            delay = 10;
        };
    };

    // Called every game tick
    void tick(chrono::milliseconds gametime) {
        int init_turn = turn;
        StringScreen* s = SceneManager::getScreen();
        if (state == 0) {
            delay--;
            if (delay == 0) {
                state = 1;
                s->restorefrombuffer();
                s->drawtext(43, 8, "PRESS ENTER TO ROLL");
            }
        }
        else if (state == 2) {
            turn++;
            if (turn >= players.size()) turn = 0;
            while (players.at(turn).getChips() == 0) {
                turn++;
                if (turn >= players.size()) turn = 0;
            };
            if (init_turn == turn) {
                // victory
                state = 10;
            }
            else if (turn == 0) {
                if (players.at(turn).getChips() != 0) {
                    state = 0;
                    delay = 10;
                    s->drawtext(45, 8, "YOUR TURN");
                };
            }
            else {
                state = 3;
                delay = 10;
                s->restorefrombuffer();
            }
        }
        else if (state == 3) {
            s->restorefrombuffer();
            int roll = 0;
            delay--;
            for (int i = 0; i < min(3, players.at(turn).getChips()); i++) {
                roll = rand() % 6;
                s->drawtext(DICE_POSITIONS[turn][0] + i * 2, DICE_POSITIONS[turn][1], string(1, (roll == 0) ? L_CHAR : (roll == 1) ? C_CHAR : (roll == 2) ? R_CHAR : BLACK_CHAR));
                s->drawtext(0, 19, to_string(delay) + "  ");
                if (delay == 0) {
                    int left_player = turn + 1;
                    if (left_player == players.size()) left_player = 0;
                    int right_player = turn - 1;
                    if (right_player == -1) right_player = players.size() - 1;
                    switch (roll) {
                    case 0:
                        players.at(turn).decChips();
                        players.at(left_player).incChips();
                        break;
                    case 1:
                        players.at(turn).decChips();
                        center_chips++;
                        break;
                    case 2:
                        players.at(turn).decChips();
                        players.at(right_player).incChips();
                        break;
                    default:
                        break;
                    }
                }
            }
            if (delay == 0) {
                delay = 10;
                state = 4;
            }
        }
        else if (state == 4) {
            delay--;
            if (delay == 0) {
                int left_player = turn + 1;
                if (left_player == players.size()) left_player = 0;
                int right_player = turn - 1;
                if (right_player == -1) right_player = players.size() - 1;

                updateCenterChips(center_chips);
                updatePlayerChips(turn, players.at(turn).getChips());
                updatePlayerChips(left_player, players.at(left_player).getChips());
                updatePlayerChips(right_player, players.at(right_player).getChips());

                s->drawtext(DICE_POSITIONS[turn][0], DICE_POSITIONS[turn][1], "     ");
                s->savetobuffer();
                victor = checkForVictory();
                if (victor > -1) state = 10; else state = 2;
            }
        }
        else if (state == 10) {
            s->clearscreen();
            s->drawrect(1, 1, 98, 18, RED_CHAR);
            s->drawtext(47, 8, "WINNER!");
            s->drawtext(47, 10, players.at(victor).getName());
            state = 11;
        };
    };

    int checkForVictory() {
        int winner = -1;
        for (int i = 0; i < players.size(); i++) {
            if (players.at(i).getChips() > 0) {
                if (winner == -1) {
                    winner = i;
                }
                else {
                    return -1;
                }
            }
        }
        return winner;
    }

    void updatePlayerChips(int player, int chips) {
        StringScreen* s = SceneManager::getScreen();
        s->drawtext(CHIPS_POSITIONS[player][0], CHIPS_POSITIONS[player][1], "CHIPS: " + to_string(chips) + "  ");
    }

    void updateCenterChips(int chips) {
        StringScreen* s = SceneManager::getScreen();
        s->drawtext(CENTER_CHIPS_POSITION[0], CENTER_CHIPS_POSITION[1], "CENTER CHIPS: " + to_string(chips));
    }

    // Called when the scene ends
    void exit(chrono::milliseconds gametime) {

    };

    // Returns true if the scene is waiting for input
    bool requestingInput() {
        return state == 1 || state == 11;
    };

    // Handle input
    void processInput(std::string input, chrono::milliseconds gametime) {
        if (state == 11) return;
        state = 3;
        delay = 10;
        turn = 0;
    };

    int getState() {
        return state;
    };

    // Returns true if the scene has finished its exit() function
    bool exited() {
        return true;
    };

    bool isPersistent() {
        return true;
    }

};

#endif