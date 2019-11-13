#ifndef PLANE_H
#define PLANE_H
#include "vector.h"
#include "intersectresult.h"
#include "ray.h"

class Plane
{
private:
	//������
	Vector normal;
	//ƽ���ϵ�һ��
	Vector point;
public:
	Plane();
	Plane(Vector _normal, Vector _point);
	~Plane();
	virtual IntersectResult isIntersected(Ray& RAY);
};
#endif