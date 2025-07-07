#pragma once
#include "Piece.h"
#include <string>

class Rook: public Piece
{
public:

	Rook(int x, int y, char color, std::string name);
	~Rook();

	virtual int valid_move(int x, int y, Piece* _board_arr[][8]) override;
	virtual int move(int new_x, int new_y) override;


};

