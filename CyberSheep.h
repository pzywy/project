#pragma once
#include "Animal.h"
class CyberSheep :
    public Animal
{
public:
	CyberSheep(int posX, int posY, World* world)
		: Animal(ORGANISM::CYBEROWCA, 11, 4, posX, posY, world)
	{
	}

	void action()
	{
		if (world->borschtX == -1)
			Attemptmove();
		else
		{
			DIRECTION direction = DIRECTION::RIGHT;
			int right = -1;
			int top = -1;

			if (world->borschtX > posX)top = 0;
			else if (world->borschtX < posX) top = 1;
			else if (world->borschtY > posY) right = 1;
			else if (world->borschtY < posY) right = 0;
			else Attemptmove();

			if (top == 1 && move(DIRECTION::TOP));
			else if (top == 0 && move(DIRECTION::BOTTOM));
			else if (right == 1 && move(DIRECTION::RIGHT));
			else if (right == 0 && move(DIRECTION::LEFT));
			else Attemptmove();
		}
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
			Organism* newAnimal = new CyberSheep(posX + a, posY + b, world);
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