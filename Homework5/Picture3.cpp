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
#include "plane.h"
#include "planepiece.h"

using namespace std;

#define WIDTH 400
#define HEIGHT 400

/*void ChangeFunction(float h, float s, float l, float &r, float &g, float &b)
{
	if (s == 0)
	{
		r = l;
		g = l;
		b = l;
	}
	else
	{
		float q,p,h_k;
		if (l < 0.5)
			q = l * (1 + s);
		else
			q = l + s - l * s;
		p= 2 * l - q;
		h_k = h / 360.0;
		float t[3];
		t[0] = h_k + 1/3;
		t[1] = h_k;
		t[2] = h_k - 1/3;
		for (int i = 0; i < 3; i++)
		{
			while (t[i] > 1.0)
				t[i] = t[i] - 1.0;
			while (t[i] < 0.0)
				t[i] = t[i] + 1.0;
			if (t[i] < 1 / 6)
				t[i] = p + ((q - p) * 6 * t[i]);
			else if (t[i] >= 1 / 6 && t[i] < 1 / 2)
				t[i] = q;
			else if (t[i] >= 1 / 2 && t[i] < 2 / 3)
				t[i] = p + ((q - p) * 6 * (2 / 3 - t[i]));
			else
				t[i] = p;
		}
		r = t[0];
		g = t[1];
		b = t[2];
	}
}*/
void ChangeFunction(float h, float s, float l, float& r, float& g, float& b)
{
	//r = 0.0;  g = 0.0;  b = 0.0;
	if (s == 0.0)
	{
		r = l;
		g = 1;
		b = l;
	}
	else
	{
		float q, p, h_k;
		if (l < 0.5)
			q = l * (1 + s);
		else
			q = l + s - l * s;
		p = 2 * l - q;
		h_k = h / 360.0;

		r = h_k + 0.333333;
		while (r > 1.0)
			r = r - 1.0;
		while (r < 0.0)
			r = r + 1.0;
		if (r < 0.16667)
			r = p + ((q - p) * 6 * r);
		else if (r >= 0.16667 && r < 0.5)
			r = q;
		else if (r >= 0.5 && r < 0.66667)
			r = p + ((q - p) * 6 * (0.66667 - r));
		else
			r = p;

		g = h_k;
		while (g > 1.0)
			g = g - 1.0;
		while (g < 0.0)
			g = g + 1.0;
		if (g < 0.16667)
			g = p + ((q - p) * 6 * g);
		else if (g >= 0.16667 && g < 0.5)
			g = q;
		else if (g >= 0.5 && g < 0.66667)
			g = p + ((q - p) * 6 * (0.66667 - g));
		else
			g = p;

		b = h_k - 0.33333;
		while (b > 1.0)
			b = b - 1.0;
		while (b < 0.0)
			b = b + 1.0;
		if (b < 0.166667)
			b = p + ((q - p) * 6 * b);
		else if (b >= 0.166667 && b < 0.5)
			b = q;
		else if (b >= 0.5 && b < 0.66667)
			b = p + ((q - p) * 6 * (0.66667 - b));
		else
			b = p;

	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-1.0f, -1.0f, -1.0f);//将原点平移到左下角
	glPointSize(2.0);
	perspectiveCamera camera(Vector(0, 10, 10), Vector(0, 0, -1), Vector(0, 1, 0), 90);

	PlanePiece planepiece1 (Vector(2, 4, -5), Vector(-2, 4, -5), Vector(-2, 4, -7), Vector(2, 4, -7), Vector(0, 1, 0));
	PlanePiece planepiece2 (Vector(-1, 4, -7), Vector(1, 4, -7), Vector(1, 6, -7), Vector(-1, 6, -7), Vector(0, 0, 1));
	PlanePiece planepiece3 (Vector(10, 6, -7), Vector(-10, 6, -7), Vector(-10, 17, -7), Vector(10, 17, -7), Vector(0, 0, 1));
	Sphere sphere4 (Vector(0, 20, -7), 1.0);
	Sphere sphere5 (Vector(5, 20, -7), 1.0);
	Sphere sphere6 (Vector(-5, 20, -7), 1.0);
	Sphere sphere7 (Vector(-10, 20, -7), 1.0);
	Sphere sphere8 (Vector(10, 20, -7), 1.0);
	Sphere sphere9(Vector(-5, 7, 1), 3.0);
	Plane plane10(Vector(0, 1, 0), Vector(0, 4, 0));
	PlanePiece planepiece11(Vector(7, 5, -2), Vector(11, 5, -2), Vector(11, 6, -2), Vector(7, 6, -2), Vector(0, 0, 1));
	PlanePiece planepiece12(Vector(7, 5, -5), Vector(11, 5, -5), Vector(11, 6, -5), Vector(7, 6, -5), Vector(0, 0, -1));
	PlanePiece planepiece13(Vector(7, 5, -2), Vector(11, 5, -2), Vector(11, 5, -5), Vector(7, 5, -5), Vector(0, -1, 0));
	PlanePiece planepiece14(Vector(7, 6, -2), Vector(11, 6, -2), Vector(11, 6, -5), Vector(7, 6, -5), Vector(0, 1, 0));
	PlanePiece planepiece15(Vector(7, 5, -2), Vector(7, 6, -2), Vector(7, 6, -5), Vector(7, 5, -5), Vector(-1, 0, 0));
	PlanePiece planepiece16(Vector(11, 5, -2), Vector(11, 6, -2), Vector(11, 6, -5), Vector(11, 5, -5), Vector(1, 0, 0));

	float dx = 2.0f / WIDTH;
	float dy = 2.0f / HEIGHT;
	Vector lightpoint = Vector(10, 10, 10);
	double K_a = 0.3, K_d = 0.3, K_s = 0.3;
	double I_a, I_e;
	double I_1, I_2, I_3, I;
	float tmp1, tmp2;
	float K_n = 5;
	float h = 0, s = 0, l = 1;
	float r = 0, g = 0, b = 0;
	glBegin(GL_POINTS);
	for (long y = 0; y < HEIGHT; ++y)
	{
		float sy = 2 - dy * y;
		for (long x = 0; x < WIDTH; ++x)
		{
			float sx = dx * x;
			Ray ray(camera.generateRay(sx, sy));
			float minDistance = 25.0;
			IntersectResult minResult = IntersectResult::notHitted();
			IntersectResult result = planepiece1.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 0.0;
				s = 1.0;
			}
			result = planepiece2.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 0.0;
				s = 0.2;
			}
			result = planepiece3.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 0.0;
				s = 0.3;
			}
			result = sphere4.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray4(result.position, lightpoint - result.position);
				IntersectResult shadow_result4 = sphere4.isIntersected(shadow_ray4);
				if (shadow_result4.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 0.0;
					s = 1.0;
				}
			}
			result = sphere5.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray5(result.position, lightpoint - result.position);
				IntersectResult shadow_result5 = sphere5.isIntersected(shadow_ray5);
				if (shadow_result5.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 60.0;
					s = 1.0;
				}
			}
			result = sphere6.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray6(result.position, lightpoint - result.position);
				IntersectResult shadow_result6 = sphere6.isIntersected(shadow_ray6);
				if (shadow_result6.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 120.0;
					s = 1.0;
				}
			}
			result = sphere7.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray7(result.position, lightpoint - result.position);
				IntersectResult shadow_result7 = sphere7.isIntersected(shadow_ray7);
				if (shadow_result7.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 240.0;
					s = 1.0;
				}
			}
			result = sphere8.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray8(result.position, lightpoint - result.position);
				IntersectResult shadow_result8 = sphere8.isIntersected(shadow_ray8);
				if (shadow_result8.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 300.0;
					s = 1.0;
				}
			}
			result = sphere9.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray9(result.position, lightpoint - result.position);
				IntersectResult shadow_result9 = sphere9.isIntersected(shadow_ray9);
				if (shadow_result9.distance < -0.01)
				{
					minDistance = result.distance;
					minResult = result;
					h = 0.0;
					s = 1.0;
				}
			}
			result = plane10.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				Ray shadow_ray10(result.position, lightpoint - result.position);
				IntersectResult shadow_result10 = sphere9.isShadow(shadow_ray10);
				if (shadow_result10.Hitted==1) 
				{
					minResult.Hitted = 0;
				}
				else
				{
					minDistance = result.distance;
					minResult = result;
					h = 60.0;
					s = 1.0;
				}
			}
			result = planepiece11.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 0.1;
			}
			result = planepiece12.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 0.1;
			}
			result = planepiece13.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 1.0;
			}
			result = planepiece14.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 1.0;
			}
			result = planepiece15.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 1.0;
			}
			result = planepiece16.isIntersected(ray);
			if (result.Hitted && (result.distance < minDistance))
			{
				minDistance = result.distance;
				minResult = result;
				h = 300.0;
				s = 1.0;
			}
			if (minResult.Hitted)
			{
					Vector lightvector = minResult.position - lightpoint;
					//I_e = 1.0 / (0.1*pow((lightpoint.getDist(result.position)), 2));
					I_e = 1.0;
					I_a = 0.2 * I_e;
					I_1 = K_a * I_a;

					float tmp1_up = lightvector.dotMul(minResult.normal);
					float tmp1_down = (lightvector.getLength()) * ((minResult.normal.getLength()));
					tmp1 = abs(tmp1_up / tmp1_down);
					I_2 = K_d * I_e * tmp1;

					Vector Half = (lightvector + ray.getDirection()) / 2;
					float tmp2_up = Half.dotMul(minResult.normal);
					float tmp2_down = (Half.getLength()) * (minResult.normal.getLength());
					tmp2 = abs(tmp2_up / tmp2_down);
					I_3 = K_s * I_e * pow(tmp2, K_n);

					l = (I_1 + I_2 + I_3);
					ChangeFunction(h, s, l, r, g, b);
					glColor3f(r, g, b);
					glVertex2f(sx, sy);
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
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Picture3");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}