#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>
#include "vector.h"
#include "ray.h"
#include "sphere.h"
#include "intersectresult.h"
#include "perspectiveCamera.h"

using namespace std;

#define WIDTH 400
#define HEIGHT 400

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View
	glTranslatef(-1.0f, -1.0f, -1.0f);
	glPointSize(2.0);
	perspectiveCamera camera(Vector(0, 10, 10), Vector(0, 0, -1), Vector(0, 1, 0), 90);
	long maxDepth = 18;
	Sphere sphere1(Vector(0, 10, -10), 10.0);
	Vector lightpoint = Vector(5, 15, 5);
	float dx = 2.0f / WIDTH;
	float dy = 2.0f / HEIGHT;
	double K_a=0.1, K_d=0.4, K_s=0.4;
	double I_a, I_e;
	double I_1, I_2, I_3, I;
	float tmp1, tmp2;
	float g = 10;
	glBegin(GL_POINTS);
	for (long y = 0; y < HEIGHT; ++y)
	{
		float sy = 2 - dy * y;
		for (long x = 0; x < WIDTH; ++x)
		{
			float sx = dx * x;
			Ray ray(camera.generateRay(sx, sy));
			IntersectResult result = sphere1.isIntersected(ray);
			if (result.Hitted)
			{
				Ray shadow_ray(result.position, lightpoint - result.position);
				IntersectResult shadow_result = sphere1.isIntersected(shadow_ray);
				if (shadow_result.distance < -0.001f)
				{
					Vector lightvector = result.position - lightpoint;
					//I_e = 1.0 / (0.001*pow((lightpoint.getDist(result.position)), 2));
					I_e = 1.0;
					I_a = 0.2 * I_e;
					I_1 = K_a * I_a;

					float tmp1_up = lightvector.dotMul(result.normal);
					float tmp1_down = (lightvector.getLength()) * ((result.normal.getLength()));
					tmp1 = abs(tmp1_up / tmp1_down);
					I_2 = K_d * I_e * tmp1;

					Vector h = (lightvector + ray.getDirection()) / 2;
					float tmp2_up = h.dotMul(result.normal);
					float tmp2_down = (h.getLength()) * (result.normal.getLength());
					tmp2 = abs(tmp2_up / tmp2_down);
					I_3 = K_s * I_e * pow(tmp2, g);

					I = (I_1 + I_2 + I_3);
					glColor3d(I, I, I);
					glVertex2f(sx, sy);
				}
			}

		}
	}

	glEnd();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Picture2");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}