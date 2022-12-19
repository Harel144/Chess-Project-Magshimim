#include "Board.h"

Board::Board()
{
	this->blackSide = *(new Side());
	this->whiteSide = *(new Side());
	this->board = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";

	this->blackSide.changeTurnState();


	/*
	adding rooks
	*/

	//black rooks
	Rook* rookBlackOne = new Rook("r", "Rook", "a8");
	Rook* rookBlackTwo = new Rook("r", "Rook", "h8");
	//white rooks
	Rook* rookWhiteOne = new Rook("R", "Rook", "a1");
	Rook* rookWhiteTwo = new Rook("R", "Rook", "h1");

	this->blackSide.addPiece(rookBlackOne);
	this->blackSide.addPiece(rookBlackTwo);

	this->whiteSide.addPiece(rookWhiteOne);
	this->whiteSide.addPiece(rookWhiteTwo);
}

bool Board::isWhiteTurn() const
{
	return this->whiteSide.isItSideTurn();
}

bool Board::isBlackTurn() const
{
	return this->blackSide.isItSideTurn();
}

string Board::getBoardString() const
{
	return this->board;
}

void Board::printBoard() const
{
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			std::cout << std::endl;
		}

		std::cout << getBoardString()[i] << " ";
	}

	std::cout << std::endl;
}


void Board::eatPiece(const string position)
{
	if (isWhiteTurn())
	{
		if (this->blackSide.isOneOfMyPiecesAtXLocation(position))
		{
			this->blackSide.removePiece(position);
		}
	}
	else
	{
		if (this->whiteSide.isOneOfMyPiecesAtXLocation(position))
		{
			this->whiteSide.removePiece(position);
		}
	}
}

bool Board::isSquareTaken(const string position)
{
	return blackSide.isOneOfMyPiecesAtXLocation(position) || whiteSide.isOneOfMyPiecesAtXLocation(position);
}

Side Board::getBlackSide()
{
	return this->blackSide;
}

Side Board::getWhiteSide()
{
	return this->whiteSide;
}

void Board::setWhiteSide(Side& newWhiteSide)
{
	this->whiteSide = newWhiteSide;
}

void Board::setBlackSide(Side& newBlackSide)
{
	this->blackSide = newBlackSide;
}

string Board::movePieceAtBoard(const string source, const string destination)
{
	string retString;
	if (isWhiteTurn())
	{
		if (blackSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(ILLEGALMOVENOORIGINALPIECE);
		}

		retString =  whiteSide.movePiece(source, destination);

		if (blackSide.isOneOfMyPiecesAtXLocation(destination) && retString == "0")
		{
			eatPiece(destination);
		}
	}
	else
	{
		if (whiteSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(ILLEGALMOVENOORIGINALPIECE);
		}

		retString = blackSide.movePiece(source, destination);

		if (whiteSide.isOneOfMyPiecesAtXLocation(destination) && retString == "0")
		{
			eatPiece(destination);
		}
	}

	if (retString == "0" || retString == "1" || retString == "8")
	{
		changeTurn();
	}
	return retString;
}

void Board::updateBoardString()
{
	string newBoardStr;
	string currPos = "xx";

	for (int i = 0; i < 64; i++)
	{
		currPos[0] = (char)i % 8 + 97;
		currPos[1] = to_string((int)i / 8)[0];

		if(this->whiteSide.isOneOfMyPiecesAtXLocation(currPos))
		{
			newBoardStr[i] = this->whiteSide.getPieceAtLocationX(currPos)->getName()[0];
		}
	}
	
	setBoardString(newBoardStr);
}

void Board::setBoardString(const string newBoard)
{
	this->board = newBoard;
}

void Board::changeTurn()
{
	this->blackSide.changeTurnState();
	this->whiteSide.changeTurnState();
}