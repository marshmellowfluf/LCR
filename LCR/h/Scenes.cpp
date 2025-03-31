//    Class by Tyler Downey
//    Scenes Class
//
//    Collection of scenes used in LCR

#include <iostream>
#include "SceneManager.h"
#include "Scene.h"
#include "../assets/gfx.h"
#include "TitleDieObject.cpp"
#include "../GameManager.cpp"
#include "../TableScene.cpp"


class StartScene : public Scene {
private:
    string name;
    int ante;
    int numplayers;
    int delay;

public:
    StartScene() {
        StringScreen* s = SceneManager::getScreen();
        s->clearscreen();
        state = 0;
        name = "";
        ante = 0;
        numplayers = 0;
        delay = 0;
    }

    void enter(chrono::milliseconds gametime) {
        StringScreen* s = SceneManager::getScreen();
        s->drawrect(1, 1, 98, 18, RED_CHAR);
        s->drawtext(42, 9, "ENTER YOUR NAME");
        s->drawrect(40, 7, 58, 11, BLUE_CHAR);
        state = 1;
    };

    void tick(chrono::milliseconds gametime) {
        if (state == 4) {
            delay--;
            if (delay == 0) {
                GameManager::startGame(name, ante, numplayers);
                state = 5;
            }
        }
    };

    // Called when the scene ends
    void exit(chrono::milliseconds gametime) {

    };

    // Returns true if the scene is waiting for input
    bool requestingInput() {
        return state == 1 || state == 2 || state == 3;
    };

    // Handle input
    void processInput(std::string input, chrono::milliseconds gametime) {
        StringScreen* s = SceneManager::getScreen();
        if (state == 1) {
            name = input;
            s->clearscreen();
            s->drawrect(1, 1, 98, 18, YELLOW_CHAR);
            s->drawtext(42, 9, "ENTER YOUR ANTE");
            s->drawrect(40, 7, 58, 11, RED_CHAR);
            state = 2;
            return;
        }
        if (state == 2) {
            ante = max(3, min(99, stoi(input)));
            s->clearscreen();
            s->drawrect(1, 1, 98, 18, BLUE_CHAR);
            s->drawtext((100 - name.length()) / 2, 7, name);
            s->drawtext(33, 9, "PLAYERS WILL START WITH " + to_string(ante) + " CHIPS.");
            s->drawtext(31, 11, "HOW MANY PLAYERS? SELECT BETWEEN 3-10.");
            s->drawrect(29, 5, 71, 13, RED_CHAR);
            state = 3;
            return;
        }
        if (state == 3) {
            numplayers = max(3, min(10, stoi(input)));
            s->clearscreen();
            s->drawrect(1, 1, 98, 18, CYAN_CHAR);
            s->drawtext(42, 9, "STARTING GAME...");
            delay = 15;
            state = 4;
        }
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


class TitleScene : public Scene {
    TitleDieObject* die1;
    TitleDieObject* die2;
    TitleDieObject* die3;

    bool die1check = false;
    bool die2check = false;
    bool die3check = false;

public:
    TitleScene() {
        state = 0;
        die1 = nullptr;
        die2 = nullptr;
        die3 = nullptr;
    }

    void enter(chrono::milliseconds gametime) {
        StringScreen* s = SceneManager::getScreen();
        s->clearscreen();
        s->load(TITLE_CARD);
        s->savetobuffer();
        die1 = new TitleDieObject(s->getwidth(), s->getheight());
        die2 = new TitleDieObject(s->getwidth(), s->getheight());
        die3 = new TitleDieObject(s->getwidth(), s->getheight());
        

    };

    // Called every game tick
    void tick(chrono::milliseconds gametime) {
        StringScreen* s = SceneManager::getScreen();
        switch (state) {
        case 0:
            s->restorefrombuffer();

            if (die1 != nullptr) {
                die1->tick();
                if (!die1->onscreen(s->getwidth(), s->getheight())) {
                    if (die1check) { 
                        delete die1; 
                        die1 = nullptr; 
                    };
                }
                else {
                    die1check = true;
                    die1->getModel()->render(s);
                };
            };
            if (die2 != nullptr) {
                die2->tick();
                if (!die2->onscreen(s->getwidth(), s->getheight())) {
                    if (die2check) { 
                        delete die2;
                        die2 = nullptr;
                    };
                }
                else {
                    die2check = true;
                    die2->getModel()->render(s);
                };
            };
            if (die3 != nullptr) {
                die3->tick();
                if (!die3->onscreen(s->getwidth(), s->getheight())) {
                    if (die3check) { 
                        delete die3;
                        die3 = nullptr;
                    }
                }
                else {
                    die3check = true;
                    die3->getModel()->render(s);
                };
            };
            if (die1 == nullptr && die2 == nullptr && die3 == nullptr) { 
                state = 1;
                s->clearscreen();
                s->restorefrombuffer();
                s->drawtext(30, 19, "PRESS ENTER TO START");
            }
            break;
        case 1:
            break;
        };
    };

    // Called when the scene ends
    void exit(chrono::milliseconds gametime) {
        delete die1;
        delete die2;
        delete die3;
        state = 2;
    };

    // Returns true if the scene is waiting for input
    bool requestingInput() {
        return state == 1;
    };

    // Handle input
    void processInput(std::string input, chrono::milliseconds gametime) {
        SceneManager::transition(new StartScene());
    };

    int getState() {
        return state;
    };

    // Returns true if the scene has finished its exit() function
    bool exited() {
        return state == 2;
    };

    bool isPersistent() {
        return false;
    }

};

