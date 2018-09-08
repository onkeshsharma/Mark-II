#pragma once
#ifndef MTRN3500_TRAPRISM_H
#define MTRN3500_TRAPRISM_H

#include "Shape.hpp" 

class TrapPrism : public Shape {

	public:
		TrapPrism() {};
		TrapPrism(double x, double y, double z);

		void SetHeight(double height);
		void SetLength(double length);
		void SetALength(double aLength);
		void SetBLength(double bLength);

		double GetHeight();
		double GetLength();
		double GetALength();
		double GetBLength();

		void draw();

	private:
		double length;
		double height;
		double aLength;
		double bLength;
};
#endif
