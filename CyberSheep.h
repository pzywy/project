#pragma once
#include "Animal.h"
class CyberSheep :
    public Animal
{
public:
	CyberSheep(int posX, int posY, World* world)
		: Animal(ORGANISM::CYBEROWCA, 11, 4, posX, posY, world)
	{
	}

	void action()
	{
		Attemptmove();
	}
};