#pragma once
#include <iostream>
#include "World.h"

class World;
enum class ORGANISM : int
{
	PLAYER,
	GRASS,
	MILT,
	GUARANA,
	WILCZEJAGODY,
	BARSZCZ,
	WILK,
	OWCA,
	LIS,
	ZOLW,
	ANTYLOPA,
	CYBEROWCA,
	UNDEFIND,
	FIRE

};
std::ostream& operator<<(std::ostream& lhs, ORGANISM o) {
	switch (o) {
	case ORGANISM::PLAYER: lhs << "Gracz"; break;
	case ORGANISM::GRASS: lhs << "Trawa"; break;
	case ORGANISM::MILT: lhs << "Mlecz"; break;
	case ORGANISM::GUARANA: lhs << "Guarana"; break;
	case ORGANISM::WILCZEJAGODY: lhs << "Wilcze Jagody"; break;
	case ORGANISM::BARSZCZ: lhs << "Barszcz Sosnowskiego"; break;
	case ORGANISM::WILK: lhs << "Wilk"; break;
	case ORGANISM::OWCA: lhs << "Owca"; break;
	case ORGANISM::LIS: lhs << "Lis"; break;
	case ORGANISM::ZOLW: lhs << "Zó³w"; break;
	case ORGANISM::ANTYLOPA: lhs << "Antylopa"; break;
	case ORGANISM::CYBEROWCA: lhs << "Cyber-Owca"; break;
	case ORGANISM::UNDEFIND: lhs << "UNDEFIND"; break;
	case ORGANISM::FIRE: lhs << "UNDEFIND"; break;
	}
	return lhs;
}




class Organism
{
	
protected:
	ORGANISM name;
	int strengh;
	int effort;
	int posX;
	int posY;
	int age;//in turns
	bool alive;
	bool isAnimal;
	World* world;
	int specialCounter = 0;
	
public:
	bool operator == (const Organism& org) const { return getID() == org.getID(); }
	Organism()
	{
		name = ORGANISM::UNDEFIND, strengh = 0, effort = 0, effort = 0, posX = 0, posY = 0, age = 0, alive = false,world=nullptr;
	}
	Organism(ORGANISM name, int strengh, int effort, int posX, int posY, World* world)
		: name(name), strengh(strengh), effort(effort), posX(posX), posY(posY), world(world)
	{
		age = 0;
		alive = true;
		//std::cout << "Created Organism: " << name << " with strengh " << strengh << ", effort " 
		//	<< effort <<", on position (" << posX << ", " << posY << ")"<<std::endl;
	}
	
	//virtual void turn() = 0;

	unsigned long getID() const
	{
		return (unsigned long)this;//unique ID
	}




	int getEffort() { return effort; }
	int getStrengh() { return strengh; }
	int getX() { return posX; }
	int getY() { return posY; }
	int getAge() { return age; }
	ORGANISM getName() { return name; }
	bool isAlive() {return alive; }
	bool getIsAnimal() { return isAnimal; }
	int getSpecial() { return specialCounter; }

	void setEffort(int e) { effort = e; }
	void setStrengh(int s) {strengh =s; }
	void setX(int x) {posX = x; }
	void setY(int y) {posY = y; }
	void addAge(int a = 1) { age += a; }

	std::string getStringName(ORGANISM o) {
		switch (o) {
		case ORGANISM::PLAYER: return  "Gracz";
		case ORGANISM::GRASS: return  "Trawa";
		case ORGANISM::MILT: return "Mlecz";
		case ORGANISM::GUARANA: return "Guarana";
		case ORGANISM::WILCZEJAGODY: return  "Wilcze Jagody";
		case ORGANISM::BARSZCZ: return "Barszcz Sosnowskiego";
		case ORGANISM::WILK: return "Wilk";
		case ORGANISM::OWCA: return "Owca";
		case ORGANISM::LIS: return "Lis";
		case ORGANISM::ZOLW: return "Zó³w";
		case ORGANISM::ANTYLOPA: return "Antylopa";
		case ORGANISM::CYBEROWCA: return "Cyber-Owca";
		case ORGANISM::UNDEFIND: return "UNDEFIND";
		}
	}

	int getAFromPosition(int pos)
	{
		return -1 + (int)(pos / 3.5);
	}

	int getBFromPosition(int pos)
	{
		int b = 1;
		b = ((pos % 3) + 1) % 3;
		if (b == 2)b = -1;
		return b;
	}

	void died()
	{
		alive = false;	
		//std::cout << "Organism: " << name <<" died in age "<<age<<". " << std::endl;
		//delete this;
	}

	//couldn't be abstract becouse board wont create array of abstract class

	int getRandom(int min, int max)
	{
		static bool first = true;
		if (first)
		{
			srand(time(NULL));
			first = false;
		}
		return min + rand() % ((max + 1) - min);
	}

	~Organism()
	{
		//std::cout<<"Deleted Organism"<<name<<std::endl;
	}
};

