#pragma once
#include "Animal.h"
#include <conio.h>  // for getchar 
class Player :
    public Animal
{
public:
	Player(int posX, int posY, World* world) 
		: Animal(ORGANISM::PLAYER,5, 4, posX, posY, world)
	{
	}
	void action()
	{
		//std::cout << "player turn" << std::endl;
		makeMove();
	}
	void reproduction()
	{

	}
	void makeMove()
	{

		if (!isAlive())return;
		bool noInput = true;
		do
		{
			char input = _getch();
			if (input == 'a' && move(DIRECTION::LEFT, 1))
			{
				noInput = false;
			}
			else if (input == 'd' && move(DIRECTION::RIGHT, 1))
			{
				noInput = false;
			}
			else if (input == 'w' && move(DIRECTION::TOP, 1))
			{
				noInput = false;
			}
			else if (input == 's' && move(DIRECTION::BOTTOM, 1))
			{
				noInput = false;
			}

			else if (input == 'q')
				noInput = false;

			else if (input == 'o')
			{
				world->gameOn = false;
				noInput = false;
			}

		} while (noInput);
	}
};

