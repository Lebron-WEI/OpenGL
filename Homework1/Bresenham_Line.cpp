#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

GLfloat pointsize = 1.0f;

//�������������ڽ��жԳƲ���
void swap(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void Bresenham_line(GLint x_1, GLint y_1, GLint x_2, GLint y_2)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int dx = abs(x_2 - x_1),
		dy = abs(y_2 - y_1),
		yy = 0;
	glPointSize(pointsize);

	if (dx < dy)//ֱ���� x ��ļнǴ��� 45 ��ʱ��Ҫ���Գ�
	{
		yy = 1;
		swap(x_1, y_1);
		swap(x_2, y_2);
		swap(dx, dy);
	}

	int ix = (x_2 - x_1) > 0 ? 1 : -1,
		iy = (y_2 - y_1) > 0 ? 1 : -1,
		cx = x_1,
		cy = y_1,
		nextdy = dy * 2,
		nextdydx = (dy - dx) * 2,
		d = dy * 2 - dx;

	//ֱ���� x ��ļнǴ��� 45 �ȵ��������Ҫ���Գƣ�
	if (yy == 1)
	{
		while (cx != x_2)
		{
			if (d < 0)
			{
				d += nextdy;
			}
			else
			{
				cy += iy;
				d += nextdydx;
			}
			glVertex2i(cy, cx);//����x,y��˳���ٶԳƻ���
			cx += ix;
		}
	}

	//ֱ���� x ��ļн�С�� 45 �ȵ����������Ҫ�Գƣ�
	else
	{
		while (cx != x_2) {
			if (d < 0) {
				d += nextdy;
			}
			else {
				cy += iy;
				d += nextdydx;
			}
			glVertex2i(cx, cy);
			cx += ix;
		}
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	Bresenham_line(0, 800, 800, 0);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Line");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}