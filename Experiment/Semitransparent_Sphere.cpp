/* Designed by Wei Xuchen*/
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>

#define WIDTH 400
#define HEIGHT 400

//��ת�Ƕ�
static GLfloat angle = 120.0f;

//���ù�Դ����
void setLight(void)
{
	GLfloat light_position[] = { 1.0f, 1.0f, -1.0f, 1.0f };
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

//���ò��ʺ���
void setMaterial(GLfloat ambient[], GLfloat diffuse[], GLfloat  specular[], GLfloat emission[], GLfloat shininess[])
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

//����
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setLight();

	//����Բ����(0, 0, 0.5)�뾶Ϊ0.3�Ĳ�͸����ɫ����A
	GLfloat A_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat A_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat A_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat A_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat A_shininess[] = { 30.0f };

	setMaterial(A_ambient, A_diffuse, A_specular, A_emission, A_shininess);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	//���ư�͸������ʱ������Ȼ�������Ϊֻ��
	glDepthMask(GL_FALSE);

	//����Բ����(0.2, 0, -0.5)�뾶Ϊ0.2�İ�͸����ɫ����B
	GLfloat CenterB[] = { 0.2f, 0.0f, -0.5f };
	GLfloat B_ambient[] = { 0.0f, 0.0f, 1.0f, 0.5f };
	GLfloat B_diffuse[] = { 0.0f, 0.0f, 1.0f, 0.5f };
	GLfloat B_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat B_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat B_shininess[] = { 30.0f };

	setMaterial(B_ambient, B_diffuse, B_specular, B_emission, B_shininess);
	glPushMatrix();
	glTranslatef(0.2f, 0.0f, -0.5f);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();

	//����Բ����(0.1, 0, 0)�뾶Ϊ0.15�İ�͸����ɫ����C
	GLfloat C_ambient[] = { 0.0f, 1.0f, 0.0f, 0.33f };
	GLfloat C_diffuse[] = { 0.0f, 1.0f, 0.0f, 0.33f };
	GLfloat C_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat C_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat C_shininess[] = { 30.0f };

	setMaterial(C_ambient, C_diffuse, C_specular, C_emission, C_shininess);
	glPushMatrix();
	glTranslatef(0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.15, 30, 30);
	glPopMatrix();

	//������ϣ�����Ȼ������ָ�Ϊ�ɶ���д
	glDepthMask(GL_TRUE);

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Semitrasparent_Sphere");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}