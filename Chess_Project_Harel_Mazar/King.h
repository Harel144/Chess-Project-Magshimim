#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(const string name, const string type, const string position);
	bool GetisChecked() const;
	void changeCheck();

	virtual string move(const string newPosition);
	virtual bool isLegitMove(const string position);

private:
		bool isCheacked;
};