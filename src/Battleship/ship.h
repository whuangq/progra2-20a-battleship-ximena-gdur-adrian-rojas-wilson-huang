#ifndef SHIP_H
#define SHIP_H
#include "cell.h"

class Ship
{
public:    
    int lives,ability_range;
    bool alive; 
    Cell coordinates[];

    Ship();
    void loseLife();
    void specialAbility();
    void clearPosition();
};

#endif // SHIP_H
