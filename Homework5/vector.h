#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <math.h>
#define MIN(x,y) (x)>(y)?(y):(x);
#define MAX(x,y) (x)>(y)?(x):(y);

using namespace std;

/*float MIN(float u, float v)
{
	if (u > v)
		return v;
	else
		return u;
}

float MAX(float u, float v)
{
	if (u < v)
		return v;
	else
		return u;
}*/

class Vector
{
public:
	float x, y, z;
	//ȱʡ���캯��
	Vector();
	~Vector();

	//�û����캯��
	Vector(float posX, float posY, float posZ);

	//���������Ϣ
	void getInfo();

	//ʸ���ӷ�
	Vector operator+(Vector v);

	//ʸ������
	Vector operator-(Vector v);

	//����
	Vector operator*(float n);

	//����
	Vector operator/(float n);

	//�������
	float dotMul(Vector v2);

	//�������
	Vector crossMul(Vector v2);

	//����ֵ��
	Vector abs();

	//��ȡ�����е����ֵ
	float max();

	//��ȡ��������Сֵ
	float min();

	//��ȡʸ������
	float getLength();

	//������λ��
	Vector normalize();

	//������֮��ľ���
	float getDist(Vector v);

	//����������
	static inline Vector zero() { return Vector(0, 0, 0); }

	//��ӡ�����ķ���ֵ
	void show();
};


#endif // !VECTOR_H
