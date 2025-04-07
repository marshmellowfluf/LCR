
#include <random>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "TickableObject.h"
#include "Cube3D.h"

class TitleDieObject : public TickableObject {
private:
	Cube3D* model;
	pair<double, double> rot_axis;
	double speed;
	double rotation = 0;
	pair<double, double> direction;
	pair<double, double> position;
public:
	TitleDieObject(int scr_width, int scr_height) {
		model = new Cube3D(10);
		model->setFace(0, RED_CHAR);
		model->setFace(1, BLUE_CHAR);
		model->setFace(2, YELLOW_CHAR);
		int target_x = (scr_width / 2); // *((double)rand() / (double)RAND_MAX) + scr_width / 4;
		int target_y = (scr_height / 4); // *((double)rand() / (double)RAND_MAX) + scr_height / 4;
		double dir = 2 * M_PI * (double)rand() / (double)RAND_MAX;
		rot_axis.first = cos(dir + M_PI / 2);
		rot_axis.second = sin(dir + M_PI / 2);
		speed = 3 + (3 * (double)rand() / (double)RAND_MAX);
		direction.first = cos(dir) * speed;
		direction.second = sin(dir) * speed;
		position.first = target_x - (direction.first * 10);
		position.second = target_y - (direction.second * 10);
		model->setPosition(position.first, position.second, 0);
	};

	void tick() {
		rotation -= 0.2 * speed;
		position.first += direction.first;
		position.second += direction.second;
		model->transform.rotateAA(rotation, rot_axis.first, rot_axis.second, 0);
		model->setPosition(position.first, position.second, 0);
	};

	bool onscreen(int scr_width, int scr_height) const {
		if (position.first > scr_width + 10) return false;
		if (position.first < -10) return false;
		if (position.second > scr_height + 10) return false;
		if (position.second < -10) return false;
		return true;
	}

	Cube3D* getModel() const {
		return model;
	};

	~TitleDieObject() {
		delete model;
		model = nullptr;
	};

};