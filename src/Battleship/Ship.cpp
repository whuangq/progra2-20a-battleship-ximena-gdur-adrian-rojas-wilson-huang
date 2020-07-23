#include "Ship.h"

Ship::Ship()
    : totalLives(1)
    , livesLeft (totalLives)
    , ability_range ()
    , alive (true)
{
}

int Ship::getLives()
{
    return this->livesLeft;
}

bool Ship::loseLife()
{
    --this->livesLeft;

    if(this->livesLeft ==0) {
        this->alive=false;
        return false;
    }
    return true;
}

void Ship::specialAbility()
{

}

void Ship::clearPosition()
{
    livesLeft = totalLives;
    alive = true;
}
