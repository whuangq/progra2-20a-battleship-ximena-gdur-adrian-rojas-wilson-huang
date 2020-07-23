#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Visualizer.h"
#include <Ship.h>
#include <Ship1.h>
#include <Ship2.h>
#include <Ship3.h>
#include <Ship4.h>
#include <Ship5.h>

Board::Board() 
    : shipsLeft(TOTAL_SHIPS)
    , board (new Cell* [MATRIX_DIMENSIONS]())
    , listOfShips (std::vector<Ship*> (TOTAL_SHIPS))
    , specialAttack (false)
    
{
    for (int index = 0; index < MATRIX_DIMENSIONS; ++index)
        board[index] = new Cell[MATRIX_DIMENSIONS] ();

    for (int shipNumber = 1; shipNumber <= TOTAL_SHIPS; shipNumber++)
        Ship1* ship1= new Ship1();
        Ship2* ship2=new Ship2();
        Ship3* ship3= new Ship3();
        Ship4* ship4= new Ship4();
        Ship5* ship5= new Ship5();
        listOfShips.push_back(ship1);
        listOfShips.push_back(ship2);
        listOfShips.push_back(ship3);
        listOfShips.push_back(ship4);
        listOfShips.push_back(ship5);
    }

int Board::getShipsLeft()
{
    return this->shipsLeft;
}

std::vector<Ship> Board::getListOfShips()
{
    return this->listOfShips;
}

Cell& Board::getElement(int row, int col)
{
    return this->board[row][col];
}


// Sets the all the cells pointer to null.
void Board::clearGrid() {
    for (int rowIndex = 0; rowIndex < MATRIX_DIMENSIONS; rowIndex++) {
        for (int colIndex = 0; colIndex < MATRIX_DIMENSIONS; colIndex++) {
            board[rowIndex][colIndex] = board[rowIndex][colIndex].clearPosition();
        }
    }
}
// Place the ship in the given position of the booard.
void Board::setShips(int row, int col, int shipNumber) {
    board[row][col].assignShip(listOfShips[shipNumber]);
}
// Decrease the shipsLeft when the ships life gets to 0.
int Board::foundShips() {
    return shipsLeft -= 1;
}
/*void Board::updateBoard(bool a, int row, int col) {

}*/

bool Board::operator==(Board& other)
{
    return this == &other;
}
