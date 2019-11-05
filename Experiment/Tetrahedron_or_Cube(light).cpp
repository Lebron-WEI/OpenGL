/* Designed by Wei Xuchen*/
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

#define WIDTH 400
#define HEIGHT 400
#define Material_Vertex(ambient,diffuse,specular,emission,shininess,v) do{glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);glMaterialfv(GL_FRONT, GL_SPECULAR, specular);glMaterialfv(GL_FRONT, GL_EMISSION, emission);glMaterialfv(GL_FRONT, GL_SHININESS, shininess);glVertex3fv(v);}while(0)

//��ת�Ƕ�
static GLfloat angle = 120.0f;

//�������巨��������
void GetNormal_3(GLfloat Point1[], GLfloat Point2[], GLfloat Point3[])
{
	GLfloat Normal[3];
	int i;
	for (i = 0; i < 3; i++)
		Normal[i] = (Point1[i] + Point2[i] + Point3[i]) / 3;
	glNormal3fv(Normal);
}

//�������巨��������
void GetNormal_4(GLfloat Point1[], GLfloat Point2[], GLfloat Point3[], GLfloat Point4[])
{
	GLfloat Normal[4];
	int i;
	for (i = 0; i < 4; i++)
		Normal[i] = (Point1[i] + Point2[i] + Point3[i] + Point4[i]) / 4;
	glNormal3fv(Normal);
}

//������������ʼ�����
void myDisplay0(void)
{
	int list = 0;
	if (list == 0)//list==0��ʾ��ʾ�б����ڣ��������򴴽���ʾ�б�
	{
		//PointA(BLUE)
			GLfloat PointA[] = { 0.0f, 0.0f, -sqrt(6.0f) / 3 };
			GLfloat A_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
			GLfloat A_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
			GLfloat A_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
			GLfloat A_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			GLfloat A_shininess[] = { 30.0f };

		//PointB(RED)
			GLfloat PointB[] = { -sqrt(3.0f) / 3, 0.0f, 0.0f };
			GLfloat B_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
			GLfloat B_diffuse[] = { 0.5f, 0.0f, 0.0f, 1.0f };
			GLfloat B_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
			GLfloat B_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			GLfloat B_shininess[] = { 30.0f };

		//PointC(GREEN)
			GLfloat PointC[] = { sqrt(3.0f) / 6, 0.5f, 0.0f };
			GLfloat C_ambient[] = { 0.0f, 0.5f, 0.0f, 1.0f };
			GLfloat C_diffuse[] = { 0.0f, 0.5f, 0.0f, 1.0f };
			GLfloat C_specular[] = { 0.0f, 1.0f, 0.0f, 1.0f };
			GLfloat C_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			GLfloat C_shininess[] = { 30.0f };

		//PointD(YELLOW)
			GLfloat PointD[] = { sqrt(3.0f) / 6, -0.5f, 0.0f };
			GLfloat D_ambient[] = { 0.5f, 0.5f, 0.0f, 1.0f };
			GLfloat D_diffuse[] = { 0.5f, 0.5f, 0.0f, 1.0f };
			GLfloat D_specular[] = { 1.0f, 1.0f, 0.0f, 1.0f };
			GLfloat D_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			GLfloat D_shininess[] = { 30.0f };

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		//ƽ��ABC
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		GetNormal_3(PointA, PointB, PointC);
		//ƽ��ACD
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		GetNormal_3(PointA, PointC, PointD);
		//ƽ��CBD
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		GetNormal_3(PointC, PointB, PointD);
		//ƽ��BAD
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		GetNormal_3(PointB, PointA, PointD);

		glEnd();
		glEndList();

		glEnable(GL_DEPTH_TEST);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//��Դ
	{
		GLfloat sun_light_position[] = { 0.0f, 0.0f, 1.0f, 1.0f };
		GLfloat sun_light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
	}

	glPushMatrix();
	glRotatef(angle, 1.0, 0.5, 0.0);
	glCallList(list);
	glPopMatrix();
	glutSwapBuffers();
}

//������������ʼ�����
void myDisplay1(void)
{
	int list = 0;
	if (list == 0)//list==0��ʾ��ʾ�б����ڣ��������򴴽���ʾ�б�
	{
		//AE,BF.CG.DH
		//PointA(BLUE)
		GLfloat PointA[] = { 0.5f, 0.5f, 0.5f };
		GLfloat A_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat A_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat A_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
		GLfloat A_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat A_shininess[] = { 30.0f };

		//PointB(RED)
		GLfloat PointB[] = {0.5f, 0.5f, -0.5f };
		GLfloat B_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat B_diffuse[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat B_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat B_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat B_shininess[] = { 30.0f };

		//PointC(GREEN)
		GLfloat PointC[] = { 0.5f, -0.5f, 0.5f };
		GLfloat C_ambient[] = { 0.0f, 0.5f, 0.0f, 1.0f };
		GLfloat C_diffuse[] = { 0.0f, 0.5f, 0.0f, 1.0f };
		GLfloat C_specular[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		GLfloat C_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat C_shininess[] = { 30.0f };

		//PointD(YELLOW)
		GLfloat PointD[] = { 0.5f, -0.5f, -0.5f };
		GLfloat D_ambient[] = { 0.5f, 0.5f, 0.0f, 1.0f };
		GLfloat D_diffuse[] = { 0.5f, 0.5f, 0.0f, 1.0f };
		GLfloat D_specular[] = { 1.0f, 1.0f, 0.0f, 1.0f };
		GLfloat D_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat D_shininess[] = { 30.0f };

		//PointE(BLUE)
		GLfloat PointE[] = { -0.5f, -0.5f, -0.5f };
		GLfloat E_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat E_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat E_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
		GLfloat E_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat E_shininess[] = { 30.0f };

		//PointF(RED)
		GLfloat PointF[] = { -0.5f, -0.5f, 0.5f };
		GLfloat F_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat F_diffuse[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat F_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		GLfloat F_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat F_shininess[] = { 30.0f };

		//PointG(GREEN)
		GLfloat PointG[] = { -0.5f, 0.5f, -0.5f };
		GLfloat G_ambient[] = { 0.0f, 0.5f, 0.0f, 1.0f };
		GLfloat G_diffuse[] = { 0.0f, 0.5f, 0.0f, 1.0f };
		GLfloat G_specular[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		GLfloat G_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat G_shininess[] = { 30.0f };

		//PointH(YELLOW)
		GLfloat PointH[] = { -0.5f, 0.5f, 0.5f };
		GLfloat H_ambient[] = { 0.5f, 0.5f, 0.0f, 1.0f };
		GLfloat H_diffuse[] = { 0.5f, 0.5f, 0.0f, 1.0f };
		GLfloat H_specular[] = { 1.0f, 1.0f, 0.0f, 1.0f };
		GLfloat H_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat H_shininess[] = { 30.0f };

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_POLYGON);
		//ƽ��ABDC
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		GetNormal_4(PointA, PointB, PointD, PointC);
		//ƽ��ABGH
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(G_ambient, G_diffuse, G_specular, G_emission, G_shininess, PointG);
		Material_Vertex(H_ambient, H_diffuse, H_specular, H_emission, H_shininess, PointH);
		GetNormal_4(PointA, PointB, PointG, PointH);
		//ƽ��ACFH
		Material_Vertex(A_ambient, A_diffuse, A_specular, A_emission, A_shininess, PointA);
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		Material_Vertex(F_ambient, F_diffuse, F_specular, F_emission, F_shininess, PointF);
		Material_Vertex(H_ambient, H_diffuse, H_specular, H_emission, H_shininess, PointH);
		GetNormal_4(PointA, PointC, PointF, PointH);
		//ƽ��BDEG
		Material_Vertex(B_ambient, B_diffuse, B_specular, B_emission, B_shininess, PointB);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		Material_Vertex(E_ambient, E_diffuse, E_specular, E_emission, E_shininess, PointE);
		Material_Vertex(G_ambient, G_diffuse, G_specular, G_emission, G_shininess, PointG);
		GetNormal_4(PointB, PointD, PointE, PointG);
		//ƽ��EFHG
		Material_Vertex(E_ambient, E_diffuse, E_specular, E_emission, E_shininess, PointE);
		Material_Vertex(F_ambient, F_diffuse, F_specular, F_emission, F_shininess, PointF);
		Material_Vertex(H_ambient, H_diffuse, H_specular, H_emission, H_shininess, PointH);
		Material_Vertex(G_ambient, G_diffuse, G_specular, G_emission, G_shininess, PointG);
		GetNormal_4(PointE, PointF, PointH, PointG);
		//ƽ��EDCF
		Material_Vertex(E_ambient, E_diffuse, E_specular, E_emission, E_shininess, PointE);
		Material_Vertex(D_ambient, D_diffuse, D_specular, D_emission, D_shininess, PointD);
		Material_Vertex(C_ambient, C_diffuse, C_specular, C_emission, C_shininess, PointC);
		Material_Vertex(F_ambient, F_diffuse, F_specular, F_emission, F_shininess, PointF);
		GetNormal_4(PointE, PointD, PointC, PointF);

		glEnd();
		glEndList();

		glEnable(GL_DEPTH_TEST);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//��Դ
	{
		GLfloat sun_light_position[] = { 0.0f, 0.0f, 1.0f, 1.0f };
		GLfloat sun_light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
	}

	glPushMatrix();
	glRotatef(angle, 1.0, 0.5, 0.0);
	glCallList(list);
	glPopMatrix();
	glutSwapBuffers();
}

//��������ת����
void myIdle0()
{
	++angle;
	if (angle >= 360.0f)
		angle = 0.0f;
	myDisplay0();
}


//��������ת����
void myIdle1()
{
	++angle;
	if (angle >= 360.0f)
		angle = 0.0f;
	myDisplay1();
}


int main(int argc, char* argv[])
{
	// scan a number, 4 for a regular tetrahedron, 6 for a cube
	int a;
	cout << "����������4���������壩����6���������壩" << endl;
	cin >> a;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);

	if (a == 4)
	{
		glutCreateWindow("Tetrahedron");
		glutDisplayFunc(&myDisplay0);
		//glutIdleFunc(&myIdle0);
	}
	else if (a == 6)
	{
		glutCreateWindow("Cube");
		glutDisplayFunc(&myDisplay1);
		//glutIdleFunc(&myIdle1);
	}
	glutMainLoop();
	return 0;
}