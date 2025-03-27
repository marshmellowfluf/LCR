//    Class by Tyler Downey
//    RenderedObject Class
//    An object that can be rendered on screen

#ifndef RENDEREDOBJECT_H
#define RENDEREDOBJECT_H

#include <iostream>
#include "StringScreen.h"

using namespace std;

class RenderedObject {
private:

public:
    // Renders the object to screen
    virtual void render(StringScreen* screen) = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

};

#endif