
#include <iostream>

#include "World.h"
#include "Grass.h"
#include "Milt.h"
#include "Player.h"
#include "Guarana.h"
#include "WBerries.h"
#include "Borscht.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Antelope.h"
#include "CyberSheep.h"
#include "Fox.h"
#include "Turtle.h"

int main()
{
    const int worldSizeX = 30;
    const int worldSizeY = 30;

    int chanceFor[13];
    chanceFor[(int)ORGANISM::ANTYLOPA] = 15;
    chanceFor[(int)ORGANISM::BARSZCZ] = 10;
    chanceFor[(int)ORGANISM::CYBEROWCA] = 5;
    chanceFor[(int)ORGANISM::GRASS] = 40;
    chanceFor[(int)ORGANISM::GUARANA] = 20;
    chanceFor[(int)ORGANISM::LIS] = 20;
    chanceFor[(int)ORGANISM::MILT] = 20;
    chanceFor[(int)ORGANISM::OWCA] = 25;
    chanceFor[(int)ORGANISM::WILCZEJAGODY] = 7;
    chanceFor[(int)ORGANISM::WILK] = 10;
    chanceFor[(int)ORGANISM::ZOLW] = 15;
    chanceFor[(int)ORGANISM::BARSZCZ] = 7;


    //for(int i=0;i<13;i++)
    //    chanceFor[i] = 0;

    //chanceFor[(int)ORGANISM::CYBEROWCA] = 15;
    //chanceFor[(int)ORGANISM::BARSZCZ] = 15;
    World* world = new World("World",worldSizeX,worldSizeY);


    Player* player = new Player(10, 7, world);

    world->addOrganism(player);

    //Generate board
    for (int i = 0; i < worldSizeX; i++)
    {
        for (int j = 0; j < worldSizeY; j++)
        {
            if (i == player->getX() && j == player->getY())continue;

            int l = player->getRandom(0, 100);
            
            
            if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::GRASS])
            {
                Organism* org = new Grass(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::MILT])
            {
                Organism* org = new Milt(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::LIS])
            {
                Organism* org = new Fox(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::OWCA])
            {
                Organism* org = new Sheep(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::ZOLW])
            {
                Organism* org = new Turtle(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::ANTYLOPA])
            {
                Organism* org = new Antelope(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::WILK])
            {
                Organism* org = new Wolf(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::GUARANA])
            {
                Organism* org = new Guarana(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::CYBEROWCA])
            {
                Organism* org = new CyberSheep(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::WILCZEJAGODY])
            {
                Organism* org = new WBerries(i, j, world);
                world->addOrganism(org);
            }
            else if (player->getRandom(0, 1000) < chanceFor[(int)ORGANISM::BARSZCZ])
            {
                //prevent instant player death
                if (i + 1 == player->getX() || j + 1 == player->getY()
                    || i - 1 == player->getX() || j - 1 == player->getY()
                    )continue;

                Organism* org = new Borscht(i, j, world);
                world->addOrganism(org);
            }
            else{continue;}


        }

    }
   
    world->prepareConsoleToPrint();

    while (world->gameOn)
    {
        world->turn();
    }
}

//Problems with antylope
//if still will occure comment antylope exceptions parts in Animal.h
//and decrease atylope spawn rate