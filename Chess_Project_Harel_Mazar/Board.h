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
	void setBoardString(const string newBoard);
	void printBoard() const;
	void eatPiece(const string position);
	bool isSquareTaken(const string position);
	Side getBlackSide();
	Side getWhiteSide();
	void setWhiteSide(Side &newWhiteSide);
	void setBlackSide(Side &newBlackSide);
	string movePieceAtBoard(const string source, const string destination);
	void updateBoardString();

private:
	string board;
	Side blackSide;
	Side whiteSide;

};