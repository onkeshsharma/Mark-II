#include "TrapPrism.hpp"
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

TrapPrism::TrapPrism(double x, double y, double z, double xLength, double ytLength, double ybLength, double zLength)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->xLength = xLength;
	this->ytLength = ytLength;
	this->ybLength = ybLength;
	this->zLength = zLength;

}

void TrapPrism::draw()
{
	double xPos = x;
	double yPos = y;
	double zPos = z;

	double height = xLength;
	double lengtht = ytLength;
	double lengthb = ybLength;
	double width = zLength;

	double halflength = width / 2;
	double halfheight = height / 2;
	double halfa = lengtht / 2;   // a and b here are the two parallel sides of the trapezoidal face
	double halfb = lengthb / 2;

	glBegin(GL_QUADS);
	//trap faces
	glVertex3d(xPos - halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfa, yPos - halflength, zPos + halfheight);
	glVertex3d(xPos - halfa, yPos - halflength, zPos + halfheight);

	glVertex3d(xPos - halfb, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos + halfb, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos + halfa, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos - halfa, yPos + halflength, zPos + halfheight);

	//rectangular faces
	glColor3d(35, 68, 120);
	glVertex3d(xPos - halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfb, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos - halfb, yPos + halflength, zPos - halfheight);

	glColor3d(255, 0, 0);
	glVertex3d(xPos - halfa, yPos - halflength, zPos + halfheight);
	glVertex3d(xPos + halfa, yPos - halflength, zPos + halfheight);
	glVertex3d(xPos + halfa, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos - halfa, yPos + halflength, zPos + halfheight);

	glColor3d(0, 0, 80);
	glVertex3d(xPos - halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos - halfa, yPos - halflength, zPos + halfheight);
	glVertex3d(xPos - halfa, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos - halfb, yPos + halflength, zPos - halfheight);

	glVertex3d(xPos + halfb, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfa, yPos - halflength, zPos + halfheight);
	glVertex3d(xPos + halfa, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos + halfb, yPos + halflength, zPos - halfheight);

	glEnd();

}
