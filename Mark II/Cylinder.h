#ifndef Cylinder_H
#define Cylinder_H

#include "Shape.hpp"

class Cylinder : public Shape {

	double Radius;
	double Depth;
	double Angle;
	double turnAmt;
	static GLUquadricObj *ptr;
	double Roller;
	double Speed;
	double RollingAmount = 0.0;
	double PI = 3.1415;


public:
	Cylinder();
	void draw();
	~Cylinder();
	void setRolling(bool rolling);
	void SetZRotation(double zRotation);
	double setrollVel(double vel);
	double SetTurnAmt(double vel);
	bool GetRolling();
	Cylinder(double rad, double depth, double inc, bool rolling);
};
#endif