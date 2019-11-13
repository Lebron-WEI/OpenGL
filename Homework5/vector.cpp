#include "vector.h"

Vector::Vector()
{
}
Vector::~Vector()
{
}
Vector::Vector(float posX, float posY, float posZ)
{
	x = posX;
	y = posY;
	z = posZ;
}

Vector Vector::operator+(Vector v)
{
	return Vector(x + v.x, v.y + y, v.z + z);
}
Vector Vector::operator-(Vector v)
{
	return Vector(x - v.x, y - v.y, z - v.z);
}
Vector Vector::operator*(float n)
{
	return Vector(x * n, y * n, z * n);
}
Vector Vector::operator/(float n)
{
	return Vector(x / n, y / n, z / n);
}
void Vector::getInfo()
{
	cout << "x:" << x << " y:" << y << " z:" << z << endl;
}
Vector Vector::abs()
{
	if (x < 0) x *= -1;
	if (y < 0) y *= -1;
	if (z < 0) z *= -1;
	return Vector(x, y, z);
}
float Vector::dotMul(Vector v2)
{
	return (x * v2.x + y * v2.y + z * v2.z);
}
Vector Vector::crossMul(Vector v2)
{
	Vector vNormal;
	vNormal.x = ((y * v2.z) - (z * v2.y));
	vNormal.y = ((z * v2.x) - (x * v2.z));
	vNormal.z = ((x * v2.y) - (y * v2.x));
	return vNormal;
}
float Vector::getLength()
{
	return  (float)sqrt(x * x + y * y + z * z);
}
Vector Vector::normalize()
{
	float length = getLength();
	x = x / length;
	y = y / length;
	z = z / length;
	return Vector(x, y, z);
}
void Vector::show()
{
	cout << "£¨ x:" << x << " y:" << y << " z £©" << z << endl;
}
float Vector::max()
{
	float tmp = MAX(y, z);
	return MAX(x, tmp);
}
float Vector::min()
{
	float tmp = MIN(y, z);
	return MIN(x, tmp);
}
float Vector::getDist(Vector v)
{
	float tmp = (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
	return sqrt(tmp);
}