#ifndef INTERSECTRESULT_H
#define INTERSECTRESULT_H
#include "vector.h"
class IntersectResult {
public:
	//�Ƿ��н��㣬�н���Ϊ1������Ϊ0
	bool Hitted;
	//���㵽��Դ���ľ���
	float distance;
	//����λ��
	Vector position;
	//���㴦�ķ�����
	Vector normal;

	IntersectResult();
	~IntersectResult();
	IntersectResult(bool _Hitted, float _distance, Vector _position, Vector _normal);
	static inline IntersectResult notHitted() { return IntersectResult(); }
};
#endif // INTERSECTRESULT_H