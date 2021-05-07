#pragma once
#include "Animal.h"
class Turtle :
    public Animal
{
public:
	Turtle(int posX, int posY, World* world)
		: Animal(ORGANISM::ZOLW, 5, 1, posX, posY, world)
	{
	}

	void action()
	{
		Attemptmove();
	}
};
