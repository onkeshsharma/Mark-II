#pragma once
#ifndef MTRN3500_TRIPRISM_H
#define MTRN3500_TRIPRISM_H

#include "Shape.hpp" 

class TriangularPrism : public Shape {

	public:
		TriangularPrism() {};
		TriangularPrism(double x, double y, double z);
		
		void SetHeight(double height);
		void SetLength(double length);
		void SetWidth(double width);

		double GetHeight();
		double GetLength();
		double GetWidth();

		void draw();
	private:
		double height;
		double length;
		double width;


};
#endif
