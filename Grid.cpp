#include "Grid.h"
#include <glut.h>


Grid::Grid()
{
}

Grid::Grid(int curWidth, int curHeight) {
	width = curWidth;
	height = curHeight;
}

Grid::~Grid()
{
}



void Grid::DrawGrid() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			Unit(x, y);
		}
	}
}
void Grid::Unit(int x, int y) {
	if (x < 1 || y < 1 || x > width - 2 || y > height - 2) {
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glLineWidth(1.0);
		glColor3f(0.5, 0.5, 0.5);
	}
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+1, y);
	glVertex2f(x+1, y+1);
	glVertex2f(x, y+1);
	glEnd();
}