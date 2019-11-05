#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>

#define WIDTH 400
#define HEIGHT 400
#define ColoredVertex(c,v) do{glColor3fv(c);glVertex3fv(v);}while(0)

static GLfloat angle = 120.0f;

void myDisplay(void)
{
	static int list = 0;
	if (list == 0)//如果显示列表不存在，则创建
	{
		GLfloat
			PointA[] = { 0.0f,0.0f,-sqrt(6.0f) / 3 },
			PointB[] = { -sqrt(3.0f) / 3,0.0f,0.0f },
			PointC[] = { sqrt(3.0f) / 6,0.5f,0.0f },
			PointD[] = { sqrt(3.0f) / 6,-0.5f,0.0f };
		GLfloat
			ColorR[] = { 1,0,0 },
			ColorG[] = { 0,1,0 },
			ColorB[] = { 0,0,1 },
			ColorY[] = { 1,1,0 };

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		//平面ABC
		ColoredVertex(ColorB, PointA);
		ColoredVertex(ColorR, PointB);
		ColoredVertex(ColorG, PointC);
		//平面ACD
		ColoredVertex(ColorB, PointA);
		ColoredVertex(ColorG, PointC);
		ColoredVertex(ColorY, PointD);
		//平面CBD
		ColoredVertex(ColorG, PointC);
		ColoredVertex(ColorR, PointB);
		ColoredVertex(ColorY, PointD);
		//平面BAD
		ColoredVertex(ColorR, PointB);
		ColoredVertex(ColorB, PointA);
		ColoredVertex(ColorY, PointD);

		glEnd();
		glEndList();

		glEnable(GL_DEPTH_TEST);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	glCallList(list);
	glPopMatrix();
	glutSwapBuffers();
}

/*void myIdle()
{
	++angle;
	if (angle >= 360.0f)
		angle = 0.0f;
	myDisplay();
}*/


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Tetrahedron");
	glutDisplayFunc(&myDisplay);
	//glutIdleFunc(&myIdle);
	glutMainLoop();
	return 0;
}