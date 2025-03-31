#include "h/DieObject.h"
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

DieObject::DieObject() {
	model.setFace(0, RED_CHAR);
	model.setFace(1, BLUE_CHAR);
	model.setFace(2, YELLOW_CHAR);
	direction = 2 * M_PI * (double)rand() / (double)RAND_MAX;
	model.transform.rotate(0, 0, direction);
};

// Called every frame
void DieObject::tick() {

};

bool DieObject::finishedRoll() {

};

int DieObject::getRoll() {

};



