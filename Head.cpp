#include "Head.h"
#include <glut.h>
#include <math.h>

Head::Head(int curWidth, int curHeight, Vector curPos, int curRadius)
{
	width = curWidth;
	height = curHeight;
	position = curPos;
}


Head::~Head()
{
}
Head::Head(const Head &obj){
	width = obj.width;
	height = obj.height;
	position = obj.position;
}
Vector Head::resultVec(0, 0);

void Head::DrawHead(Head &head){
	head.position += head.resultVec;
	if (head.position.getX() >= width - 2) {
		Vector Reverse1(-1, 0);
		head.resultVec += Reverse1;
	}
	if (head.position.getX() < 2) {
		Vector Reverse2(1, 0);
		head.resultVec += Reverse2;
	}
	if (head.position.getY() >= height - 2) {
		Vector Reverse3(0, -1);
		head.resultVec += Reverse3;
	}
	if (head.position.getY() < 2) {
		Vector Reverse4(0, 1);
		head.resultVec += Reverse4;
	}
	int _x = head.position.getX();
	int _y = head.position.getY();
	//glRectd(_x, _y, _x + 1, _y + 1);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	int radius = 1;
	for (int angle = 0; angle <= 360; angle+=10)
	{
		float dx = radius * cos(angle * 3.1415926 / 180);
		float dy = radius * sin(angle * 3.1415926 / 180);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(_x + dx, _y + dy);
	}

	glEnd();
}