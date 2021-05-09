
#include "Plant.h"
class Grass :
    public Plant
{
public:
	Grass(int posX, int posY, World* world) : Plant(ORGANISM::GRASS, 0, posX, posY, world)
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

			if (getRandom(0, 35) != 1)return;//chance to reproduct


			position = reproduction();
			if (position == 5)return;

			int a = 1;
			int b = 1;

			a = getAFromPosition(position);
			b = getBFromPosition(position);

			if (world->board->get(posX + a, posY + b) == nullptr)
			{
				Organism* newPlant = new Grass(posX + a, posY + b, world);
				world->addOrganism(newPlant);
				world->board->set(newPlant->getX(), newPlant->getY(), newPlant);
			}

	}
};
