#pragma once
#include <Vector.h>

class Head
{
private:
	int width;
	int height;
	Vector position;
public:
	static Vector resultVec;
	Head(int curWidth, int curHeight, Vector curPos, int radius);
	~Head();
	Head(const Head &obj);
	void DrawHead(Head &head);
};

