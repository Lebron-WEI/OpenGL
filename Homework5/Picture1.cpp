#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

#define WIDTH 400
#define HEIGHT 400

void myDisplay() 
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float colorSpan = 0.0005f;
	float color = 0.0f;
	float pixelSize = 2.0f;
	float posY = -1.0f;
	float posX = -1.0f;
	long maxDepth = 20;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//将原点移动到左下角
	glTranslatef(-1.0f, -1.0f, 0.0f);
	glPointSize(2.0);

	double dx = 2.0f / WIDTH;
	double dy = 2.0f / HEIGHT;
	float dD = 255.0f / maxDepth;

	glBegin(GL_POINTS);
	for (long y = 0; y < HEIGHT; ++y)
	{
		double sy = 2.0f - dy * y;
		for (long x = 0; x < WIDTH; ++x)
		{
			double sx = dx * x;
			float colorR = x * 1.0 / WIDTH;
			float colorB = y * 1.0 / HEIGHT;
			glColor3f(colorR, 0.0f, colorB);
			glVertex2f(sx, sy);
		}
	}
	glEnd();
	// 交换缓冲区
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Picture1");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}