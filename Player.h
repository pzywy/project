#pragma once

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77

#include "Animal.h"
#include <conio.h>  // for getchar 
#include "Fire.h"
class Player :
	public Animal
{
private:
	
public:
	Player(int posX, int posY, World* world)
		: Animal(ORGANISM::PLAYER, 5, 4, posX, posY, world)
	{
	}
	void action()
	{
		//std::cout << "player turn" << std::endl;
		special();
		makeMove();
		if (specialCounter > 0)killAll();
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
			if ((input == 'a' || input== KEY_LEFT) && move(DIRECTION::LEFT, 1))
			{
				noInput = false;
			}
			else if ((input == 'd' || input == KEY_RIGHT) && move(DIRECTION::RIGHT, 1))
			{
				noInput = false;
			}
			else if ((input == 'w' || input == KEY_UP) && move(DIRECTION::TOP, 1))
			{
				noInput = false;
			}
			else if ((input == 's' || input==KEY_DOWN) && move(DIRECTION::BOTTOM, 1))
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
			else if (input == ' ')
			{
				activateSpecial();
				noInput = true;
			}

		} while (noInput);
	}

	//if specialcouter is > 0 it means special is on
	// if is <0 its on cooldown
	// 0 means avaible

	void special()
	{
		if (specialCounter > 0)
		{
			killAll();
			specialCounter--;
			
			if (specialCounter == 0)specialCounter = -5;
			world->print();
		}
		if (specialCounter < 0)specialCounter++;
	}
	void activateSpecial()

	{
		if (specialCounter == 0)
		{
			killAll();
			specialCounter = 5;
			world->print();
		}
	}

	void killAll()
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 5)continue;
			int a = 1;
			int b = 1;
			a = getAFromPosition(i);
			b = getBFromPosition(i);


			Organism* fire = new Fire(posX + a, posY + b, world);
			if (posX + a >= 0 && posX + a < world->getSizeX()
				&& posY + b >= 0 && posY + b < world->getSizeY()
				&& world->board->get(posX + a, posY + b) != nullptr)
			{
				

				Organism* org = world->board->get(posX + a, posY + b);
					org->died();
					world->delOrganism(org);
					//world->board->set(posX + a, posY + b, fire);
					
					
			}
			if (posX + a >= 0 && posX + a < world->getSizeX()
				&& posY + b >= 0 && posY + b < world->getSizeY())
			world->addOrganism(fire);

		}
	}
};

