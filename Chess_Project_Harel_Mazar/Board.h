#pragma once
#include <string>

using std::string;

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

private:
	string board;
};