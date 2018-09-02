#include "TriangularPrism.hpp"
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


TriangularPrism::TriangularPrism(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void TriangularPrism::SetHeight(double height)
{
	this->height = height;
};

void TriangularPrism::SetLength(double length)
{
	this->length = length;


};

void TriangularPrism::SetWidth(double width)
{
	this->width = width;
};

double TriangularPrism::GetHeight()
{
	return height;
};

double TriangularPrism::GetLength()
{
	return length;
};

double TriangularPrism::GetWidth()
{
	return width;
};

void TriangularPrism::draw()
{
	double xPos = getX();
	double yPos = getY();
	double zPos = getZ();

	double halflength = GetLength() / 2;
	double halfwidth = GetWidth() / 2;
	double halfheight = GetHeight() / 2;

	glBegin(GL_TRIANGLES);
		// triangular faces
		glVertex3d(xPos - halfwidth, yPos - halflength,zPos - halfheight);
		glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
		glVertex3d(xPos, yPos - halflength, zPos + halfheight);

		glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);
		glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
		glVertex3d(xPos , yPos + halflength, zPos + halfheight);	
	glEnd();

	glBegin(GL_QUADS);
	// rectangular base
		glColor3d(255, 0, 0);
		glVertex3d(xPos - halfwidth, yPos - halflength, zPos - halfheight);
		glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
		glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
		glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);

	//rectangular sides
		glColor3d(25, 100, 0);
		glVertex3d(xPos - halfwidth, yPos - halflength, zPos - halfheight);
		glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);
		glVertex3d(xPos , yPos + halflength, zPos + halfheight);
		glVertex3d(xPos , yPos - halflength, zPos + halfheight);
		
		glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
		glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
		glVertex3d(xPos, yPos + halflength, zPos + halfheight);
		glVertex3d(xPos, yPos - halflength, zPos + halfheight);
	glEnd();
};
