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

RectangularPrism::RectangularPrism(double x, double y, double z, double xLength, double yLength, double zLength)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->xLength = xLength;
	this->yLength = yLength;
	this->zLength = zLength;

};

void RectangularPrism::draw()
{
	double xPos = x;
	double yPos = y;
	double zPos = z;

	double height = xLength;
	double length = yLength;
	double width = zLength;

	double halfXLen = height/2;
	double halfYLen = length/2;
	double halfZLen = width/2;

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






