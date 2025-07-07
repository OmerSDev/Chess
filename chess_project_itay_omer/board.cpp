#include "board.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include <string>
#include <iostream>


board::board(std::string board)
{
	_board_string = board;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board_arr[i][j] = nullptr;
		}
	}
	_if_check = false;
	check_ = false;
}

board::~board()
{

}

void board::create_board()
{
	_board_arr[0][0] = new Rook(0, 0, 'b', "r1");//[y][x]
	_board_arr[0][7] = new Rook(7, 0, 'b', "r2");//[y][x]
	_board_arr[7][7] = new Rook(7, 7, 'w', "R1");//[y][x]
	_board_arr[7][0] = new Rook(0, 7, 'w', "R2");//[y][x]

	_board_arr[0][2] = new Bishop(2, 0, 'b', "b1");//[y][x]
	_board_arr[0][5] = new Bishop(5, 0, 'b', "b2");//[y][x]
	_board_arr[7][2] = new Bishop(2, 7, 'w', "B1");//[y][x]
	_board_arr[7][5] = new Bishop(5, 7, 'w', "B2");//[y][x]

	_board_arr[0][1] = new Knight(1, 0, 'b', "n1");//[y][x]
	_board_arr[0][6] = new Knight(6, 0, 'b', "n2");//[y][x]
	_board_arr[7][1] = new Knight(1, 7, 'w', "N1");//[y][x]
	_board_arr[7][6] = new Knight(6, 7, 'w', "N2");//[y][x]
	
	_board_arr[0][3] = new Queen(3, 0, 'b', "q");//[y][x]
	_board_arr[7][3] = new Queen(3, 7, 'w', "Q");//[y][x]

	_board_arr[0][4] = new King(4, 0, 'b', "k");//[y][x]
	_board_arr[7][4] = new King(4, 7, 'w', "K");//[y][x]

    _board_arr[1][0] = new Pawn(0, 1, 'b', "p1");//[y][x]
	_board_arr[1][1] = new Pawn(1, 1, 'b', "p2");//[y][x]
	_board_arr[1][2] = new Pawn(2, 1, 'b', "p3");//[y][x]
	_board_arr[1][3] = new Pawn(3, 1, 'b', "p4");//[y][x]
	_board_arr[1][4] = new Pawn(4, 1, 'b', "b5");//[y][x]
	_board_arr[1][5] = new Pawn(5, 1, 'b', "p6");//[y][x]
	_board_arr[1][6] = new Pawn(6, 1, 'b', "p7");//[y][x]
	_board_arr[1][7] = new Pawn(7, 1, 'b', "p8");//[y][x]
	_board_arr[6][0] = new Pawn(0, 6, 'w', "P1");//[y][x]
	_board_arr[6][1] = new Pawn(1, 6, 'w', "P2");//[y][x]
	_board_arr[6][2] = new Pawn(2, 6, 'w', "P3");//[y][x]
	_board_arr[6][3] = new Pawn(3, 6, 'w', "P4");//[y][x]
	_board_arr[6][4] = new Pawn(4, 6, 'w', "P5");//[y][x]
	_board_arr[6][5] = new Pawn(5, 6, 'w', "P6");//[y][x]
	_board_arr[6][6] = new Pawn(6, 6, 'w', "P7");//[y][x]
	_board_arr[6][7] = new Pawn(7, 6, 'w', "P8");//[y][x]

}

int board::move(int from, int to)
{
	int x = to % 8;
	int y = to / 8;
	int x_king = 0;
	int y_king = 0;
	bool taken = true;
	Piece* moving = (&_board_arr[0][0])[from];
	Piece* target = (&_board_arr[0][0])[to];

	Piece* to_temp;
	Piece* from_temp;
	char string_temp = ' ';
	char string_from = ' ';
	char color_king = ' ';

	if (moving == nullptr)
	{
		return 6;
	}
	char color = moving->getColor();
	
	if (color_turn == color)
	{
		if (color == 'w')
		{
			color_turn = 'b';
		}
		if (color == 'b')
		{
			color_turn = 'w';
		}
		if (moving == nullptr)
		{
			return 2;
		}
		if (moving == target)
		{
			return 7;
		}
		std::string name = (&_board_arr[0][0])[from]->getName();
		if (name[0] == 'k' || name[0] == 'K')
		{
			_if_check = check(x, y, moving, from);
			if (_if_check == true)
			{
				if (color_turn == 'w')
				{
					color_turn = 'b';
				}
				else if (color_turn == 'b')
				{
					color_turn = 'w';
				}
				return 4;
			}
		}
		int num_error = moving->valid_move(x, y, this->_board_arr);
		if (num_error == 0)
		{
			moving->move(x, y);
		}
		if (num_error == 6)
		{
			if (color_turn == 'w')
			{
				color_turn = 'b';
			}
			else if (color_turn == 'b')
			{
				color_turn = 'w';
			}
			return 6;
		}
		if (target != nullptr)
		{
			char current = (&_board_arr[0][0])[from]->getColor();
			if (target->getColor() == 'b')
			{
				taken = Place_taken(current, 'b', to);
			}
			else
			{
				taken = Place_taken(current, 'w', to);
			}
		}
		if (taken == true)
		{
			to_temp = (&_board_arr[0][0])[to];
			from_temp = (&_board_arr[0][0])[from];
			string_temp = _board_string[to];
			string_from = _board_string[from];

			(&_board_arr[0][0])[to] = (&_board_arr[0][0])[from];
			(&_board_arr[0][0])[from] = nullptr;
			_board_string[to] = _board_string[from];
			_board_string[from] = '#';
			char color_ = (&_board_arr[0][0])[to]->getColor();




			//create 2 from loops to find the 2 kings and after that check if they are in check and must move
			bool checked = false;
			for (int i = 0; i <63; i++)
			{
				Piece* piece = (&_board_arr[0][0])[i];
				if (piece != nullptr)
				{
					if ((piece->getName() == "k" || piece->getName() == "K"))
					{
						color_king = piece->getColor();
						x_king = piece->getX();
						y_king = piece->getY();
						checked = check(x_king, y_king, piece, to); 

						if (checked && !check_)
						{
							check_ = true;
							if (color_king != color_)
							{
								return 0;
							}
						}
						if (checked && check_)
						{
							if (color_turn == 'w')
							{
								color_turn = 'b';
							}
							else if (color_turn == 'b')
							{
								color_turn = 'w';
							}
							(&_board_arr[0][0])[to] = to_temp;
							(&_board_arr[0][0])[from] = from_temp;
							_board_string[to] = string_temp;
							_board_string[from] = string_from;
							return 4;
						}
					}				
				}
			}
			check_ = false;
			return 0;
		}
	}
	else
	{
		return 2;
	}
	if (color_turn == 'w')
	{
		color_turn = 'b';
	}
	else if (color_turn == 'b')
	{
		color_turn = 'w';
	}
	return 3;

}

bool board::check(int x, int y, Piece* moving, int from)
{
	int error = 99;
	char color = ' ';
	char K_color = moving->getColor();
	for (int i = 0; i < 63; i++)
	{
		Piece* threat = (&_board_arr[0][0])[i];
		if (threat != nullptr)
		{
			color = threat->getColor();
			if (color != K_color)
			{
				error = threat->valid_move(x, y, this->_board_arr);
			}
			if (error == 0)
			{
				return true;
			}

		}
	}

	return false;
}


bool board::Place_taken(char current, char color, int to)
{

	if (current == 'b' && color == 'w')
	{
		Eat(to);
	}
	else if (current == 'w' && color == 'b')
	{
		Eat(to);
	}
	else
	{
		std::cout << "error 3\n";
		return false;
	}
	return true;
}

void board::Print_board()
{
	for (int y = 0; y <= 7; y++)
	{
		for (int x = 0; x < 8; x++) {
			int index = y * 8 + x;
			char piece = _board_string[index];
			// Print the piece or '#' if the square is empty
			std::cout << (piece == '#' ? '#' : piece) << ' ';
		}
		std::cout << '\n';
	}
}

void board::Eat(int to)
{
	delete (&_board_arr[0][0])[to];
	(&_board_arr[0][0])[to] = nullptr;
}


