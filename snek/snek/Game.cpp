#include "Game_H.h"
#include "Snake_H.h"
#include "Directions_H.h"

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
	board[snek.getHeadCoords().second][snek.getHeadCoords().first] = '@';
	std::list<std::pair<int, int>> temp = snek.getTail();
	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		board[it->second][it->first] = '*';
	}
}


void Game::play()
{
	while (!game_over)
	{
		print_board();
		update();
		std::system("cls");
	}
}

void Game::update()
{
	char press = ' ';
	if(_kbhit())
		press = _getch();
	int dir = snek.getDirection();
	switch (press)
	{
	case 'w':
		if (dir != Direction::DOWN)
			snek.setDirection(Direction::UP);
		break;
	case 'd':
		if (dir != Direction::LEFT)
			snek.setDirection(Direction::RIGHT);
		break;
	case 's':
		if (dir != Direction::UP)
			snek.setDirection(Direction::DOWN);
		break;
	case 'a':
		if (dir != Direction::RIGHT)
			snek.setDirection(Direction::LEFT);
		break;
	default:
		break;
	}
	snek.snek_update();
	game_over = snek.colided();
	clear();
	draw();

}

void Game::clear()
{
	for (auto& row:board)
	{
		row.clear();
	}
	board.clear();
}

/////////////////////////////////////////////////////////
void Game::print_board()
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