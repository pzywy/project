#pragma once
#include "Plant.h"
class Milt :
	public Plant
{
public:
	Milt(int posX, int posY, World* world) : Plant(ORGANISM::MILT, 0, posX, posY, world)
	{
	}
	

	void action()
	{
		//std::cout << "milt turn" << std::endl;
		repr();

	}
private:
	void repr()
	{
		int position = 5;
		

		for (int i = 0; i < 3; i++)
		{
			if (getRandom(0, 25) != 1)continue;//chance to reproduct


			position = reproduction();
			if (position == 5)return;

			int a = 1;
			int b = 1;

			a = getAFromPosition(position);
			b = getBFromPosition(position);

			if (world->board->get(posX + a, posY + b) == nullptr)
			{
				Organism* newPlant = new Milt(posX + a, posY + b, world);
				world->addOrganism(newPlant);
				world->board->set(newPlant->getX(), newPlant->getY(), newPlant);
			}

		}
	}

};
