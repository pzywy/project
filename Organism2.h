#pragma once
#include "Organism.h"
class Organism2 :
    public Organism
{
public:
    Organism2(ORGANISM name, int strengh, int effort, int posX, int posY, World* world)
        : Organism(name, strengh, effort, posX, posY, world)
    {
        
    }
    virtual void turn() = 0;

};

//That class is a little hack
//Organism couldn't be abstract becouse it's stored in array in Board Class
//But also virtual class was needed in order to call making turn in world Class
//So far this works well.