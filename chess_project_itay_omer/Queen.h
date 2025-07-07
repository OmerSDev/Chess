#pragma once
#include <string>
#include "Piece.h"

class Queen : public Piece
{
public:

	Queen(int x, int y, char color, std::string name);
	virtual ~Queen();
	virtual int valid_move(int x, int y, Piece* _board_arr[][8]) override;
	virtual int move(int new_x, int new_y);

};

