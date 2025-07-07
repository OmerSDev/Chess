#pragma once
#include <string>
#include "Piece.h"
class board 
{
protected:
	std::string _board_string;
	bool _if_check;
	char color_turn = 'w';
	bool check_;
public:
	Piece* _board_arr[8][8];
	board(std::string board);
	~board();
	void create_board();
    void Print_board();
	int move(int from, int to);
	bool check(int x, int y, Piece* moving, int from);
	bool Place_taken(char current ,char to_color, int to);
	void Eat(int to);

};