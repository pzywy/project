#pragma once
#include "Organism2.h"

enum DIRECTION
{
	TOP,//0
	BOTTOM,//1
	RIGHT,//2
	LEFT//3
};
class Animal : public Organism2
{
public:

	Animal(ORGANISM name, int strengh,int effort, int posX, int posY, World* world) 
		: Organism2(name, strengh, effort, posX, posY, world)
	{
	}

	virtual void reproduction() = 0; 

	bool collision(Organism* org)//returns if animal pass collision
	{

		if (org->getName() == ORGANISM::GUARANA)
		{
			strengh += 3;
			return true;
		}

		if (org->getName() == name)
		{
			reproduction();
			return false;
		}
		if (org->getName() == ORGANISM::BARSZCZ && name == ORGANISM::CYBEROWCA)
		{
			org->died();
			world->delOrganism(org);
			return true;
		}

		//deletes wolf berries after eaten
		if (org->getName() == ORGANISM::WILCZEJAGODY)
		{
			org->died();
			world->delOrganism(org);
			return true;
		}

		else if (strengh >= org->getStrengh())// or if turtle or sth
		{
			org->died();
			world->delOrganism(org);
			return true;
		}
		else
		{
			return false;
		}
	}
	void turn()
	{
		action();
		addAge();
	}
	virtual void action() = 0;
	void Attemptmove(int distance = 1)
	{
		bool succes = false;
		//checkColision();
		if (getRandom(0, 1))//if true vertical, else horizontal
		{
			if (getRandom(0, 1))
			{
				if (move(DIRECTION::TOP, distance))succes = true;
				else
					if(move(DIRECTION::BOTTOM, distance))succes = true;
			}
			else
			{
				if (move(DIRECTION::BOTTOM, distance)) succes=true;
				else
					if(move(DIRECTION::TOP, distance))succes = true;
			}
		}
		if(!succes)
		{
			if (getRandom(0, 1))
			{
				if (move(DIRECTION::RIGHT, distance));
				else
					move(DIRECTION::LEFT, distance);
			}
			else
			{
				if (move(DIRECTION::LEFT, distance));
				else
					move(DIRECTION::RIGHT, distance);
			}
		}



	}

	//(position are reverted)
	bool move(int direction, int distance=1)
	{
		int moveX = 0;
		int moveY = 0;
		bool passColision = true;
		
		switch (direction)
		{
		case DIRECTION::TOP:moveX = -1 * distance; break;
		case DIRECTION::BOTTOM:moveX = 1 * distance; break;
		case DIRECTION::RIGHT:moveY = 1 * distance; break;
		case DIRECTION::LEFT:moveY = -1 * distance; break;
		}


		if (posX + moveX >= 0 && posX + moveX < world->getSizeX()
			&& posY + moveY >= 0 && posY + moveY < world->getSizeY())
		{
			
			if (world->board->get(posX + moveX, posY + moveY)!=nullptr
				&&world->board->get(posX + moveX, posY + moveY)->isAlive())
			{
				passColision = collision(world->board->get(posX + moveX, posY + moveY));
			}

			if (passColision)
			{
				world->board->set(posX, posY, nullptr);
				posX += moveX;
				posY += moveY;
				world->board->set(posX, posY, this);
			}
			else
			{
				//if died
				if (world->board->get(posX + moveX, posY + moveY)->getName() == name)
				{

				}
				if (world->board->get(posX + moveX, posY + moveY)->getStrengh() >= strengh
					&& world->board->get(posX + moveX, posY + moveY)->getName() != name
					||(world->board->get(posX + moveX, posY + moveY)->getName()==ORGANISM::BARSZCZ 
						&& name == ORGANISM::CYBEROWCA)
					)
				{
					world->board->set(posX, posY, nullptr);
					died();
					world->toDelete = this;
				}

			}
			
			
		}
		else
		{
			//move fail
			return false;
		}
		//std::cout << "Pos: " << posX << ", " << posY << std::endl;
		return true;
	}
};

