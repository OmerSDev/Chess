#include "Knight.h"

Knight::Knight(int x, int y, char color, std::string name) : Piece(x, y, color, name)
{

}

Knight::~Knight()
{
}

int Knight::valid_move(int new_x, int new_y, Piece* _board_arr[][8])
{

    // Check if the move is an L-shaped pattern for a knight
    if (new_x - _x == 1 && new_y - _y == 2 || _x - new_x == 1 && new_y - _y == 2 || new_x - _x == 1 && _y - new_y == 2 || _x - new_x == 1 && _y - new_y == 2 ||
		new_x - _x == 2 && new_y - _y == 1 || _x - new_x == 2 && new_y - _y == 1 || new_x - _x == 2 && _y - new_y == 1 || _x - new_x == 2 && _y - new_y == 1)
    {
        return 0;
    }

    return 6; 
}

int Knight::move(int new_x, int new_y)
{
	_x = new_x;
	_y = new_y;
	return 0;
}
