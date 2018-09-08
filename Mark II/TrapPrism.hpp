#pragma once
#ifndef MTRN2500_TRIANGULARPRISM_H
#define MTRN2500_TRIANGULARPRISM_H

#include "Shape.hpp" 

class TriangularPrism : public Shape {

public:
	TriangularPrism() {};
	TriangularPrism(double x, double y, double z, double xLength, double yLength, double zLength );
	double xLength;
	double yLength;
	double zLength;
	void draw();
	//void Rotate(double angle);
};

#endif // !MTRN3500_TRIANGULARPRISM_H
