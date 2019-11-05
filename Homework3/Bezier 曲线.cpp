#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>

#define N 100
using namespace std;
int n, i;
float x[N], y[N];

int fact(int k)//阶乘函数
{
	int result = 1;
	for (int j = 1; j <= k; result *= j, j++);
	return result;
}

void put_in_function()
{
	cout << "请输入Bezier曲线的点数" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i << "个点的坐标 x=?, y=?, 范围0~800" << endl;
		cin >> x[i] >> y[i];
	}
}

void myDisplay(void)
{
	GLfloat t = 0;
	float Bx, By;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	for (i = 0; i < n; i++)
		glVertex2f(x[i], y[i]);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS);
	while (t <= 1) 
	{
		Bx = 0.0f, By = 0.0f;
		for (i = 0; i < n; i++)
		{
			Bx = Bx + fact(n-1) / fact(i) /fact(n-1 - i) * x[i] * pow(1 - t, n-1 - i) * pow(t, i);
			By = By + fact(n-1) / fact(i) /fact(n-1 - i) * y[i] * pow(1 - t, n-1 - i) * pow(t, i);
		}
		glVertex2f(Bx, By);
		t = t + 0.001;
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