#pragma once
#include "Piece.h"
#include <string>

class Bishop : public Piece
{
public:

	Bishop(int x, int y, char color, std::string name);
	~Bishop();
	virtual int valid_move(int x, int y, Piece* _board_arr[][8]) override;
	virtual int move(int new_x, int new_y) override;
};

