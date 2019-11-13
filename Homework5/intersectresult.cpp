#include "intersectresult.h"
IntersectResult::IntersectResult()
{
	//¶¨Òå¿Õº¯Êý
	Hitted = 0;
}
IntersectResult::~IntersectResult()
{

}
IntersectResult::IntersectResult(bool _Hitted, float _distance, Vector _position, Vector _normal)
{
	distance = _distance;
	Hitted = _Hitted;
	position = _position;
	normal = _normal;
}