#include "sphere.h"
#include "intersectresult.h"
Sphere::Sphere()
{
}
Sphere::Sphere(Vector c, double r)
{
	center = c;
	radius = r;
}
Sphere::Sphere(Sphere &s)
{
	center = s.getCenter();
	radius = s.getRadius();
}
Sphere::~Sphere()
{
}
void Sphere::setCenter(Vector c)
{
	center = c;
}
void Sphere::setRadius(double r)
{
	radius = r;
}
Vector Sphere::getCenter()
{
	return center;
}
double Sphere::getRadius()
{
	return radius;
}
Vector Sphere::getNormal(Vector p)
{
	return p - center;
}
IntersectResult Sphere::isIntersected(Ray ray)
{
	IntersectResult result = IntersectResult::notHitted();

	//圆心到光源起点的向量v
	Vector v = ray.getOrigin() - center;

	float a = v.dotMul(v) - radius * radius;
	float down = ray.getDirection().dotMul(ray.getDirection());

	//圆心光源起点的向量v与光线方向的Inner Product
	float IP = ray.getDirection().dotMul(v);


	if (IP < 0) //表示两者方向的夹角为钝角，那么光线与球表面可以相交
	{
		//二次方程判别式，大于等于0代表有交点
		float ID = IP * IP - a;
		if (ID > 0) 
		{
			//命中
			result.Hitted = 1;

			//光源点到相交点的距离
			result.distance = (-IP - sqrt(ID))/ down ;

			//相交点的坐标
			result.position = ray.getPoint(result.distance);

			//球面上相交点处的法向量
			result.normal = result.position - center;
			result.normal.normalize();
		}
	}
	return result;
}
IntersectResult Sphere::isShadow(Ray ray)
{
	IntersectResult result = IntersectResult::notHitted();
	//圆心到光源起点的向量v
	Vector v = ray.getOrigin() - center;
	float a = v.dotMul(v) - radius * radius;
	//圆心光源起点的向量v与光线方向的Inner Product
	float IP = ray.getDirection().dotMul(v);
	//if (IP < 0) //表示两者方向的夹角为钝角，那么光线与球表面可以相交
	
		//二次方程判别式，大于等于0代表有交点
		float ID = IP * IP - a;
		if (ID > -0.1)
		{
			//判别式大于0，说明光线传播的路径上有球，那么这个点应该是阴影
			result.Hitted = 1;
		}
		else
		{
			result.Hitted = 0;
		}
	

	return result;
}