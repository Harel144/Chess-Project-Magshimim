#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	//methods
	Bishop(const string name, const string type, const string position);
	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);

};