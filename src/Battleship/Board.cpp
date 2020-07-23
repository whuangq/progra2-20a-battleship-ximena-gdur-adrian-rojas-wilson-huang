#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Visualizer.h"

Board::Board() 
    : shipsLeft(TOTAL_SHIPS)
    , board (new Cell* [MATRIX_DIMENSIONS]())
    , listOfShips (std::vector<Ship> (TOTAL_SHIPS))
    , specialAttack (false)
    
{
    for (int index = 0; index < MATRIX_DIMENSIONS; ++index)
        board[index] = new Cell[MATRIX_DIMENSIONS] ();

    /*for (int shipNumber = 1; shipNumber <= TOTAL_SHIPS; shipNumber++)
        listOfShips*/
}

Board::~Board()
{
    for (int cellIndex = 0; cellIndex < MATRIX_DIMENSIONS; cellIndex++)
        delete[] board [cellIndex];

    delete[] board;
}


bool Board::getStatusSpecialAttack()
{
    return this->specialAttack;
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


bool Board::operator==(Board& other)
{
    return this == &other;
}


// Sets the all the cells pointer to null.
void Board::clearGrid() {
    for (int rowIndex = 0; rowIndex < MATRIX_DIMENSIONS; rowIndex++) {
        for (int colIndex = 0; colIndex < MATRIX_DIMENSIONS; colIndex++) {
            this->board[rowIndex][colIndex].clearPosition();
        }
    }
}

// Place the ship in the given position of the booard.
void Board::setShips(int row, int col, Ship& ship) {
    board[row][col].assignShip(ship);
}

// Decrease the shipsLeft when the ships life gets to 0.
int Board::foundShips() {
    return --shipsLeft;
}

void Board::attack()
{
    Visualizer visual = visual.getInstance();
    // Wait for players input
    std::string cell = visual.chooseCell(*this);
    bool success = board[cell[0]][cell[1]].getAttacked();

    if (success == false)
    {
        visual.showMessage ("That cell is not available, choose another.", *this);
        this->attack();
    }
    else {
        if (board[cell[0]][cell[1]].isEmpty()) {
            visual.showMessage("A ship has fallen.", *this);
        }
        else {
            visual.showMessage("You've hit something.", *this);
        }
    }
}

void Board::executeSpecialAttack()
{
    Visualizer visual = visual.getInstance();
    std::string message = "Which ship would you like to use for your special attack?\n";

    message += "Ship #1:\n";
    message += listOfShips[0].getDescription();
    message += "\n\n";

    message += "Ship #2:\n";
    message += listOfShips[1].getDescription();
    message += "\n\n";

    message += "Ship #3: \n";
    message += listOfShips[2].getDescription();
    message += "\n\n";

    message += "Ship #4: \n";
    message += listOfShips[3].getDescription();
    message += "\n\n";

    message += "Ship #5: \n";
    message += listOfShips[4].getDescription();
    message += "\n\n";

    int shipNumber = visual.askNumber(message, *this);

    listOfShips[shipNumber].specialAbility();
}