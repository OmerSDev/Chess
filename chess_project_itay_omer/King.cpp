#include "King.h"

King::King(int x, int y, char color, std::string name) : Piece(x,y,color,name)
{

}

King::~King()
{
    
}

int King::valid_move(int new_x, int new_y, Piece* _board_arr[][8])
{
    bool if_check = false;
    if (new_x > _x +1 || new_x < _x - 1 || new_y > _y + 1 || new_y < _y - 1)
    {
		return 6;
    }
    else
    {
        return 0;
    }
}

int King::move(int new_x, int new_y)
{

    _x = new_x;
    _y = new_y;
    return _x, _y;
}