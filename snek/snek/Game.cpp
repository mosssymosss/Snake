#include "Game_H.h"

Game::Game()
	:width(20)
	,height(20)
{
	draw();
}

Game::Game(int x, int y)
	:width(x)
	,height(y)
{
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
}

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