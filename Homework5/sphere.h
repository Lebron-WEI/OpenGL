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

	//获取物体表面一点的法线
	virtual Vector getNormal(Vector point);

	//用于判断射线和该物体的交点，包括是否有交点，交点坐标是多少等等
	virtual IntersectResult isIntersected(Ray RAY);
	//用于判断阴影
	virtual IntersectResult isShadow(Ray RAY);
	virtual ~Sphere();
};
#endif // SPHERE_H