#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
public:
	Sheep(int posX, int posY, World* world)
		: Animal(ORGANISM::OWCA, 4, 4, posX, posY, world)
	{
	}

	void action()
	{
		Attemptmove();
	}
};

