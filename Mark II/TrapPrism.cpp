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

TrapPrism::TrapPrism(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void TrapPrism::SetHeight(double height)
{
	this->height = height;
}

void TrapPrism::SetLength(double length)
{
	this->length = length;
}

void TrapPrism::SetALength(double aLength)
{
	this->aLength = aLength;
}

void TrapPrism::SetBLength(double bLength)
{
	this->bLength = bLength;
}

double TrapPrism::GetHeight()
{
	return height;
}

double TrapPrism::GetLength()
{
	return length;
}

double TrapPrism::GetALength()
{
	return aLength;
}

double TrapPrism::GetBLength()
{
	return bLength;
}

void TrapPrism::draw()
{

	double xPos = getX();
	double yPos = getY();
	double zPos = getZ();

	double halflength = GetLength()/2;
	double halfheight = GetHeight()/2;
	double halfa = GetALength()/2;   // a and b here are the two parallel sides of the trapezoidal face
	double halfb = GetBLength()/2;
	
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
		glColor3d(35,68,120);
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
