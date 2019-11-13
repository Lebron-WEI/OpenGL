#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include "ray.h"
class perspectiveCamera {
public:
	perspectiveCamera();
	~perspectiveCamera();
	perspectiveCamera(const Vector &_eye, const Vector &_front, const Vector &_up, float _fov);
	Ray generateRay(float x, float y);

private:
	//�ӵ�
	Vector eye;
	//�ӽ���ǰ�ķ���
	Vector front;
	//�ӵ����ϵķ���
	Vector up;
	//�ӽǿ��
	float fov;
	//�ӵ����ҵķ���
	Vector right;
	float fovScale;
};
#endif