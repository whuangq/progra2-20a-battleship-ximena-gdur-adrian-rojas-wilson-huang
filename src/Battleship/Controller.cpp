#include <array>
#include <string>

#include "Controller.h"
#include "Ship.h"
#include "Board.h"



Controller& Controller::getInstance()
{
	static Controller trivia;
	return trivia;
}

Controller::Controller()
	: player1 (Board())
	, player2 (Board())
	, visual (visual.getInstance())
	, position (HORIZONTAL)
{
}

void Controller::begin()
{
	// Create player's board
	createPlayersBoard(player1);
	createPlayersBoard(player2);

	// Show board
	visual.showBoard(player1);
	visual.showBoard(player2);

	// Repeat while foundShips is lesser than TOTAL_SHIPS
	while (player1.getShipsLeft() < TOTAL_SHIPS && player2.getShipsLeft() < TOTAL_SHIPS)
	{
		// Execute attack
		executeAttack(player1);
		sendResponse(player2);

		executeAttack(player2);
		sendResponse(player1);
	}

	if (player1.getShipsLeft() == TOTAL_SHIPS)
		visual.showMessage("You won!", player1);
	else 
		visual.showMessage("You won!", player2);
}

// Create player's board
void Controller::createPlayersBoard (Board& thisPlayer)
{
	thisPlayer.clearGrid();

	// Show board
	visual.showBoard(thisPlayer);

	// Repeat for each ship in that player's list 
	for (Ship& element : thisPlayer.getListOfShips())
	{
		// Choose place for that ship
		choosePlace(element, thisPlayer);
	}

	visual.showBoard(thisPlayer);
	// Ask if they are content with the board
	bool answer = visual.ask ("Are you content with the board?\n Warning: if you choose to change it, it will reset the board", thisPlayer);
	// If they answer false
	if (answer == false) {
		createPlayersBoard (thisPlayer);
	}
}

// Choose place for that ship:	
void Controller::choosePlace (Ship& thisShip, Board& thisPlayer)
{
	// Create chosen as false
	bool chosen = false;
	bool notAvailable = false;
	// While chosen is false                             
	while (chosen == false)
	{
		// Wait for players input
		std::string cellChosen = visual.chooseCell(thisPlayer);
		// Go to that cell
		for (int shipCellIndex = 0; shipCellIndex < thisShip.getLives(); shipCellIndex++)
		{
			if (notAvailable = false) {
				if (position == HORIZONTAL) 
				{ 
					if ((int)cellChosen[1] + shipCellIndex < MATRIX_DIMENSIONS) {
						visual.showCell((int)cellChosen[0], (int)cellChosen[1] + shipCellIndex, thisPlayer);
					}
					else {
						visual.showMessage("Not available", thisPlayer);
						notAvailable = true;
					}
				}
				else if (position == VERTICAL) {
					if ((int)cellChosen[0] + shipCellIndex < MATRIX_DIMENSIONS) {
						visual.showCell((int)cellChosen[0] + shipCellIndex, (int)cellChosen[1], thisPlayer);
					}
					else {
						visual.showMessage("Not available", thisPlayer);
						notAvailable = true;
					}
				}
			}
		}

		bool correct = true;
		if (notAvailable = false) {
			// Ask if the cell they chose is correct
			correct = visual.ask("Is this correct?", thisPlayer);
			// If it is
			if (correct == false )
			// Assign chosen true
				chooseCell(cellChosen, thisPlayer, thisShip);
		}
		else {
			chooseCell(cellChosen, thisPlayer, thisShip);
		}
	}
}

bool Controller::chooseCell (std::string& cell, Board& player, Ship& ship)
{
	// If cell isEmpty
	if (player.getElement ( (int) cell[0], (int) cell[1] ).isEmpty() == false)
	{
		for (int shipCellIndex = 0; shipCellIndex < ship.getLives(); shipCellIndex++)
		{
			// If position is horizontal
			if (position == HORIZONTAL)
				// Set ship in call and cellToTheRight
				player.setShips((int)cell[0], (int)cell[1] + shipCellIndex, ship);
			// Else if position is vertical
			else if (position == VERTICAL)
				// Set ship in call and cellBelow
				player.setShips((int)cell[0] + shipCellIndex, (int)cell[1], ship);
		}
		return true;
	}
	else
	{
		// Print "Not available choose another"
		visual.showMessage("Already occupied, choose another");
		return false;
	}
}
	
void Controller::executeAttack(Board& thisPlayer)
{
	// Create attackSucessful as false
	bool attackSucessful = false;
	// If specialAttack is false
	if (thisPlayer.getStatusSpecialAttack() == false)
	{
		// Ask player if they want to use the special attack and if the answer is true
		if (visual.ask("Do you want to use the special attack?", thisPlayer) == true) {
			// Send response
			visual.showMessage("The other player has used a special attack against you!", (thisPlayer == player1) ? player1 : player2);
			// Execute special attack
			return thisPlayer.executeSpecialAttack();
		}
	}
		// Send response
		visual.showMessage ("The other player has attacked you!", (thisPlayer == player1) ? player1 : player2);
		// Attack
		return thisPlayer.attack();
}

// Send response
void Controller::sendResponse(Board& otherPlayer)
{
	// Print TOTAL_SHIPS - foundShips for the other player
	std::string message = "The other player has attacked ";
	message += std::to_string(otherPlayer.getShipsLeft());
	message += " of your ships. \n";
	message += std::to_string(TOTAL_SHIPS - otherPlayer.getShipsLeft());
	message += " remain.";

	visual.showMessage(message, otherPlayer);
}

