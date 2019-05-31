#include "Vector.h"


Vector::Vector()
{
	x = 0;
	y = 0;
}

Vector::Vector(int X, int Y)
{
	x = X;
	y = Y;
}

Vector::~Vector()
{
}
Vector::Vector(const Vector &vec) {
	x = vec.x;
	y = vec.y;
}


Vector Vector::Opposite(Vector vecNew) {
	Vector newVec;
	newVec.x = -vecNew.x;
	newVec.y = -vecNew.y;
	return newVec;
}

void Vector::operator= (const Vector& vec) {
	this->x = vec.x;
	this->y = vec.y;
}
void Vector::operator+= (const Vector& v) {
	x += v.x;
	y += v.y;
}
Vector Vector::operator* (const float v) const{
	return Vector(x*v, y*v);
}