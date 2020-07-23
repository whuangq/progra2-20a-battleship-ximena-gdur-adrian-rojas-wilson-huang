#include "Visualizer.h"

Visualizer& Visualizer::getInstance()
{
	static Visualizer visual;
	return visual;
}

void Visualizer::showBoard(Board& thisPlayer)
{
}

void Visualizer::showMessage(std::string str, Board& thisPlayer)
{
}

bool Visualizer::ask(std::string str, Board& thisPlayer)
{
	return false;
}

int Visualizer::askNumber(std::string str, Board& thisPlayer)
{
	return 0;
}

std::string Visualizer::chooseCell(Board& thisPlayer)
{
	return std::string();
}

void Visualizer::showCell(int row, int col, Board& thisPlayer)
{

}