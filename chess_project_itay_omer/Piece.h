#pragma once
#include <string>
class Piece
{

protected:

	int _x;
	int _y;
	char _color;
	std::string _name;


public:
	std::string getName();
	Piece(int x, int y, char color, std::string name);
	virtual ~Piece();
	virtual int valid_move(int x, int y, Piece* _board_arr[][8]) = 0;
	virtual int move(int new_x, int new_y);
	char getColor();
	int getX();
	int getY();

};

