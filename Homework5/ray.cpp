#include "ray.h"
Ray::Ray()
{
}
Ray::~Ray()
{
}
Ray::Ray(Vector o, Vector d)
{
	origin = o;
	direction = d;
}
void Ray::setDirection(Vector d)
{
	direction = d;
}
void Ray::setOrigin(Vector o)
{
	origin = o;
}
Vector Ray::getDirection()
{
	return direction;
}
Vector Ray::getOrigin()
{
	return origin;
}
Vector Ray::getPoint(double t)
{
	return origin + direction * t;
}