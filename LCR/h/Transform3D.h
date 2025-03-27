//    Class by Tyler Downey
//    Transform3D Class
//
//    Represents a 3D transformation matrix

#ifndef TRANSFORM3D_H
#define TRANSFORM3D_H
#include <iostream>
#include <math.h>
#include "RenderedObject.h"
#include "Constants.h"

using namespace std;

class Transform3D {
private:
    double translation_factor[3] = {0, 0, 0};
    double scale_factor[3] = {1, 1, 1};
    double rotation_factor[3] = {0, 0, 0};

    double rot_matrix[4] = {0, 0, 0, 1};
    
    double* quaternion_multiply(double x0, double x1, double x2, double x3, double y0, double y1, double y2, double y3) const {
        double *toreturn = new double[4];
        toreturn[0] = x0*y0 - x1*y1 - x2*y2 - x3*y3;
        toreturn[1] = x0*y1 + x1*y0 - x2*y3 + x3*y2;
        toreturn[2] = x0*y2 + x1*y3 + x2*y0 - x3*y1;
        toreturn[3] = x0*y3 - x1*y2 + x2*y1 + x3*y0;
        return toreturn;
    };

    void normalizeRotationMatrix() {
        double normalizer = sqrt(rot_matrix[0]*rot_matrix[0] + rot_matrix[1]*rot_matrix[1] + rot_matrix[2]*rot_matrix[2] + rot_matrix[3]*rot_matrix[3]);

        rot_matrix[0] /= normalizer;
        rot_matrix[1] /= normalizer;
        rot_matrix[2] /= normalizer;
        rot_matrix[3] /= normalizer;
    };

public:

    Transform3D() { 
        
    };

    Transform3D* rotate(double x, double y, double z) {
        rotation_factor[0] = x;
        rotation_factor[1] = y;
        rotation_factor[2] = z;

        double cu = cos(x / 2);
        double su = sin(x / 2);
        double cv = cos(y / 2);
        double sv = sin(y / 2);
        double cw = cos(z / 2);
        double sw = sin(z / 2);

        rot_matrix[0] = cu*cv*cw + su*sv*sw;
        rot_matrix[1] = su*cv*cw - cu*sv*sw;
        rot_matrix[2] = cu*sv*cw + su*cv*sw;
        rot_matrix[3] = cu*cv*sw - su*sv*cw;

        normalizeRotationMatrix();
        
        return this;
    };

    // Rotate using axis-angle notation
    // Does not update rotations. It should, but for this program it would just add unnecessary calculations.
    Transform3D* rotateAA(double angle, double x, double y, double z) {
        
        rot_matrix[0] = cos(angle / 2);
        rot_matrix[1] = x * sin(angle / 2);
        rot_matrix[2] = y * sin(angle / 2);
        rot_matrix[3] = z * sin(angle / 2);

        normalizeRotationMatrix();

        return this;
    };

    Transform3D* scale(double x, double y, double z) {
        scale_factor[0] = x;
        scale_factor[1] = y;
        scale_factor[2] = z;
        
        return this;        
    };

    Transform3D* translate(double x, double y, double z) {
        translation_factor[0] = x;
        translation_factor[1] = y;
        translation_factor[2] = z;
        
        return this;
    };

    double* apply(double x, double y, double z) const {
        double* toreturn = new double[3];
        double* matrix = quaternion_multiply(0, x, y, z, rot_matrix[0], rot_matrix[1], rot_matrix[2], rot_matrix[3]);
        double* matrix2 = quaternion_multiply(rot_matrix[0], -rot_matrix[1], -rot_matrix[2], -rot_matrix[3], matrix[0], matrix[1], matrix[2], matrix[3]);
        toreturn[0] = matrix2[1] * scale_factor[0] + translation_factor[0];
        toreturn[1] = matrix2[2] * scale_factor[1] + translation_factor[1];
        toreturn[2] = matrix2[3] * scale_factor[2] + translation_factor[2];

        delete matrix;
        delete matrix2;

        return toreturn;
    };

};

#endif