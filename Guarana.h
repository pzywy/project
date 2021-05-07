#pragma once
#include "Plant.h"
class Guarana :
    public Plant
{
public:
	Guarana(int posX, int posY, World* world) : Plant(ORGANISM::GUARANA, 0, posX, posY, world)
	{
	}

	void action()
	{
		
		repr();

	}
	void repr()
	{
		int position = 5;

		if (getRandom(0, 50) != 1)return;//chance to reproduct


		position = reproduction();
		if (position == 5)return;

		int a = 1;
		int b = 1;

		a = getAFromPosition(position);
		b = getBFromPosition(position);

		if (world->board->get(posX + a, posY + b) == nullptr)
		{
			Organism* newPlant = new Guarana(posX + a, posY + b, world);
			world->addOrganism(newPlant);
			world->board->set(newPlant->getX(), newPlant->getY(), newPlant);
		}

	}

};

