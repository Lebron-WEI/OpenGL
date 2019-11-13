#include"perspectiveCamera.h"
perspectiveCamera::perspectiveCamera()
{

}
perspectiveCamera::~perspectiveCamera()
{
}
perspectiveCamera::perspectiveCamera(const Vector &_eye, const Vector &_front, const Vector &_up, float _fov)
{
	//视点
	eye = _eye;
	//视角向前的方向
	front = _front;
	//视点向上的方向
	up = _up;
	//视角宽度
	fov = _fov;
	//视点向右的方向
	right = front.crossMul(up);
	//up = right.crossMul(front);
	fovScale = tan(fov * (PI * 0.5f / 180));
}
Ray perspectiveCamera::generateRay(float x, float y)
{
	Vector r = right * ((x - 1.0f) * fovScale);
	Vector u = up * ((y - 1.0f) * fovScale);
	Vector way = front + r + u;
	way.normalize();
	return Ray(eye, way);
}