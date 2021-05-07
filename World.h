#pragma once
#include <iostream>
#include "Organism.h"
#include <list>
#include <Windows.h>
#include "Board.h"
#include "Organism2.h"
class World
{
private:
    std::string name;
    std::list <Organism*> organism;
    int sizeX, sizeY;
    

public:
    Organism* toDelete = nullptr;
    Board* board;
    bool gameOn = true;

    World(std::string name, int sizeX=20, int sizeY=20) :name(name), sizeX(sizeX), sizeY(sizeY)
    {
        //std::cout << "Created World: " << name << std::endl;
        board = new Board(sizeX, sizeY);  
    }
    int getSizeX(){ return sizeX; }
    int getSizeY(){ return sizeY; }

    void delOrganism(Organism* org)
    {
        //std::cout << "Deleting organism: " << org->getName() << "there are:" 
        //    << organism.size() - 1 << std::endl;
        organism.remove(org);
        
    }

    void addOrganism(Organism* org)
    {
        if (org->getX() > sizeX || org->getY() > sizeY)
        { throw std::out_of_range("out of range"); return;}//check if is not out of range

        
        Organism* selectedPlace = board->get(org->getX(), org->getY());
        if (selectedPlace==nullptr || !selectedPlace->isAlive())
        {
            board->set(org->getX(), org->getY(), org);
            
            //std::cout << org->getName()<<" was placed in the world."<<std::endl;
        }
        else
        {
            //std::cout << "The place is taken by "<< selectedPlace->getName()
            //    <<"! Organism won't appear in the world!" << std::endl;
            return;
        }



        organism.insert(organism.end(), org);
        sortOrganisms();
        //std::cout << "Added Organism: " << org->getName()<<std::endl;
    }


    void sortOrganisms()
    {
        organism.sort([](Organism* lhs, Organism* rhs)
            {
                if (lhs->getEffort() == rhs->getEffort())
                {
                    return lhs->getAge() > rhs->getAge();
                }
                return lhs->getEffort() > rhs->getEffort();
            });
    }

    void print()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        //move console cursor to top
        COORD pos = { 0, 0 };
        SetConsoleCursorPosition(hConsole, pos);

        for (int i = 0; i < sizeX + 2; i++)std::cout << "X";
        std::cout << std::endl;
        for (int x = 0; x < sizeX; x++)
        {
            std::cout << "X";
            for (int y = 0; y < sizeY; y++)
            {
                if (board->get(x, y) != nullptr)
                    printOrganismSymbol(board->get(x, y)->getName());
                else
                    printOrganismSymbol(ORGANISM::UNDEFIND);
            }
            std::cout << "X";
            std::cout<<std::endl;
        }
        for (int i = 0; i < sizeX + 2; i++)std::cout << "X";
        std::cout << std::endl;
    }

    void printOrganismSymbol(ORGANISM symbol)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        switch (symbol) {
        case ORGANISM::PLAYER:SetConsoleTextAttribute(hConsole, 15);  std::cout << "P"; break;
        case ORGANISM::GRASS:SetConsoleTextAttribute(hConsole, 10); std::cout << "G"; break;
        case ORGANISM::MILT:SetConsoleTextAttribute(hConsole, 14); std::cout << "M"; break;
        case ORGANISM::GUARANA: SetConsoleTextAttribute(hConsole, 13);  std::cout << "G"; break;
        case ORGANISM::WILCZEJAGODY: SetConsoleTextAttribute(hConsole, 12);  std::cout << "J"; break;
        case ORGANISM::BARSZCZ: SetConsoleTextAttribute(hConsole, 16);  std::cout << "B"; break;
        case ORGANISM::WILK: SetConsoleTextAttribute(hConsole, 4);  std::cout << "W"; break;
        case ORGANISM::OWCA: SetConsoleTextAttribute(hConsole, 3);  std::cout << "O"; break;
        case ORGANISM::LIS: SetConsoleTextAttribute(hConsole, 11);  std::cout << "L"; break;
        case ORGANISM::ZOLW: SetConsoleTextAttribute(hConsole, 9);  std::cout << "Z"; break;
        case ORGANISM::ANTYLOPA: SetConsoleTextAttribute(hConsole, 8);  std::cout << "A"; break;
        case ORGANISM::CYBEROWCA: SetConsoleTextAttribute(hConsole, 3);  std::cout << "O"; break;
        case ORGANISM::UNDEFIND: std::cout << " "; break;
        }
                //SetConsoleTextAttribute(hConsole, 4);//red
                SetConsoleTextAttribute(hConsole, 7);

    }

    //if organism is not alive delete it from list during printing update or sth

    void prepareConsoleToPrint()
    {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 13;
        cfi.dwFontSize.Y = 15;
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_BOLD;
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = !true; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    void turn()

    {
        print();

        for (Organism* org : organism)
        {
            delOrganism(toDelete);
            toDelete = nullptr;

            if (org==nullptr||!org->isAlive())
            {     
                continue;
            }
            

            
            if (Organism2* o = static_cast<Organism2*>(org)) {
                o->turn();
            }
            //else if (Plant* o = dynamic_cast<Plant*>(org)) {
            //    o->turn();
            //}

            
        }
        
    }

    /*
    void prepareBoard(int worldSize)
    {
        system("cls");
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);


        COORD pos = { worldSize * 2 + 5, 0 };
        SetConsoleCursorPosition(out, pos);
        std::cout << "Move - wsad, q - wait, o - leave.";

        pos = { 0, 0 };
        SetConsoleCursorPosition(out, pos);
    }
    */

};


