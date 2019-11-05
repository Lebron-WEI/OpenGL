#include <gl/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>

std::pair<GLint, GLint> sdot, edot;
std::pair<GLint, GLint> center;
GLint radius;

GLubyte* pixels;
size_t totsz;

void drawLine()
{
	//Bresenham alg to draw a line
	GLint dx = abs(edot.first - sdot.first);
	GLint dy = abs(edot.second - sdot.second);
	GLint err = -abs(dy - dx);
	GLint x = sdot.first, y = sdot.second;
	GLint sx = (edot.first > sdot.first) ? 1 : -1;
	GLint sy = (edot.second > sdot.second) ? 1 : -1;
	while (x != edot.first || y != edot.second) {
		*(GLuint*)(pixels + y * 400 * 4 + x * 4) = 0x01ffffff;
		if (err >= 0 || dy < dx) x += sx;
		if (err >= 0 || dy > dx) y += sy;
		if (err < 0) 
			err += (dy < dx) ? dy : dx;
		else 
			err -= abs(dx - dy);
	}
	glDrawPixels(400, 400, GL_BGRA_EXT, GL_UNSIGNED_BYTE, pixels);
}

void drawCircle()
{
	//Bresenham alg to draw a circle
	GLint x = 0, y = radius;
	GLint err = 2 * radius - 2;
	while (x < y) {
		GLint _x[8] = {x + center.first, y + center.first, y + center.first, x + center.first,
						-x + center.first, -y + center.first, -y + center.first, -x + center.first};
		GLint _y[8] = { y + center.second, x + center.second, -x + center.second, -y + center.second,
						-y + center.second, -x + center.second, x + center.second, y + center.second };
		for (int i = 0; i < 8; i++)
			* (GLuint*)(pixels + _y[i] * 400 * 4 + _x[i] * 4) = 0x01ffff00;
		if (err > 0)
			err -= 2 * x + 3;
		else {
			err += 2 * (y - x) - 6;
			y--;
		}
		x++;
	}
	glDrawPixels(400, 400, GL_BGRA_EXT, GL_UNSIGNED_BYTE, pixels);
}

void renderFrame()
{
	memset(pixels, 0, totsz);
	drawLine();
	drawCircle();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(400, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OpenGL Window");

	totsz = sizeof(GLubyte) * 400 * 400 * 4;
	pixels = (GLubyte*)malloc(totsz);

	std::cout << "Please give the start/end point of a line:" << std::endl;
	std::cin >> sdot.first >> sdot.second;
	std::cin >> edot.first >> edot.second;

	std::cout << "Please give the center and radius of a circle:" << std::endl;
	std::cin >> center.first >> center.second;
	std::cin >> radius;

	glutDisplayFunc(renderFrame);
	glClearColor(255.0f, 0.0f, 0.0f, 1.f);
	glutMainLoop();

	free(pixels);
}