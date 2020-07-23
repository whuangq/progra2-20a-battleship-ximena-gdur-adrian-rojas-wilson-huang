#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <string>

#include "Board.h"

class Visualizer
{
public:
	/*
	@brief Gets the only instance of the class Visualizer.
	@return A reference to that instance.
	*/
	Visualizer& getInstance();
	
	/*
	@brief Shows the user player's current board
	@param thisPlayer A reference to the current player
	@return This function doesn't return anything.
	*/
	void showBoard(Board& thisPlayer);

	/*
	@brief Shows a message to the user.
	@param str Text to be shown.
	@param thisPlayer A reference to the current player.
	@return This function doesn't return anything.
	*/
	void showMessage(std::string str, Board& thisPlayer);

	/*
	@brief Asks a question to the user, it expects a response.
	@param str Question to be asked.
	@param thisPlayer A reference to the current player.
	@return A boolean value indicating if the answer is yes or no.
	*/
	bool ask (std::string str, Board& thisPlayer);

	/*
	@brief Asks a question to the user, it expects a numerical response.
	@param str Question to be asked.
	@param thisPlayer A reference to the current player.
	@return A numerical value in response to what was asked.
	*/
	int askNumber (std::string str, Board& thisPlayer);

	/*
	@brief Facilitates the user the opportunity to choose a cell to place a ship. It shows a window with buttons to choose from.
	@param thisPlayer A reference to the current player.
	@return A string indicating the user's choice of coordinates.
	*/
	std::string chooseCell(Board& thisPlayer);

	/*
	@brief Shows the player the cell they have selected to place the ship.
	@param row Row in the board where the selected cell is located.
	@param col Column in the board where the selected cell is located.
	@param thisPlayer A reference to the current player.
	@return This function doesn't return anything.
	*/
	void showCell(int row, int col, Board& thisPlayer);

};
#endif // VISUALIZER_H
