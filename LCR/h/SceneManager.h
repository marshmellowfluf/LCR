//    Class by Tyler Downey
//    SceneManager Class
//
//    Manages the objects and progression of a scene

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>
#include <chrono>
#include <iostream>
#include <string>
#include "RenderedObject.h"
#include "Scene.h"

static Scene* current_scene = nullptr;
static Scene* next_scene = nullptr;
static bool scene_init = false;
static StringScreen* screen = nullptr;

class SceneManager {
private:

public:
    
    static void init(int width, int height, Scene* first_scene) {
        screen = new StringScreen(width, height);
        current_scene = first_scene;
        next_scene = nullptr;
        scene_init = false;
    };

    static void process(chrono::milliseconds gametime) {
        if (next_scene) {
            if (scene_init) {
                current_scene->exit(gametime);
                scene_init = false;
            };
            if (current_scene->exited()) {
                if(!current_scene->isPersistent()) delete current_scene;
                current_scene = next_scene;
                next_scene = nullptr;
            }
            else {
                current_scene->tick(gametime);
                return;
            };
        };
        if (!scene_init) {
            current_scene->enter(gametime);
            scene_init = true;
        };
        if (current_scene->requestingInput()) {
            //screen->drawtext(5, 5, "INPUT REQUESTED");
            display();
            string input;
            getline(cin, input);
            current_scene->processInput(input, gametime);
            return;
        }
        current_scene->tick(gametime);

        display();
    };

    // Used to move to a new scene
    static void transition(Scene* scene) {
        next_scene = scene;
    }

    static StringScreen* getScreen() {
        return screen;
    }

    static void display() {
        cout << "\033[H";
        cout << "\033[0J";
        screen->display();
    };

};

#endif