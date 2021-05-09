#pragma once
#include "Plant.h"
class Borscht :
    public Plant
{
public:
	Borscht(int posX, int posY, World* world) : Plant(ORGANISM::BARSZCZ, 1000, posX, posY, world)
	{
	}



	void action()
	{

		killAll();
		repr();

	}

	void killAll()//plants no

	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 5)continue;
			int a = 1;
			int b = 1;
			a = getAFromPosition(i);
			b = getBFromPosition(i);



			if (posX + a >= 0 && posX + a < world->getSizeX()
				&& posY + b >= 0 && posY + b < world->getSizeY()
				&& world->board->get(posX + a, posY + b) != nullptr)
			{
				Organism* org = world->board->get(posX + a, posY + b);
				if (org->getIsAnimal() && org->getName() != ORGANISM::CYBEROWCA)
				{
					org->died();
					world->delOrganism(org);
					world->board->set(posX + a, posY + b, nullptr);
				}
			}

		}
	}
private:
	void repr()
	{
		int position = 5;

		if (getRandom(0, 300) != 1)return;//chance to reproduct


		position = reproduction();
		if (position == 5)return;

		int a = 1;
		int b = 1;

		b = ((position % 3) + 1) % 3;
		if (b == 2)b = -1;
		a = -1 + (int)(position / 4);

		if (world->board->get(posX + a, posY + b) == nullptr)
		{
			Organism* newPlant = new Borscht(posX + a, posY + b, world);
			world->addOrganism(newPlant);
			world->board->set(newPlant->getX(), newPlant->getY(), newPlant);
		}

	}
};


