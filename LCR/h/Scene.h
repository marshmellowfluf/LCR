//    Class by Tyler Downey
//    Scene Class
//
//    Abstract class representing a scene

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <chrono>
#include "StringScreen.h"

class Scene {
protected:
    int state;

public:

    // Called when the scene starts
    virtual void enter(chrono::milliseconds gametime) = 0;

    // Called every game tick
    virtual void tick(chrono::milliseconds gametime) = 0;

    // Called when the scene ends
    virtual void exit(chrono::milliseconds gametime) = 0;

    // Returns true if the scene is waiting for input
    virtual bool requestingInput() = 0;

    // Handle input
    virtual void processInput(std::string input, chrono::milliseconds gametime) = 0;

    virtual int getState() = 0;

    // Returns true if the scene has finished its exit() function
    virtual bool exited() = 0;

    // Persistent scenes are not automatically deleted by the manager
    virtual bool isPersistent() = 0;
};

#endif