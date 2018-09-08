#pragma once
#ifndef MTRN3500_RECPRISM_H
#define MTRN3500_RECPRISM_H

#include "Shape.hpp" 

class RectangularPrism : public Shape {

public:
	RectangularPrism() {};
	RectangularPrism(double x, double y, double z, double xLength, double yLength ,double zLength);
	double xLength;
	double yLength;
	double zLength;
	void draw();
	//void Rotate(double angle);

};

#endif // !MTRN3500_OBSTACLE_H
