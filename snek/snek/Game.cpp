#include "Game_H.h"
#include "Snake_H.h"

#include <stdlib.h>
#include <conio.h>
#include <iostream>

Game::Game()
	:width(25)
	,height(25)
{
	draw();
}

Game::Game(int x, int y)
	:width(x)
	,height(y)
{
	Snake temp(x / 2, 4);
	snek = temp;
	draw();
}

void Game::draw()
{
	
	for (int i = 0; i < height; ++i)
	{
		std::vector<char> temp;
		if (i == 0 || i == height - 1)
		{
			for (int j = 0; j < width; ++j)
			{
				temp.push_back('#');
			}
		}
		else
		{
			for (int j = 0; j < width; ++j)
			{
				if (j == 0 || j == width - 1)
					temp.push_back('#');
				else
					temp.push_back(' ');
			}
		}
		board.push_back(temp);
	}
	board[snek._getHeadCoords().second][snek._getHeadCoords().first] = '@';
	std::deque<std::pair<int, int>> temp = snek._getTail();
	for (int i = 0; i < snek._getLenght(); ++i)
	{
		board[temp[i].second][temp[i].first] = '*';
	}
}


void Game::play()
{
	bool game_over = false;
	while (!game_over)
	{
		print();
		update();
		std::system("cls");
	}
}

void Game::update()
{
	char press = ' ';
	if(_kbhit())
		press = _getch();
	int dir = snek._getDirection();
	switch (press)
	{
	case 'w':
		if (dir != 3)
			snek._setDirection(1);
		break;
	case 'd':
		if (dir != 4)
			snek._setDirection(2);
		break;
	case 's':
		if (dir != 1)
			snek._setDirection(3);
		break;
	case 'a':
		if (dir != 2)
			snek._setDirection(4);
		break;
	default:
		break;
	}
	snek.snek_update();
	clear();
	draw();

}

void Game::clear()
{
	for (int i = 0; i < height; ++i)
	{
		board[i].clear();
	}
	board.clear();
}

/////////////////////////////////////////////////////////
void Game::print()
{

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << std::setw(2) << board[i][j];
		}
		std::cout << std::endl;
	}
	
}