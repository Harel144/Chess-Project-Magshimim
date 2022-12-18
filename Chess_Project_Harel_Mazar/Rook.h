#pragma once
#include "Piece.h"

class Rook : public Piece
{
public: 
	//methods
	Rook(const string name, const string type, const string position);
	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);

};