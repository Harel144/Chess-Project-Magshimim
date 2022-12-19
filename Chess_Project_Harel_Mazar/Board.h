#pragma once
#include <string>
#include "Side.h"
#include <iostream>

class Board
{
public:
	Board();
	bool isWhiteTurn() const;
	bool isBlackTurn() const;
	string getBoardString() const;
	string printBoard() const;
	void eatPiece(const string position);
	bool isSquareTaken(const string position);
	Side getBlackSide();
	Side getWhiteSide();
	void setWhiteSide(Side &newWhiteSide);
	void setBlackSide(Side &newBlackSide);

private:
	string board;
	Side blackSide;
	Side whiteSide;

};