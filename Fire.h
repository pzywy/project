
#include "Plant.h"
class Fire :
	public Plant
{
public:
	Fire(int posX, int posY, World* world) : Plant(ORGANISM::FIRE, 2, posX, posY, world)
	{
	}



	void action()
	{
		//del fire after 10 turns of faster if rand
		if (age > 10 || (age>2 && getRandom(0, 10 - age)))
		{
			world->board->set(posX, posY, nullptr);
			died();
			world->toDelete = this;
		}
	}

};
