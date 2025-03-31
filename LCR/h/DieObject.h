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
    int facing;
    double direction;
    double speed;

public:
    DieObject();
    
    // Called every frame
    void tick();

    bool finishedRoll();

    int getRoll();



};

#endif