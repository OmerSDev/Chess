#include "Pawn.h"
#include <string>

Pawn::Pawn(int x, int y, char color, std::string name) : Piece(x, y, color, name)
{
	_first_move == true;
}

Pawn::~Pawn()
{
}

int Pawn::valid_move(int new_x, int new_y, Piece* _board_arr[][8])
{	

	if (_color == 'b' && new_y == _y + 1 && new_x == _x && _board_arr[new_y][new_x] == nullptr || new_y == _y + 2 && _first_move && new_x == _x &&
		_board_arr[new_y - 1][new_x] == nullptr && _board_arr[new_y][new_x] == nullptr)
	{
		_first_move = false;
		return 0;
	}
	else if (_color == 'w' && new_y == _y - 1 && new_x == _x && _board_arr[new_y][new_x] == nullptr || new_y == _y - 2 && _first_move && new_x == _x &&
		_board_arr[new_y + 1][new_x] == nullptr && _board_arr[new_y][new_x] == nullptr)
	{
		_first_move = false;
		return 0;
	}
	if (_board_arr[new_y][new_x] != nullptr && ((new_y == _y+1 && new_x == _x + 1) || (new_y == _y + 1 && new_x == _x - 1) || 
		(new_y == _y - 1 && new_x == _x + 1) || (new_y == _y - 1 && new_x == _x - 1)))
	{
		return 0;
	}
	return 6;
}

int Pawn::move(int new_x, int new_y)
{
	_x = new_x;
	_y = new_y;
	return 0;
}