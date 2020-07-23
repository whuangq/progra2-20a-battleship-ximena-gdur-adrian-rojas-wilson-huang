#include "Visualizer.h"

Visualizer& Visualizer::getInstance()
{
	static Visualizer visual;
	return visual;
}

void Visualizer::showBoard(Board& thisPlayer)
{
	std::cout << " 1 2 3 4 5 6 7 8 9";
	for (int rowIndex = 0; rowIndex < MATRIX_DIMENSIONS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < MATRIX_DIMENSIONS; colIndex++)
		{
			std::cout << rowIndex << " ";
			if (thisPlayer.getElement(rowIndex, colIndex).isEmpty() == true)
				std::cout << "O ";
			else 
				std::cout << "X ";
		}
		std::cout << std::endl;
	}
}

void Visualizer::showMessage(std::string str, Board& thisPlayer)
{
	std::cout << std::endl << str;
}

bool Visualizer::ask(std::string str, Board& thisPlayer)
{
	std::cout << std::endl << str;
	int response = 0;
	std::cin >> response;
	if (response = 0)
		return false;
	if (response = 1)
		return true;
}

int Visualizer::askNumber(std::string str, Board& thisPlayer)
{
	std::cout << std::endl << str;
	int response = 0;
	std::cin >> response;
	return response;
}

std::string Visualizer::chooseCell(Board& thisPlayer)
{
	std::cout << "Choose a cell, enter the coordinates without a space. \n Example: 21, for row 2 column 1" << std::endl << std::endl;
	showBoard(thisPlayer);
	std::string response;
	std::cin >> response;
	return response;
}

void Visualizer::showCell(int row, int col, Board& thisPlayer)
{
	std::cout << " 1 2 3 4 5 6 7 8 9";
	for (int rowIndex = 0; rowIndex < MATRIX_DIMENSIONS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < MATRIX_DIMENSIONS; colIndex++)
		{
			std::cout << rowIndex << " ";
			if (rowIndex  == row && colIndex == col)
				std::cout << "[ "
			if (thisPlayer.getElement(rowIndex, colIndex).isEmpty() == true)
				std::cout << "O ";
			else
				std::cout << "X ";
			if (rowIndex == row && colIndex == col)
				std::cout << "] ";
		}
		std::cout << std::endl;
	}

}