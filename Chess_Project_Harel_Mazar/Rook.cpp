#include "Rook.h"

Rook::Rook(const string name, const string type, const string position) : Piece(name, type, position)
{
}


string Rook::move(const string newPosition)
{
	string returnString = "6";

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString = "0";
	}

	return returnString;
}


bool Rook::isLegitMove(const string position)
{
	string currPosition = getPosition();

	//if someone tried to make a diagonal move with the rook
	if (currPosition[0] != position[0] && currPosition[1] != position[1])
	{
		return false;
	}

	return true;
}