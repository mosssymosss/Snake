#ifndef GAME_H
#define GAME_H

#include "Snake_H.h"
#include "Food_H.h"

#include <iostream>
#include <iomanip>
#include <vector>


class Game
{
public:
	Game();
	Game(int, int);

	

	void print(); //delete later
	void play();
private:
	
	void draw();
	void update();
	void clear();

private:

	Snake snek;
	std::vector<std::vector<char>> board;
	int width;
	int height;
};

#endif