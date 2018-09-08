#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#endif



#include "Cylinder.h"
#include <math.h>



Cylinder::Cylinder() {

}

Cylinder::Cylinder(double rad, double depth, double inc, bool rolling) {
	Radius = rad;
	Angle = 0.0;
	Depth = depth;
	turnAmt = inc;
}

void Cylinder::draw() {
	

	glColor3f(red, green, blue);
	glTranslatef(x, y, z);
	if (Roller) {
		glRotatef(RollingAmount, 0, 0, 1); //rotating wheel
	}

	glRotatef(rotation, 0, 1, 0);

	//Cylinder Wall
	glBegin(GL_QUAD_STRIP);
	Angle = 0.0;
	while (Angle < 2 * PI) { //this loop creates a series of circles from Depth/2.0 to -Depth/2.0 in order to form the cylinder wall. However, it increments by whatever value is specified in inc as mention in the constructor.
		glVertex3f(Radius*cos(Angle), Radius*sin(Angle), Depth / 2.0);
		glVertex3f(Radius*cos(Angle), Radius*sin(Angle), -Depth / 2.0);
		if (Angle <= 180.0) {
			glColor3f(0.5, 0.5, 0.5);
		}
		Angle = Angle + turnAmt;
	}
	glEnd();

	//Cylinder
	glBegin(GL_POLYGON);
	Angle = 0.0;
	while (Angle < 2 * PI) {
		glVertex3f(Radius * cos(Angle), Radius * sin(Angle), Depth / 2.0); //creates the cylinder disk using the value for Angle as mentioned above
		Angle = Angle + turnAmt;
	}
	glVertex3f(Radius, 0.0, Depth / 2.0);
	glEnd();
	glFlush();
}


void Cylinder::setRolling(bool rolling) {
	Roller = rolling;
}

double Cylinder::setrollVel(double vel) {
	Speed = vel;
	return Speed;
}

double Cylinder::SetTurnAmt(double vel)
{
	RollingAmount += vel; 
	return RollingAmount;
}

bool Cylinder::GetRolling() {
	return Roller;
}
void Cylinder::SetZRotation(double zRotate) {
	glRotatef(zRotate, 0, 1, 0);
}

Cylinder::~Cylinder()
{
}

