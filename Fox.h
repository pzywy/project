#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
public:
	Fox(int posX, int posY, World* world)
		: Animal(ORGANISM::LIS, 3, 7, posX, posY, world)
	{
	}

	void action()
	{
		Attemptmove();
	}
};

