#include "plane.h"

Plane::Plane()
{
	
}

Plane::~Plane()
{
	
}

Plane::Plane(Vector _normal, Vector _point)
{
	normal = _normal;
	point = _point;
}
IntersectResult Plane::isIntersected(Ray& ray)
{
	IntersectResult result = IntersectResult::notHitted();
	//����ƽ�淽������߷��̵ó����
	float a = (point - ray.getOrigin()).dotMul(normal);
	float b = ray.getDirection().dotMul(normal);
	float t = a / b;
	if (t > 0)
	{
		result.Hitted = 1;
		result.distance = t;
		result.position = ray.getPoint(result.distance);
		result.normal = normal;
	}
	return result;
}