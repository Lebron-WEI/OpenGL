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

	//Բ�ĵ���Դ��������v
	Vector v = ray.getOrigin() - center;

	float a = v.dotMul(v) - radius * radius;
	float down = ray.getDirection().dotMul(ray.getDirection());

	//Բ�Ĺ�Դ��������v����߷����Inner Product
	float IP = ray.getDirection().dotMul(v);


	if (IP < 0) //��ʾ���߷���ļн�Ϊ�۽ǣ���ô���������������ཻ
	{
		//���η����б�ʽ�����ڵ���0�����н���
		float ID = IP * IP - a;
		if (ID > 0) 
		{
			//����
			result.Hitted = 1;

			//��Դ�㵽�ཻ��ľ���
			result.distance = (-IP - sqrt(ID))/ down ;

			//�ཻ�������
			result.position = ray.getPoint(result.distance);

			//�������ཻ�㴦�ķ�����
			result.normal = result.position - center;
			result.normal.normalize();
		}
	}
	return result;
}
IntersectResult Sphere::isShadow(Ray ray)
{
	IntersectResult result = IntersectResult::notHitted();
	//Բ�ĵ���Դ��������v
	Vector v = ray.getOrigin() - center;
	float a = v.dotMul(v) - radius * radius;
	//Բ�Ĺ�Դ��������v����߷����Inner Product
	float IP = ray.getDirection().dotMul(v);
	//if (IP < 0) //��ʾ���߷���ļн�Ϊ�۽ǣ���ô���������������ཻ
	
		//���η����б�ʽ�����ڵ���0�����н���
		float ID = IP * IP - a;
		if (ID > -0.1)
		{
			//�б�ʽ����0��˵�����ߴ�����·����������ô�����Ӧ������Ӱ
			result.Hitted = 1;
		}
		else
		{
			result.Hitted = 0;
		}
	

	return result;
}