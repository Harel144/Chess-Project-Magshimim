#pragma once

#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"

#include <vector>

using std::vector;

class Side
{

public:
	//c'tor
	Side();
	void addPiece(Piece* newPiece);
	void removePiece(const string position);

	//getters and setters
	vector<Piece*> getPiecesVector() const;
	Piece* getPieceAtLocationX(const string location) const;
	string getKingLocation() const;
	bool isItSideTurn() const;

	//methods
	void changeTurnState();

	string movePiece(const string sourcePosOfPiece, const string destinationPosOfPiece);
	Side operator=(Side& otherSide);

	bool isOneOfMyPiecesAtXLocation(const string location) const;
	bool isOneOfMyPiecesCanReachXLocation(const string location) const;
	void setCheckState(const bool check);
	bool isLegitEatingMoveForPawn(const string source, const string destination, const string name);

private:
	vector<Piece*> Pieces;
	bool thisSideTurn;
	bool isChecked;
};