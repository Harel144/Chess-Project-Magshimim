#pragma once
#include "Bishop.h"
#include "Rook.h"
#include <vector>

using std::vector;

class Side
{

public:
	Side();
	void addPiece(Piece* newPiece);
	void removePiece(const string position);

	vector<Piece*> getPiecesVector() const;

	void changeTurnState();
	bool isItSideTurn() const;
	bool isOneOfMyPiecesAtXLocation(const string location) const;
	string movePiece(const string sourcePosOfPiece, const string destinationPosOfPiece);
	Side operator=(Side& otherSide);

	Piece* getPieceAtLocationX(const string location) const;

private:
	vector<Piece*> Pieces;
	bool thisSideTurn;

};