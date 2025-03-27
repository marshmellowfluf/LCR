//    Class by Tyler Downey
//    DieObject Class
//
//    A rollable die with functions for rendering

#ifndef DIEOBJECT_H
#define DIEOBJECT_H

#include "TickableObject.h"
#include "RenderedObject.h"
#include "Cube3D.h"

class DieObject : public TickableObject {
private:
    Cube3D model;
public:
    // Called every frame
    void tick();

    

};

#endif