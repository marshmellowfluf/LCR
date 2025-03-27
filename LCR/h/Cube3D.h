//    Class by Tyler Downey
//    Cube3D Class
//
//    A 3D cube that can be rendered to StringScreen

#ifndef CUBE3D_H
#define CUBE3D_H
#include "RenderedObject.h"
//#include "Constants.h"
#include "Transform3D.h"

class Cube3D: public RenderedObject {
private:
    int edge_length;
    double x;
    double y;
    double z;

    double vertices[8][3];

    char faces[6];

public:
    Transform3D transform;

    Cube3D(int edge);

    // sets face face to be drawn with character c
    void setFace(int face, char c);

    // Outputs an array of strings that can be drawn to StringScreen
    void render(StringScreen* screen);

    // Size on screen
    int getWidth() const;

    int getHeight() const;

    void setPosition(double x, double y, double z);

    double* getPosition() const;
    
};

#endif