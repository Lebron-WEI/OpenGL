#include "planepiece.h"

PlanePiece::PlanePiece()
{

}

PlanePiece::~PlanePiece()
{

}

PlanePiece::PlanePiece(Vector _point1, Vector _point2, Vector _point3, Vector _point4, Vector _normal)
{
	point1 = _point1;
	point2 = _point2;
	point3 = _point3;
	point4 = _point4;
	normal = _normal;
}
IntersectResult PlanePiece::isIntersected(Ray& ray)
{
	IntersectResult result = IntersectResult::notHitted();
	//联立平面方程与光线方程得出结果
	float a = (point1 - ray.getOrigin()).dotMul(normal);
	float b = ray.getDirection().dotMul(normal);
	float t = a / b;
	if (t < 0.0)
	{
		result.Hitted = 0;
	}
	else
	{
		result.distance = t;
		result.position = ray.getPoint(result.distance);
		Vector normal_p12 = (result.position - point1).crossMul(point1 - point2);
		Vector normal_p23 = (result.position - point2).crossMul(point2 - point3);
		Vector normal_p34 = (result.position - point3).crossMul(point3 - point4);
		Vector normal_p41 = (result.position - point4).crossMul(point4 - point1);
		float s12 = normal_p12.dotMul(normal);
		float s23 = normal_p23.dotMul(normal);
		float s34 = normal_p34.dotMul(normal);
		float s41 = normal_p41.dotMul(normal);
		if (s12 > 0 && s23 > 0 && s34 > 0 && s41 > 0 || s12 < 0 && s23 < 0 && s34 < 0 && s41 < 0) 
		{
			result.Hitted = 1;
			result.distance = t;
			result.position = ray.getPoint(result.distance);
			result.normal = normal;
		}
		else
		{
			result.Hitted = 0;
		}
	}
	return result;
}