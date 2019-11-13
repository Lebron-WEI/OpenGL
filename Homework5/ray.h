#ifndef RAY_H
#define RAY_H
#include <iostream>
#include "vector.h"
#define PI 3.14159
using namespace std;
class Ray
{
private:
	Vector origin;
	Vector direction;
public:
	Ray();
	Ray(Vector o, Vector d);
	~Ray();
	void setOrigin(Vector o);
	void setDirection(Vector d);
	Vector getOrigin();
	Vector getDirection();
	//通过向射线的参数方程传入参数t而获得在射线上的点
	Vector getPoint(double t);

};
#endif