#pragma once
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"

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

	string movePiece(const string sourcePosOfPiece, const string destinationPosOfPiece);
	Side operator=(Side& otherSide);

	bool isOneOfMyPiecesAtXLocation(const string location) const;
	bool isOneOfMyPiecesCanReachXLocation(string location);
	Piece* getPieceAtLocationX(string location) const;
	string getKingLocation() const;
	void setCheckState(const bool check);
	bool isLegitEatingMoveForPawn(string source, string destination, string name);

private:
	vector<Piece*> Pieces;
	bool thisSideTurn;
	bool isChecked;
};