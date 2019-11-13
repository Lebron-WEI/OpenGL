#ifndef SPHERE_H
#define SPHERE_H
#include "vector.h"
#include "intersectresult.h"
#include "ray.h"
class Sphere
{
private:
	Vector center;
	double radius;
public:
	Sphere();
	Sphere(Vector c, double r);
	Sphere(Sphere &s);
	void setCenter(Vector c);
	void setRadius(double r);
	Vector getCenter();
	double getRadius();

	//��ȡ�������һ��ķ���
	virtual Vector getNormal(Vector point);

	//�����ж����ߺ͸�����Ľ��㣬�����Ƿ��н��㣬���������Ƕ��ٵȵ�
	virtual IntersectResult isIntersected(Ray RAY);
	//�����ж���Ӱ
	virtual IntersectResult isShadow(Ray RAY);
	virtual ~Sphere();
};
#endif // SPHERE_H