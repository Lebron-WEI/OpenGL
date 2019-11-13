#include"perspectiveCamera.h"
perspectiveCamera::perspectiveCamera()
{

}
perspectiveCamera::~perspectiveCamera()
{
}
perspectiveCamera::perspectiveCamera(const Vector &_eye, const Vector &_front, const Vector &_up, float _fov)
{
	//�ӵ�
	eye = _eye;
	//�ӽ���ǰ�ķ���
	front = _front;
	//�ӵ����ϵķ���
	up = _up;
	//�ӽǿ��
	fov = _fov;
	//�ӵ����ҵķ���
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