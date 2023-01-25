#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <vector>

class Game
{
public:
	Game();
	Game(int, int);

	void print(); //delete later
private:
	
	void draw();
	std::vector<std::vector<char>> board;
	int width;
	int height;
};

#endif