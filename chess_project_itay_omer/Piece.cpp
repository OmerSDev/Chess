#include "Piece.h"

Piece::Piece(int x, int y, char color, std::string name)
{
	_x = x;
	_y = y;
	_color = color;
	_name = name;

}

Piece::~Piece()
{

}

std::string Piece::getName()
{
	return _name;
}

int Piece::move(int new_x, int new_y)
{
	return new_x,new_y;
}

char Piece::getColor()
{
	return _color;
}

int Piece::getX()
{
	return _x;
}

int Piece::getY()
{
	return _y;
}
