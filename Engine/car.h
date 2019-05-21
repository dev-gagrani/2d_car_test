#pragma once

#include"Graphics.h"
#define _USE_MATH_DEFINES
#include <math.h>
class car
{
private:
	float x,y;
	float theta;
	float vx,vy;
	float v;
	float ax,ay;
	float braking_a;
	float mass;
	float g;
	float coeff_friction_static, coeff_friction_kinetic;
	float ang_v;
public:
	car();
	void move_car(float distance);
	void move_car();
	void rotate(float del_theta);
	void display_car(Graphics& gfx);
	void up();
	void down();
	void left();
	void right();
	void reorient();
};