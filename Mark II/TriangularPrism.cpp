#include "TriangularPrism.h"
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

TriangularPrism::TriangularPrism(double x, double y, double z, double xLength, double yLength, double zLength)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->xLength = xLength;
	this->yLength = yLength;
	this->zLength = zLength;

};

void TriangularPrism::draw()
{
	double xPos = x;
	double yPos = y;
	double zPos = z;
	double height = xLength;
	double length = yLength;
	double width = zLength;

	double halfheight = height / 2;
	double halflength = length / 2;
	double halfwidth = width / 2;
	
	glBegin(GL_TRIANGLES);
	// triangular faces
	glVertex3d(xPos - halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos, yPos - halflength, zPos + halfheight);

	glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos, yPos + halflength, zPos + halfheight);
	glEnd();

	glBegin(GL_QUADS);
	// rectangular base
	glColor3d(255, 0, 0);
	glVertex3d(xPos - halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);

	//rectangular sides
	glColor3d(0, 255, 0);
	glVertex3d(xPos - halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos - halfwidth, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos, yPos - halflength, zPos + halfheight);

	glColor3d(0, 0, 255);
	glVertex3d(xPos + halfwidth, yPos - halflength, zPos - halfheight);
	glVertex3d(xPos + halfwidth, yPos + halflength, zPos - halfheight);
	glVertex3d(xPos, yPos + halflength, zPos + halfheight);
	glVertex3d(xPos, yPos - halflength, zPos + halfheight);
	glEnd();
};






