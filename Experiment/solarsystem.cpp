#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>

static int day = 90;
float Pi=3.1415926535;

void myDisplay(void)
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000, 200000, 0, 0, 0, 0, 0, 1);

	//sun
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600, 20, 20);
	//earth
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000, 0.0f, 0.0f);
	glutSolidSphere(15945, 20, 20);
	//moon
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day/360.0*30.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000, 0.0f, 0.0f);
	glutSolidSphere(4345, 20, 20);
	glFlush();
	glutSwapBuffers();
}

void myIdle()
{
	day++;
	if (day >= 360)
		day = 0;
	myDisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Solarsystem");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return 0;
}