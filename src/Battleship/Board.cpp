#include <iostream>
#include "Board.h"
#include "Cell.h"

Board::Board() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; i < dim; i++) {
            tablero[i][j] = new Cell cell;
        }
    }
}
// Sets the all the cells pointer to null.
void Board::clearGrid() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; i < dim; i++) {
            tablero[i][j] = cell.clearPosition();
        }
    }
}
// Place the ship in the given position of the booard.
void Board::setShips(int row, int col, int shipNumber) {
    tablero[row][col] = cell.assignShip(shipNumber);
}
// Decrease the shipsLeft when the ships life gets to 0.
int Board::foundShips() {
    return shipsLeft -= 1;
}
void Board::updateBoard(bool a, int row, int col) {

}
