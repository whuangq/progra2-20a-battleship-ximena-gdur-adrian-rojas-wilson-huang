#include "Cell.h"
#include "Ship.h"

Cell::Cell()
    : shipPtr(nullptr)
    , attacked (false)
    , hasShip (false)
{
}

bool Cell::isEmpty()
{
    return hasShip;
}

void Cell::assignShip(Ship& ship)
{
    this->shipPtr = &ship;
    this->hasShip = true;
}

bool Cell::getAttacked()
{
    if ( this->attacked == false )
    { 
        if (!this->isEmpty())
        {
            this->attacked = true;
            if ((*shipPtr).loseLife() == false)
            {
                this->hasShip = false;
                this->shipPtr = nullptr;
            }
        }
        return true;
    } else
    {
        return false;
    }
}

void Cell::clearPosition()
{
    this->shipPtr = nullptr;
    attacked = false;
}

std::string Cell::getDescription()
{
    return std::string();
}


