#ifndef INTERSECTRESULT_H
#define INTERSECTRESULT_H
#include "vector.h"
class IntersectResult {
public:
	//是否有交点，有交点为1，否则为0
	bool Hitted;
	//交点到光源起点的距离
	float distance;
	//交点位置
	Vector position;
	//交点处的法向量
	Vector normal;

	IntersectResult();
	~IntersectResult();
	IntersectResult(bool _Hitted, float _distance, Vector _position, Vector _normal);
	static inline IntersectResult notHitted() { return IntersectResult(); }
};
#endif // INTERSECTRESULT_H