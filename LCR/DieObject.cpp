#include "h/DieObject.h"
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

DieObject::DieObject(int x, int y) {
	model = new Cube3D(10);
	model->setFace(0, RED_CHAR);
	model->setFace(1, BLUE_CHAR);
	model->setFace(2, YELLOW_CHAR);
	target_x = x;
	target_y = y;
	speed = 4.5;
	direction = 2 * M_PI * (double)rand() / (double)RAND_MAX;
	facing = rand() % 6;
	int rand_dist = 5 + rand() % 6;
	model->setPosition(x - cos(direction) * rand_dist, y - sin(direction) * rand_dist, 10);
	model->transform.rotate(0, 0, direction);
	done = false;
};

// Called every frame
void DieObject::tick() {
	if (!done) {
		double* pos = model->getPosition();
		pos[0] += cos(direction);
		pos[1] += sin(direction);
		model->setPosition(pos[0], pos[1], pos[2]);
		if (target_x == pos[0] && target_y == pos[1]) done = true;
	};
};

bool DieObject::finishedRoll() {
	return done;
};

int DieObject::getRoll() {
	return 0;
};



