#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <deque>


class Snake
{
public:
	Snake();
	Snake(int, int);

	std::pair<int, int> _getHeadCoords();
	std::deque<std::pair<int, int>> _getTail();
	int _getLenght();
	int _getDirection();
	void _setDirection(int);

	void snek_update();

	void operator = (Snake const& obj);
private:
	std::pair<int, int> head_coords;
	int speed;
	int direction;
	int lenght;
	std::deque<std::pair<int, int>> tail;
};

#endif