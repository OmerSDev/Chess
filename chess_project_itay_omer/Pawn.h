#pragma once
#include "Piece.h"
#include <string>

class Pawn : public Piece
{
private:
	
	bool _first_move;
public:

	Pawn(int x, int y, char color, std::string name);
	~Pawn();
	virtual int valid_move(int x, int y, Piece* _board_arr[][8]) override;
	virtual int move(int new_x, int new_y) override;
};

