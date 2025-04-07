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
    Cube3D* model;
    int facing;
    int target_x;
    int target_y;
    double direction;
    double speed;
    bool done;

public:
    DieObject(int, int);
    
    // Called every frame
    void tick();

    bool finishedRoll();

    int getRoll();



};

#endif