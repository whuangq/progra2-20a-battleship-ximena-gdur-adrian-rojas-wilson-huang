#ifndef CELL_H
#define CELL_H

#include "Ship.h"

class Cell
{
private:
    Ship* shipPtr;
    bool attacked;

public:
    Cell();
    bool isEmpty();
    void assignShip(Ship ship);
    void getAttacked();
    void clearPosition();
};

#endif // CELL_H
