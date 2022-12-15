#pragma once
#include "Piece.h"

class Rook : public Piece
{
public: 
	//fields
	Rook(const string name, const string type, const string position);
	virtual int move(const string newPosition);
	virtual bool isLegitMove(const string position);

};