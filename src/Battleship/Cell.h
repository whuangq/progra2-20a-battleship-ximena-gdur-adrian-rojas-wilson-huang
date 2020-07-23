#ifndef CELL_H
#define CELL_H

#include <string>
#include "Ship.h"

class Cell
{
private:
    
    /// Attributes
    Ship* shipPtr;
    bool attacked;
    bool hasShip;

public:
    /// Constructor
    Cell();
    Cell(const Cell& other) = delete;
    Cell(Cell&& other) = delete;
    Cell& operator= (const Cell& other) = delete;
    Cell& operator= (Cell&& other) = delete;

    /// Functions
    /*
    @brief Checks if there is a pointer to a ship.
    @param This function doesn't have any parameters.
    @return A boolean value indicating if it is empty or not.
    */
    bool isEmpty();

    /*
    @brief Assigns a ship to shipPtr.
    @param ship A reference to a ship.
    @return It doesn't return aything.
    */
    void assignShip(Ship& ship);

    /*
    @brief Attacks this cell.
    @param This function doesn't have any parameters.
    @return It doesn't return aything.
    */
    bool getAttacked();

    /*
    @brief Clears that cell.
    @param This function doesn't have any parameters.
    @return It doesn't return aything.
    */
    void clearPosition();

    std::string getDescription();
};

#endif // CELL_H
