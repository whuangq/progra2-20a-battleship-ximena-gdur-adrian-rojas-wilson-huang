#ifndef SHIP_H
#define SHIP_H
#include "Cell.h"
#include <vector>

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
///
    /*
    @brief It decreases the lives of this ship, when hit
    @param This function doesn't recieve anything
    @return This function doesn't return anything
    */
    void loseLife();

    /*
    @brief This executes the special ability
    @param This function receives the coordinates to execute the special power in
    @return This function returns vector of coordinates to be affected
    */
    virtual vector<int> specialAbility(int i, int j);
    //void clearPosition();

    void setLives(int x){
        lives=x;
    }
};

#endif // SHIP_H
