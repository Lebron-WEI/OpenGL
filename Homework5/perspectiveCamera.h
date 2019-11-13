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
	//视点
	Vector eye;
	//视角向前的方向
	Vector front;
	//视点向上的方向
	Vector up;
	//视角宽度
	float fov;
	//视点向右的方向
	Vector right;
	float fovScale;
};
#endif