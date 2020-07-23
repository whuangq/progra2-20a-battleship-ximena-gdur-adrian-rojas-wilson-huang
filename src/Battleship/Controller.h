#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Visualizer.h"
#include "Board.h"
#include "Ship.h"
#include <string>

/**
 *  Controller class. Manages each player's actions and what they see.
 */
class Controller
{
public:
	/**
	 * An enum for the direction.
	 * Indicates whether it is horizontal or vertical.
	 */
	enum Direction {
		HORIZONTAL,
		VERTICAL
	};

private:
	/// Attributes
	Board player1; /* Instance of Board. Indicates the first player.*/
	Board player2; /* Instance of Board. Indicates the second player.*/
	Visualizer visual; /* Instance of Visualizer.*/
	Direction position; /* Instance of the enumeration Direction. Indicates is the position is vertical or horizontal.*/

public:
	/// Functions
	/*
	@brief Gets the only instance of the class Controller.
	@return A reference to that instance.
	*/
	static Controller& getInstance();

	/*
	@brief Begins the execution of the program.
	@return Does not return anything.
	*/
	void begin();

	/*
	@brief Creates that player's board, based on the user's input.
	@param thisPlayer A reference to the current player.
	@return Does not return anything.
	*/
	void createPlayersBoard(Board& thisPlayer);

	/*
	@brief Chooses a spot to place the ship, based on the user's input.
	@param thisPlayer A reference to the current player.
	@param thisShip A reference to the current ship.
	@return Does not return anything.
	*/
	void choosePlace(Ship& thisShip, Board& thisPlayer);
	/*
	@brief Checks if the user's choice is viable, and acts accordingly.
	@param cell A reference to the current cell.
	@param thisPlayer A reference to the current player.
	@param thisShip A reference to the current ship.
	@return A boolean value indicating if it was successful.
	*/
	
	bool chooseCell(std::string& cell, Board& player, Ship& ship);

	/*
	@brief Executes a player's attack, based on the user's input.
	@param thisPlayer A reference to the current player.
	@return Does not return anything.
	*/
	void executeAttack(Board& thisPlayer);

	/*
	@brief Sends the other player a message indicating the state of it's opponent's game.
	@param otherPlayer A reference to the current player.
	@return Does not return anything.
	*/
	void sendResponse(Board& otherPlayer);

private:
	/// Constructors
	Controller();
	Controller(const Controller& other) = delete;
	Controller(Controller&& other) = delete;
	Controller& operator= (const Controller& other) = delete;
	Controller& operator= (Controller&& other) = delete;
};
#endif // CONTROLLER_H