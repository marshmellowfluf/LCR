#ifndef ROLLSCENE_H
#define ROLLSCENE_H


#include <iostream>
#include "h/SceneManager.h"
#include "h/Scene.h"
#include "assets/gfx.h"
#include "Player.cpp"

using namespace std;

class RollScene : public Scene {
private:

public:
    RollScene() {
        state = 0;
    }

    // Called when the scene starts
    void enter(chrono::milliseconds gametime) {

    };

    // Called every game tick
    void tick(chrono::milliseconds gametime) {

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
        return false;
    }

};

#endif