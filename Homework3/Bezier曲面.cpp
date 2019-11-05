#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>

#define N 100
using namespace std;
int n, i, j;
float x[N], y[N], z[N];

int fact(int k)//阶乘函数
{
	int result = 1;
	for (int l = 1; l <= k; result *= l, l++);
	return result;
}

void put_in_function()
{
	cout << "请输入Bezier曲面的点数" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i << "个点的坐标 x=?, y=?, z=? 范围0~800" << endl;
		cin >> x[i] >> y[i] >> z[i];
	}
}

void myDisplay(void)
{
	GLfloat u = 0, v = 0;
	float Bx, By, Bz;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//创建透视效果图
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 1.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1000.0, 1000.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	for (i = 0; i < n; i++)
		glVertex3f(x[i], y[i], z[i]);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS);
	while (u <= 1)
	{
		while (v <= 1)
		{
			Bx = 0.0f, By = 0.0f, Bz = 0.0f;
			for (j = 0; j < 3; j++)
			{
				for (i = 0; i < n; i++)
				{
					Bx = Bx + x[i] * fact(n - 1) / fact(i) / fact(n - 1 - i) * pow(1 - u, n - 1 - i) * pow(u, i) * fact(3 - 1) / fact(j) / fact(3 - 1 - j) * pow(1 - v, 3 - 1 - j) * pow(v, j);
					By = By + y[i] * fact(n - 1) / fact(i) / fact(n - 1 - i) * pow(1 - u, n - 1 - i) * pow(u, i) * fact(3 - 1) / fact(j) / fact(3 - 1 - j) * pow(1 - v, 3 - 1 - j) * pow(v, j);
					Bz = Bz + z[i] * fact(n - 1) / fact(i) / fact(n - 1 - i) * pow(1 - u, n - 1 - i) * pow(u, i) * fact(3 - 1) / fact(j) / fact(3 - 1 - j) * pow(1 - v, 3 - 1 - j) * pow(v, j);
				}
			}
			v = v + 0.001;
		}
		glVertex3f(Bx, By, Bz);
		u = u + 0.001;
	}
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Bezier");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	put_in_function();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}