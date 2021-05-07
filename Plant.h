#pragma once
#include "Organism2.h"
class Plant : public Organism2
{
public:

	Plant(ORGANISM name, int strengh, int posX, int posY, World* world) : Organism2(name, strengh, 0, posX, posY, world)
	{
	}
	int reproduction()
	{
		//std::cout << name << " Reproducted" << std::endl;

		int triedPositions = 1;

		while (triedPositions > 0)
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

