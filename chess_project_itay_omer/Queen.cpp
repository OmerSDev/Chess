#include "Queen.h"

Queen::Queen(int x, int y, char color, std::string name) : Piece(x, y, color, name)
{

}

Queen::~Queen()
{
}

int Queen::valid_move(int new_x, int new_y, Piece* _board_arr[][8])
{
	int i = 0;
	int i_y = 0;
	std::string name = " ";
	if (new_x != _x && new_y != _y)
	{
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
					if (_board_arr[i_y][i] != nullptr)// _board_arr[y][x]->getName()
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
					if (_board_arr[i_y][i] != nullptr)// _board_arr[y][x]->getName()
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
					if (_board_arr[i_y][i] != nullptr)// _board_arr[y][x]->getName()
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
					if (_board_arr[i_y][i] != nullptr)// _board_arr[y][x]->getName()
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
	}
	else if(!(new_x == _x && new_y == _y || new_x != _x && new_y != _y))
	{
		if (new_x > _x)
		{
			for (i = _x + 1; i < new_x; i++)
			{
				if (_board_arr[_y][i] != nullptr)// _board_arr[y][x]->getName()
				{
					name = _board_arr[_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
			}
		}
		else if (new_x < _x)
		{
			for (i = new_x + 1; i < _x; i++)
			{
				if (_board_arr[_y][i] != nullptr)
				{
					name = _board_arr[_y][i]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
			}
		}

		if (new_y > _y)
		{
			for (i = _y + 1; i < new_y; i++)
			{
				if (_board_arr[i][_x] != nullptr)
				{
					name = _board_arr[i][_x]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
			}
		}
		else if (_y > new_y)
		{
			for (i = new_y + 1; i < _y; i++)
			{
				if (_board_arr[i][_x] != nullptr)// _board_arr[y][x]->getName()
				{
					name = _board_arr[i][_x]->getName();
					if (name != "k" && name != "K")
					{
						return 6;
					}
				}
			}
		}
		return 0;


	}
	
	return 6;
}

int Queen::move(int new_x, int new_y)
{
	_x = new_x;
	_y = new_y;
	return 0;
}