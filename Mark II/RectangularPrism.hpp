#pragma once
#ifndef MTRN3500_RECPRISM_H
#define MTRN3500_RECPRISM_H

#include "Shape.hpp" 

class RectangularPrism : public Shape {

public:
	RectangularPrism() {};
	RectangularPrism(double x, double y, double z);
	void draw();
	void setXLength(double length);
	void setYLength(double length);
	void setZLength(double length);

	double getXLength();
	double getYLength();
	double getZLength();  

	//void Rotate(double angle);


private:
	double xLength;
	double yLength;
	double zLength;

};

#endif // !MTRN3500_OBSTACLE_H
