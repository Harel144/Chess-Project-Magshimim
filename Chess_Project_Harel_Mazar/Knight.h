#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	//methods
	Knight(const string name, const string type, const string position);
	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);
};