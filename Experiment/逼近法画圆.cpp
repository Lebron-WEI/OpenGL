#include <GL/glut.h>
#include <math.h>
#include <float.h>
int n = 100;
float R = 0.5f;
float Pi = 3.1415926535f;
void myDisaplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex2f(R * cos(2 * Pi / n * i), R * sin(2 * Pi / n * i));
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("±Æ½ü·¨»­Ô²");
	glutDisplayFunc(&myDisaplay);
	glutMainLoop();
	return 0;
}