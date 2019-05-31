#include "Tail.h"



Tail::Tail()
{
}


Tail::~Tail()
{
}
void Tail::AddNew(Head curHead) {
	if (tail.size() >= 7){
		tail.erase(tail.begin());
		std::vector<Head>(tail).swap(tail);
	}
	tail.push_back(curHead);
}
void Tail::DrawTail(Tail curTail) {
	for (auto &curElement : curTail.tail) {
		curElement.DrawHead(curElement);
	}
}