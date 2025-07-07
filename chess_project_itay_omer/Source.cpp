/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/
#include <cstdlib> // For system function
#include "Pipe.h"
#include <iostream>
#include <thread>
#include "board.h"
#include "Util.h"


using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	string board_string = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";
	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");
	board b = board(board_string);
	Util u = Util();
	b.board::create_board();
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		char from = msgFromGraphics[0];
		char to = msgFromGraphics[2];

		int from_int = u.Util::letters_to_int(from);
		int to_int = u.Util::letters_to_int(to);
		from_int += ((8 - u.Util::char_to_int(msgFromGraphics[1])) * 8);
		to_int += ((8 - u.Util::char_to_int(msgFromGraphics[3])) * 8);
		int num_error = b.board::move(from_int, to_int);
		b.board::Print_board();
		
		// YOUR CODE
		if (num_error == 0)
			strcpy_s(msgToGraphics, "0");
		else if (num_error == 1)
			strcpy_s(msgToGraphics, "1");
		else if (num_error == 2)
			strcpy_s(msgToGraphics, "2");
		else if (num_error == 3)
			strcpy_s(msgToGraphics, "3");
		else if (num_error == 4)
			strcpy_s(msgToGraphics, "4");
		else if (num_error == 5)
			strcpy_s(msgToGraphics, "5");
		else if (num_error == 6)
			strcpy_s(msgToGraphics, "6");
		else if (num_error == 7)
			strcpy_s(msgToGraphics, "7");
		else if (num_error == 8)
			strcpy_s(msgToGraphics, "8"); 
		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......

		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}