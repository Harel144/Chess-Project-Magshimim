#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(const string name, const string type, const string position);
	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);
	bool isLegitEatingMove(const string position);
};