#include "Snake_H.h"
#include "Directions_H.h"

Snake::Snake()
	:direction(Direction::DOWN)
	,lenght(2)
{
	head_coords = {12,3};
	tail.push_back(std::make_pair(12, 2));
	tail.push_back(std::make_pair(12, 1));
}

Snake::Snake(int x, int y)
	:direction(Direction::DOWN)
	,lenght(2)
{
	head_coords = { x , y };
	tail.resize(lenght);
	tail.push_back(std::make_pair(x, y-1));
	tail.push_back(std::make_pair(x, y-2));
}

void Snake::operator = (Snake const& obj)
{
	this->head_coords = obj.head_coords;
	this->direction = obj.direction;
	this->lenght = obj.lenght;
	this->tail = obj.tail;
}

std::pair<int, int> Snake::getHeadCoords()
{
	return head_coords;
}

std::list<std::pair<int, int>> Snake::getTail()
{
	return tail;
}

int Snake::getLenght()
{
	return lenght;
}

int Snake::getDirection()
{
	return direction;
}

void Snake::setDirection(int x)
{
	direction = x;
}

void Snake::snek_update()
{
	tail.push_front(head_coords);
	tail.pop_back();
	switch (direction)
	{
	case Direction::UP:
		head_coords.second = head_coords.second - 1;
		break;
	case Direction::RIGHT:
		head_coords.first = head_coords.first + 1;
		break;
	case Direction::DOWN:
		head_coords.second = head_coords.second + 1;
		break;
	case Direction::LEFT:
		head_coords.first = head_coords.first - 1;
		break;
	default:
		break;
	}
}

bool Snake::colided()
{
	return false;
}