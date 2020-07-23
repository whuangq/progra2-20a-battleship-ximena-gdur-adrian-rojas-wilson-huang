#include "Cell.h"
#include "Ship.h"

Cell::Cell()
    : shipPtr(nullptr)
    , attacked (false)
{
}

bool Cell::isEmpty()
{
    return this->shipPtr == nullptr;
}

void Cell::assignShip(Ship ship)
{
    this->shipPtr = &ship;
}

void Cell::getAttacked()
{
    if ( this->attacked == false && !( this->isEmpty() ) )
    { 
        this->attacked = true;
        (*shipPtr).loseLife();
    }
}

void Cell::clearPosition()
{
    this->shipPtr = nullptr;
}


