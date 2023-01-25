#include "Snake_H.h"

/*
	1				w				↑
4		2		a		d		←		→
	3				s				↓
*/

Snake::Snake()
	:speed(1)
	,direction(3)
	,lenght(2)
{
	head_coords = {11,4};
	tail.resize(lenght); //xz
	tail[0] = { 11,3 };
	tail[1] = { 11,2 };
}

Snake::Snake(int x, int y)
	:speed(1)
	,direction(3)
	,lenght(2)
{
	head_coords = { x,y };
	tail.resize(lenght);
	tail[0] = { x, y - 1 };
	tail[1] = { x, y - 2 };
}

std::pair<int, int> Snake::_getHeadCoords()
{
	return head_coords;
}

std::vector<std::pair<int, int>> Snake::_getTail()
{
	return tail;
}

int Snake::_getLenght()
{
	return lenght;
}