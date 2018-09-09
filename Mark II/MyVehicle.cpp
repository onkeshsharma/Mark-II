#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <map>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif


#include "Cylinder.h"
#include "MyVehicle.h"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapPrism.hpp"


#include <math.h>

void MyVehicle::draw()
{
	glPushMatrix();
	positionInGL();
	RectangularPrism rect(0,0,3,5,5,2);
	rect.draw();
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	TriangularPrism tri1(0, 0, 5.5,5,1,5);
	tri1.draw();
	tri1.setRotation(3);
	glPopMatrix();

	glPushMatrix();
	positionInGL();
	TrapPrism trap1(0, 5, 2.5, 3, 5, 3, 6 );
	trap1.draw();
    glPopMatrix();

	
	glPushMatrix();
	positionInGL();
	Cylinder wheel1(2, 4, 0.1, 0);
	 wheel1.draw();
	 glPopMatrix();
}
