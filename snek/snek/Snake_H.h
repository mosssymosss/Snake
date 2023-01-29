#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <list>


class Snake
{
public:
	Snake();
	Snake(int, int);

	std::pair<int, int> getHeadCoords();
	std::list<std::pair<int, int>> getTail();
	int getLenght();
	int getDirection();
	void setDirection(int);

	void snek_update();
	bool colided(int, int);


	void operator = (Snake const& obj);
private:
	std::pair<int, int> head_coords;
	int direction;
	int lenght;
	std::list<std::pair<int, int>> tail;
};

#endif