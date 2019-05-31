#pragma once
#include <vector>
#include <Head.h>

class Tail
{
private:
	std::vector<Head> tail;
public:
	Tail();
	~Tail();
	void AddNew(Head curHead);
	void DrawTail(Tail curTail);
};

