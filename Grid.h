#pragma once
class Grid
{
private:
	int width;
	int height;
public:
	Grid();
	Grid(int curWidth, int curHeight);
	~Grid();
	void DrawGrid();
	void Unit(int x, int y);
};

