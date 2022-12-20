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
	void printBoard() const;
	void eatPiece(const string position);
	bool isSquareTaken(const string position);
	Side getBlackSide() const;
	Side getWhiteSide() const;
	void setWhiteSide(Side &newWhiteSide);
	void setBlackSide(Side &newBlackSide);
	string movePieceAtBoard(const string source, const string destination);
	void updateBoardString();
	void setBoardString(const string newBoard);

	bool isKingChecked();

private:
	string board;
	Side blackSide;
	Side whiteSide;

	void changeTurn();

};