#include "RectangularPrism.hpp"
#include <cmath>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

RectangularPrism::RectangularPrism(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
};

void RectangularPrism::draw()
{
	double xPos = getX();
	double yPos = getY();
	double zPos= getZ();

	double halfXLen = getXLength()/2;
	double halfYLen = getYLength()/2;
	double halfZLen = getZLength()/2;

	glBegin(GL_QUADS);

		//front and back

		glColor3d(255, 0, 0);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos - halfZLen);

		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos + halfZLen);


		//left and right
		glColor3d(0, 255, 0);
		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos + halfZLen);
		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos + halfZLen);


		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos - halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos + halfZLen);

		//top and bottom
		glColor3d(0, 0, 255);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos + halfZLen);
		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos + halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos + halfZLen);


		glVertex3d(xPos - halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos + halfXLen, yPos + halfYLen, zPos - halfZLen);
		glVertex3d(xPos + halfXLen, yPos - halfYLen, zPos - halfZLen);
		glVertex3d(xPos - halfXLen, yPos - halfYLen, zPos - halfZLen);
	
	glEnd();
};

void RectangularPrism::setXLength(double length)
{
	this->xLength = length;
};

void RectangularPrism::setYLength(double length)
{
	this->yLength = length;
};

void RectangularPrism::setZLength(double length)
{
	this->zLength = length;
};
double RectangularPrism::getXLength()
{
	return xLength;
};
double RectangularPrism::getYLength()
{
	return yLength;
}
double RectangularPrism::getZLength()
{
	return zLength;
};




