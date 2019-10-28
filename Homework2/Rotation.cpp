#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#define N 100
using namespace std;
int n, i;
float x[N], y[N];
float t, s;
float a;

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
	cout << "��������תԲ�ĵĺ������������ t=?�� s=��,��Χ0~800" << endl;
	cin >> t >> s;
	cout << "��������ʱ����ת���� a=��" << endl;
	cin >> a;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2i(x[i], y[i]);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2f(cos(a)*(x[i]-t)+sin(-a)*(y[i]-s)+t, sin(a)*(x[i] - t) + cos(a)*(y[i] - s)+s);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Rotation");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	put_in_function();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}