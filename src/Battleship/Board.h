#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <iostream>
#include <vector> 

/**
 *  Board class. Creates de board and place the ships of each player
 */
class Board
{
private:
    int dim = 10;
    int shipsLeft = 5;
    Cell tablero[][];
    std::vector<Ship> ship;
public:
    
    Board();
    /*
    @brief Sets the all the cells pointer to null.
    @return Does not return anything.
    */
    void clearGrid();
    /*
    @brief Place the ship in the given position of the booard.
    @param row Row choosen to place de ship.
    @param col column choosen to place de ship.
    @param shipNumber Identifies the choosen ship for placement.
    @return Does not return anything.
    */
    void setShips(int row, int col, int shipNumber);
    /*
    @brief Decrease the shipsLeft when the ships life gets to 0.
    @return The number of ships left.
    */
    int foundShips();
    /*
    @brief Shows the current state od the board.
    @return Does not return anything.
    */
    void updateBoard(bool a, int row, int col);

};

#endif // BOARD_H
