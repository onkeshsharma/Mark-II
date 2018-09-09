#pragma once
#ifndef MTRN2500_TRAPPRISM_H
#define MTRN2500_TRAPPRISM_H

#include "Shape.hpp" 

class TrapPrism : public Shape {

public:
	TrapPrism() {};
	TrapPrism(double x, double y, double z, double xLength, double ytLength, double ybLenth, double zLength);
	double xLength;
	double ytLength;
	double ybLength;
	double zLength;
	void draw();
	//void Rotate(double angle);
};

#endif // !MTRN3500_TRAPPRISM_H
