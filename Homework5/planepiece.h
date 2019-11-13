#ifndef PLANEPIECE_H
#define PLANEPIECE_H
#include "vector.h"
#include "intersectresult.h"
#include "ray.h"

class PlanePiece
{
private:
	Vector point1;
	Vector point2;
	Vector point3;
	Vector point4;
	Vector normal;
public:
	PlanePiece();
	PlanePiece(Vector _point1, Vector _point2, Vector _point3, Vector _point4, Vector normal);
	~PlanePiece();
	virtual IntersectResult isIntersected(Ray& RAY);
};
#endif