#ifndef SHIP_H
#define SHIP_H
#include "Cell.h"

class Ship
{
private:   
/// Attributes
    int totalLives;
    int livesLeft;
    int ability_range;
    bool alive; 

public:
    /// Constructor
    Ship();
    Ship(const Ship& other) = delete;
    Ship(Ship&& other) = delete;
    Ship& operator= (const Ship& other) = delete;
    Ship& operator= (Ship&& other) = delete;

    /// Functions
     /*
    @brief It indicates the lives this ship has left.
    @param This function doesn't receive anything
    @return The amount of lives left.
    */
    int getLives();

    /*
    @brief It decreases the lives of this ship, when hit.
    @param This function doesn't receive anything.
    @return A boolean indicating if the ship is still alive.
    */
    bool loseLife();

    /*
    @brief This executes the special ability
    @param This function doesn't receive anything
    @return This function doesn't return anything
    */
    void specialAbility();
    
    /*
    @brief It clears this ship's data.
    @param This function doesn't receive anything.
    @return This function doesn't return anything.
    */
    void clearPosition();
};

#endif // SHIP_H
