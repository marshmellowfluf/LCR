#ifndef TABLESCENE_H
#define TABLESCENE_H


#include <iostream>
#include "h/SceneManager.h"
#include "h/Scene.h"
#include "assets/gfx.h"
#include "GameManager.cpp"

using namespace std;

class TableScene : public Scene {
private:
    int delay;
public:
    TableScene() {
        state = 0;
        delay = 0;
    }

    // Called when the scene starts
    void enter(chrono::milliseconds gametime) {
        
        StringScreen* s = SceneManager::getScreen();
        s->clearscreen();
        for (int i = 0; i < table.size(); i++) {
            s->drawrect(SEAT_POSITIONS[i][0], SEAT_POSITIONS[i][1], SEAT_POSITIONS[i][2], SEAT_POSITIONS[i][3], COLORS[table[i].getColor()]);
            s->drawtext(CHIPS_POSITIONS[i][0], CHIPS_POSITIONS[i][1], "CHIPS: " + to_string(table[i].getChips()) + "  ");
            s->drawtext(NAMES_POSITIONS[i][0], NAMES_POSITIONS[i][1], table[i].getName());
        }
        s->savetobuffer();
        if (state == 0) {
            s->drawtext(45, 9, "YOUR TURN");
            delay = 5;
        };
    };

    // Called every game tick
    void tick(chrono::milliseconds gametime) {
        if (state == 0) {
            delay--;
            if (delay == 0) {

            }
        };
    };

    // Called when the scene ends
    void exit(chrono::milliseconds gametime) {

    };

    // Returns true if the scene is waiting for input
    bool requestingInput() {
        return false;
    };

    // Handle input
    void processInput(std::string input, chrono::milliseconds gametime) {
    
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