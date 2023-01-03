/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"

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
	Board gameBoard = *(new Board());
	string currBoard = gameBoard.getBoardString();

	strcpy_s(msgToGraphics, currBoard.c_str()); // just example...

	gameBoard.setBoardString(currBoard.substr(0, gameBoard.getBoardString().size() - 1));

	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		gameBoard.printBoard();
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		string source = msgFromGraphics.substr(0, 2);
		string destination = msgFromGraphics.substr(2, 2);

		// YOUR CODE
		if (source != destination)
		{
			strcpy_s(msgToGraphics, gameBoard.movePieceAtBoard(source, destination).c_str()); // msgToGraphics should contain the result of the operation
		}
		else
		{
			strcpy_s(msgToGraphics, to_string(ILLEGALMOVENOMOVE).c_str());
		}
		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

		gameBoard.updateBoardString();
	}

	p.close();
}