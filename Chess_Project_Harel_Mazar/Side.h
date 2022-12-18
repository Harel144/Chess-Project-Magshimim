#pragma once
#include "Bishop.h"
#include "Rook.h"
#include <vector>

using std::vector;

class Side
{

public:
	Side();
	void addPiece(const Piece* newPiece);
	void removePiece(const string position);

	vector<Piece*> getPiecesVector();

	void changeTurnState();
	bool isItSideTurn();

private:
	vector<Piece*> Pieces;
	bool thisSideTurn;

};