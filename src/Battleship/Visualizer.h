#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <string>

#include "Board.h"

class Visualizer
{
public:
	void showBoard(Board& thisPlayer);
	void showMessage(std::string, Board& thisPlayer);
	bool ask (std::string, Board& thisPlayer);
	std::string chooseCell(Board& thisPlayer);

};
#endif // VISUALIZER_H
