#pragma once
#include "Animal.h"
class Turtle :
    public Animal
{
public:
	Turtle(int posX, int posY, World* world)
		: Animal(ORGANISM::ZOLW, 2, 1, posX, posY, world)
	{
	}

	void action()
	{
		//move only in 25% cases
		if(getRandom(0,3)==0)
			Attemptmove();
	}

	void reproduction()
	{
		int position = 5;

		position = rep();
		if (position == 5)return;

		int a = 1;
		int b = 1;

		a = getAFromPosition(position);
		b = getBFromPosition(position);

		if (world->board->get(posX + a, posY + b) == nullptr)
		{
			Organism* newAnimal = new Turtle(posX + a, posY + b, world);
			world->addOrganism(newAnimal);
			world->board->set(newAnimal->getX(), newAnimal->getY(), newAnimal);
		}
	}
	int rep()
	{
		int position = getRandom(1, 9);
		int a = 1;
		int b = 1;

		b = ((position % 3) + 1) % 3;
		if (b == 2)b = -1;
		a = -1 + (int)(position / 4);

		//also check if not out of boundarys
		if (posX + a >= 0
			&& posX + a < world->getSizeX()
			&& posY + b >= 0
			&& posY + b < world->getSizeY()
			&& world->board->get(posX + a, posY + b) == nullptr)
		{
			return position;
		}
		else return 5;
	}
};
