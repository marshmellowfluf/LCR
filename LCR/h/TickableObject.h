//    Class by Tyler Downey
//    TickableObject Class
//
//    An object that needs to be updated every frame

#ifndef TICKABLEOBJECT_H
#define TICKABLEOBJECT_H

class TickableObject {
private:

public:
    // Called every frame
    virtual void tick() = 0;

};

#endif