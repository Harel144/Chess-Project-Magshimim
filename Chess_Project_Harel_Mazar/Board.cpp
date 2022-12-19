#include "Board.h"

Board::Board()
{
	this->blackSide = *(new Side());
	this->whiteSide = *(new Side());
	this->board = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";

	/*
	adding rooks
	*/

	//black rooks
	Rook* rook = new Rook("r", "Rook", "a8");
	this->blackSide.addPiece(rook);
	rook->setPosition("h8");
	this->blackSide.addPiece(rook);

	//white rooks
	rook->setName("R");
	rook->setPosition("a1");
	this->whiteSide.addPiece(rook);
	rook->setPosition("h1");
	this->whiteSide.addPiece(rook);
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
		std::cout << this->getBoardString()[i] + " ";

		if (i % 8 == 0)
		{
			std::cout << std::endl;
		}
	}
}


void Board::eatPiece(const string position)
{
	if (this->blackSide.isOneOfMyPiecesAtXLocation(position))
	{
		this->blackSide.removePiece(position);
	}

	if (this->whiteSide.isOneOfMyPiecesAtXLocation(position))
	{
		this->whiteSide.removePiece(position);
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
	if (isWhiteTurn())
	{
		if (blackSide.isOneOfMyPiecesAtXLocation(destination))
		{
			eatPiece(destination);
		}
		whiteSide.movePiece(source, destination);
	}
	else
	{
		if (whiteSide.isOneOfMyPiecesAtXLocation(destination))
		{
			eatPiece(destination);
		}
		blackSide.movePiece(source, destination);
	}
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

	this->board = newBoardStr;
}