#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <iostream>
#include <vector> 

/* A constant which indicates the amount of ships for a player.*/
const int TOTAL_SHIPS = 5;
/* A constant which indicates the dimensions of the board*/
const int MATRIX_DIMENSIONS = 10;

/**
 *  Board class. Creates de board and place the ships of each player
 */
class Board
{

private:
    /// Attributes
    int shipsLeft;
    Cell** board;
    std::vector<Ship> listOfShips;
    bool specialAttack;

public:
    /// Constructor
    Board();

    /// Functions

    int getShipsLeft();

    std::vector<Ship> getListOfShips();

    Cell& getElement(int row, int col);

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
    //void updateBoard(bool a, int row, int col);

    /*
    @brief Compares two classes Board
    @param other A reference to the other Board to be compared
    @return A boolean value indicating whether they are equal or not
    */
    bool operator== (Board& other);
};

#endif // BOARD_H
