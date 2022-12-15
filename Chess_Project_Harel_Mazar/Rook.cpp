#include "Rook.h"

Rook::Rook(const string name, const string type, const string position) : Piece(name, type, position)
{
}


string Rook::move(const string newPosition)
{
	string returnString = "6";
	returnString[1] = NULL;

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString[0] = '0';
	}

	return returnString;
}


bool Rook::isLegitMove(const string position)
{
	string currPosition = getPosition();

	//if someone tried to make a diagonal move with the rook
	if (currPosition[3] != position[3] && position[4] != position[4])
	{
		return false;
	}

	return true;
}