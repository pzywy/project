#pragma once
#include "Organism.h"
#include <iostream>

class Board
{
private:
	int sizeX, sizeY;
	Organism** board;


public:
	
	Board(int x, int y)
	{
		sizeX = x;
		sizeY = y;
		board = new Organism*[x * y];
		std::cout << "Created Board " << sizeX << " x " << sizeY << std::endl;
		prepareBoard();
	}

	void prepareBoard()
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				board[j + sizeX * i] = nullptr;
			}
		}
	}

	Organism* get(int x, int y)
	{
		if (x > sizeX or y > sizeY)
			throw std::out_of_range("out of range");
		return board[y + sizeY * x];
	}

	void set(int x, int y, Organism* org)
	{
		if (x > sizeX || y > sizeY)
			throw std::out_of_range("out of range");

		board[y + sizeY * x] = org;

	}

};


