#include <array>
#include <string>

#include "Controller.h"
#include "Ship.h"


Controller& Controller::getInstance()
{
	static Controller trivia;
	return trivia;
}

Controller::Controller()
	: player1 (Player())
	, player2 (Player())
	, visual (Visualizer())
	, position (HORIZONTAL)
{
}

Controller::~Controller()
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
	while (player1.foundShips < TOTAL_SHIPS && player2.foundShips < TOTAL_SHIPS)
	{
		// Execute attack
		executeAttack(player1);
		executeAttack(player2);
	}

	if (player1.foundShips == TOTAL_SHIPS)
		visual.showMessage("You won!", player1);
	else 
		visual.showMessage("You won!", player2);
}

// Create player's board
void Controller::createPlayersBoard (Player& thisPlayer)
{
	thisPlayer.ClearGrid();

	// Show board
	visual.showBoard(thisPlayer);

	// Repeat for each ship in that player's list 
	for (std::array<Ship*, TOTAL_SHIPS> element : thisPlayer.listOfShips)
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
		/*
		// Ask which ship they want to change
		int ship = visual.askNumber("Write the number of the ship you wish to change", thisPlayer, TOTAL_SHIPS);
		// Choose place for that ship
		choosePlace (thisPlayer, thisPlayer.listOfShips[ship]);
		*/
	}
}

// Choose place for that ship:	
void Controller::choosePlace (Player& thisPlayer, Ship& thisShip)
{
	// Create chosen as false
	bool chosen = false;
	bool changeDirection = false;
	// While chosen is false                             
	while (chosen == false)
	{
		// Wait for players input
		std::string cellChosen = visual.chooseCell(thisPlayer);
		// Go to that cell
		visual.showCell(cellChosen, thisPlayer);
		// Ask if the cell they chose is correct
		bool correct = visual.ask("Is this correct?", thisPlayer);
			// If it is
		if (correct == true)
			// Assign chosen true
			chosen = chooseCell(cellChosen, thisPlayer, thisShip);
	}
}

bool Controller::chooseCell (std::string cell, Player& player, Ship& ship)
{
	bool setShipSuccessful = false;
	// If cell isEmpty
	if (player.board[cell[0]][cell[1]].isEmpty() == false)
	{
		// If position is horizontal
		if (position == HORIZONTAL)
			// Assign setShipSucessful the result of setting ship in cell and cellToTheRight
			setShipSuccessful = ship.setShip(board[cellChosen[0]][cellChosen[1]], board[cellChosen[0]][cellChosen[1] + 1]);
		// Else if position is vertical
		else if (position == VERTICAL)
			// Assign setShipSucessful the result of setting ship in call and cellBelow
			setShipSuccessful = ship.setShip(board[cellChosen[0]][cellChosen[1]], board[cellChosen[0] + 1][cellChosen[1]]);
		// If setShipSucessful is false then
		if (setShipSuccessful == false)
			// Print "Not available choose another"
			visual.showMessage("Not available, choose another");
		return true;
	}

	// Print "Not available choose another"
	visual.showMessage("Already occupied, choose another");
	return false;
}
	
void Controller::executeAttack(Player thisPlayer)
{
	// Create attackSucessful as false
	bool attackSucessful = false;
	// If specialAttack is false
	if (thisPlayer.specialAttack == false)
	{
		// Ask player if they want to use the special attack and if the answer is true
		if (visual.ask("Do you want to use the special attack", thisPlayer) == true)
			// Execute special attack
			thisPlayer.executeSpecialAttack();
		// Else 
		else
		{
			// Attack
			thisPlayer.attack();
		}

		// Send response
		sendResponse((thisPlayer == player1) ? player1 : player2);
	}
}

// Send response
void Controller::sendResponse(Player otherPlayer)
{
	// Print TOTAL_SHIPS - foundShips for the other player
	std::string message = "The other player has attacked ";
	message += std::to_string(player.foundShips);
	message += " of your ships. \n";
	message += std::to_string(TOTAL_SHIPS - otherPlayer.foundShips);
	message += " remain."

	visual.showMessage(message, otherPlayer);
}

