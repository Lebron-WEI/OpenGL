#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

GLfloat pointsize = 1.0f;

void Bresenham_circle(GLint x_0, GLint y_0, GLint R)
{
    GLint x_1 = 0;
    GLint y_1 = R;
    GLfloat d = 1.25 - R;
    glPointSize(pointsize);
    GLint cx = x_1, cy = y_1;
    glVertex2i(x_0, y_0);
    while (cx <= cy)
    {
		glVertex2i(x_0 + cx, y_0 + cy);
		glVertex2i(x_0 - cx, y_0 - cy);
		glVertex2i(x_0 - cx, y_0 + cy);
		glVertex2i(x_0 + cx, y_0 - cy);
		glVertex2i(x_0 + cy, y_0 - cx);
		glVertex2i(x_0 - cy, y_0 - cx);
		glVertex2i(x_0 - cy, y_0 + cx);
		glVertex2i(x_0 + cy, y_0 + cx);
        
        cx++;
        if (d >= 0)
        {
			d = d + 2 * cx - 2 * cy + 5;
			cy = cy - 1;
        }
        else
        {
			d = d + 2 * cx + 3;
            cy = cy;
        }
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    Bresenham_circle(400, 400, 200);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Circle");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}