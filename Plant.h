#pragma once
#include "Organism2.h"
class Plant : public Organism2
{
public:

	Plant(ORGANISM name, int strengh, int posX, int posY, World* world) : Organism2(name, strengh, 0, posX, posY, world)
	{
		isAnimal = false;
	}
	int reproduction()
	{

		int triedPositions = 1;

		while (triedPositions > 0)
		{
			int position = getRandom(1, 9);
			int a = 1;
			int b = 1;

			b = getBFromPosition(position);
			a = getAFromPosition(position);

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
			triedPositions--;
		}
		
	}
	void turn()
	{
		action();
		addAge();
	}

	virtual void action() = 0;
	
};

