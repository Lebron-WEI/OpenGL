#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#define N 100
using namespace std;
int n, i;
float x[N], y[N];
float t, s;
float sx, sy;

void put_in_function()
{
	cout << "���������ζ�����" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "�������" << i << "��������� x=?, y=?, ��Χ0~800" << endl;
		cin >> x[i] >> y[i];
		cout << "���" << i << "�������������ʾΪ(" << x[i] << "," << y[i] << ",1)" << endl;
	}
	cout << "�������������ĵĺ������������ t=?�� s=��,��Χ0~800" << endl;
	cin >> t >> s;
	cout << "���������ŵĺ��������������� sx=?, sy=? " << endl;
	cin >> sx >> sy;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2f(x[i], y[i]);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2f(sx * (x[i] - t) + t, sy * (y[i] - s) + s);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Scale");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	put_in_function();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}