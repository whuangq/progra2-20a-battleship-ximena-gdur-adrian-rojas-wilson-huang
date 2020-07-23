#include "Ship.h"

Ship::Ship()
    : lives ()
    , ability_range ()
    , alive (true)
{
}

void Ship::loseLife()
{
    --this->lives;
    if(this->lives==0)
        this->alive=false;
}

virtual vector<int> Ship::specialAbility()
{

}

/*void Ship::clearPosition()
{

}*/
