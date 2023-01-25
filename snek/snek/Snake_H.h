#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>


class Snake
{
public:
	Snake();
	Snake(int, int);

	std::pair<int, int> _getHeadCoords();
	std::vector<std::pair<int, int>> _getTail();
	int _getLenght();

private:
	std::pair<int, int> head_coords;
	int speed;
	int direction;
	int lenght;
	std::vector<std::pair<int, int>> tail;
};

#endif