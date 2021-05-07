#pragma once
#include "Animal.h"
class Antelope :
    public Animal
{
public:
	Antelope(int posX, int posY, World* world)
		: Animal(ORGANISM::ANTYLOPA, 4, 4, posX, posY, world)
	{
	}

	void action()
	{
		Attemptmove(2);
	}
};
