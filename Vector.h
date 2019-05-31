#pragma once
class Vector
{
private:
	int x;
	int y;
public:
	Vector();
	Vector(int X, int Y);
	~Vector();
	Vector(const Vector &vec);
	int getX(void) { return x; }
	int getY(void) { return y; }
	Vector Opposite(Vector vecNew);
	void operator= (const Vector& vec);
	void operator+= (const Vector& v);
	Vector operator* (const float v) const;
};

