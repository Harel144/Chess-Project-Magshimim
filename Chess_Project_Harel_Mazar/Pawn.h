#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn();
	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);
	bool isLegitEatingMove(const string position);

};