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
	//缺省构造函数
	Vector();
	~Vector();

	//用户构造函数
	Vector(float posX, float posY, float posZ);

	//输出向量信息
	void getInfo();

	//矢量加法
	Vector operator+(Vector v);

	//矢量减法
	Vector operator-(Vector v);

	//数乘
	Vector operator*(float n);

	//数除
	Vector operator/(float n);

	//向量点积
	float dotMul(Vector v2);

	//向量叉乘
	Vector crossMul(Vector v2);

	//绝对值化
	Vector abs();

	//获取分量中的最大值
	float max();

	//获取分量的最小值
	float min();

	//获取矢量长度
	float getLength();

	//向量单位化
	Vector normalize();

	//求两点之间的距离
	float getDist(Vector v);

	//返回零向量
	static inline Vector zero() { return Vector(0, 0, 0); }

	//打印向量的分量值
	void show();
};


#endif // !VECTOR_H
