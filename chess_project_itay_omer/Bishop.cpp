#include "Bishop.h"

Bishop::Bishop(int x, int y, char color, std::string name) : Piece(x, y, color, name)
{

}

Bishop::~Bishop()
{
}

int Bishop::valid_move(int new_x, int new_y, Piece* _board_arr[][8])
{
	int i = 0;
	int i_y = 0;
	std::string name = " ";
	if (new_x != _x && new_y != _y && new_x - _x == new_y - _y || new_x - _x == _y - new_y || _x - new_x == _y - new_y || _x - new_x == new_y - _y)
	{
		if (new_x > _x && new_y > _y)
		{
			i_y = _y;
			for (i = _x + 1; i < new_x; i++)
			{	
				if (i_y < new_y)
				{
					i_y++;
				}
				if (_board_arr[i_y][i] != nullptr)
				{
					name = _board_arr[i_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
				
			}
		}
		else if (new_x > _x && new_y < _y)
		{
			i_y = _y;
			for (i = _x + 1; i < new_x; i++)
			{
				if (i_y > new_y)
				{
					i_y--;
				}
				if (_board_arr[i_y][i] != nullptr)
				{
					name = _board_arr[i_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}

			}
		}
		else if (new_x < _x && new_y < _y)
		{
			i_y = _y;
			for (i = _x - 1; i > new_x; i++)
			{
				if (i_y > new_y)
				{
					i_y--;
				}
				if (_board_arr[i_y][i] != nullptr)
				{
					name = _board_arr[i_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
				i -= 2;

			}
		}
		else if (new_x < _x && new_y > _y)
		{
			i_y = _y;
			for (i = _x - 1; i > new_x; i++)
			{
				if (i_y < new_y)
				{
					i_y++;
				}
				if (_board_arr[i_y][i] != nullptr)
				{
					name = _board_arr[i_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
				i -= 2;

			}
		}
		return 0;
	}

	return 6;
}

int Bishop::move(int new_x, int new_y)
{
	_x = new_x;
	_y = new_y;
	return 0;
}
