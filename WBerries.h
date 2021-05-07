#pragma once
#include "Plant.h"
class WBerries :
    public Plant
{

public:
	WBerries(int posX, int posY, World* world) : Plant(ORGANISM::WILCZEJAGODY, 1000, posX, posY, world)
	{
	}

	void action()
	{
		//std::cout << "grass turn" << std::endl;
		repr();

	}
private:
	void repr()
	{
		int position = 5;


		for (int i = 0; i < 3; i++)
		{
			if (getRandom(0, 100) != 1)continue;//chance to reproduct


			position = reproduction();
			if (position == 5)return;

			int a = 1;
			int b = 1;

			a = getAFromPosition(position);
			b = getBFromPosition(position);

			if (world->board->get(posX + a, posY + b) == nullptr)
			{
				Organism* newPlant = new WBerries(posX + a, posY + b, world);
				world->addOrganism(newPlant);
				world->board->set(newPlant->getX(), newPlant->getY(), newPlant);
			}

		}
	}

	
};

