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

	Animal(ORGANISM name, int strengh, int effort, int posX, int posY, World* world)
		: Organism2(name, strengh, effort, posX, posY, world)
	{
	}

	virtual void reproduction() = 0;

	int collision(Organism* org)//returns if animal pass collision
	{

		if (org->getName() == ORGANISM::GUARANA)
		{
			strengh += 3;
			return 1;
		}

		//if the same specie reproduct, and cancel move;
		if (org->getName() == name)
		{
			reproduction();
			return -1;
		}

		else if (org->getName() == ORGANISM::ZOLW && strengh < 5 && strengh>org->getStrengh())
		{
			return -1;
		}

		//cybersheep exterminates borscht
		else if (org->getName() == ORGANISM::BARSZCZ && name == ORGANISM::CYBEROWCA)
		{
			org->died();
			world->delOrganism(org);
			return 1;
		}
		//escape of antylopa
		else if ( org->getName() == ORGANISM::ANTYLOPA && getRandom(0, 1))
		{
			if (Organism2* o = static_cast<Organism2*>(org)) {
				o->turn();
			}

			return 1;
		}

		//deletes wolf berries after eaten
		if (org->getName() == ORGANISM::WILCZEJAGODY)
		{
			org->died();
			world->delOrganism(org);
			return 0;
		}

		if (strengh >= org->getStrengh())
		{
			org->died();
			world->delOrganism(org);
			return 1;
		}
		else
		{
			return 0;
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
					if (move(DIRECTION::BOTTOM, distance))succes = true;
			}
			else
			{
				if (move(DIRECTION::BOTTOM, distance)) succes = true;
				else
					if (move(DIRECTION::TOP, distance))succes = true;
			}
		}
		if (!succes)
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
	bool move(int direction, int distance = 1)
	{
		int moveX = 0;
		int moveY = 0;
		int passColision = 1;

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

			if (world->board->get(posX + moveX, posY + moveY) != nullptr
				&& world->board->get(posX + moveX, posY + moveY)->isAlive())
			{
				if (name == ORGANISM::ANTYLOPA && getRandom(0, 1))
					Attemptmove(distance);

				passColision = collision(world->board->get(posX + moveX, posY + moveY));
			}

			if (passColision == 1)
			{
				world->board->set(posX, posY, nullptr);
				posX += moveX;
				posY += moveY;
				world->board->set(posX, posY, this);
				return true;
			}
			else if (passColision == 0)

			{
				world->board->set(posX, posY, nullptr);
				died();
				world->toDelete = this;
				return false;
			}
			else if (passColision == -1)
			{
				return false;
			}
			else;


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
