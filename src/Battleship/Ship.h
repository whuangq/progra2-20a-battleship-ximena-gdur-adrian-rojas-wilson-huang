#ifndef SHIP_H
#define SHIP_H
#include "Cell.h"

class Ship
{
private:   
/// Attributes
    int lives;
    int ability_range;
    bool alive; 
    //Cell coordinates[];

public:
/// Constructor
    Ship();

/// Functions
    /*
    @brief It decreases the lives of this ship, when hit
    @param This function doesn't recieve anything
    @return This function doesn't return anything
    */
    void loseLife();

    /*
    @brief This executes the special ability
    @param This function doesn't recieve anything
    @return This function doesn't return anything
    
    void specialAbility();*/
    //void clearPosition();
};

#endif // SHIP_H
