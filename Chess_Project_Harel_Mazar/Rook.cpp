#include "Rook.h"

/*
constructor of Rook.
input: name, type and position of Piece.
output: none.
*/
Rook::Rook(const string name, const string type, const string position) : Piece(name, type, position)
{
}

/*
this function moves the rook and returns if the function moved the rook or not (return is by values that the frontend understands)
input: new position for rook
output: code that the frondend understand.
*/
string Rook::move(const string newPosition)
{
	string returnString = to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString = to_string(LEGALMOVE);
	}

	return returnString;
}

/*
this function returns if the rook can reach given position
input: position to check.
output: true or false
*/
bool Rook::isLegitMove(const string position)
{
	string currPosition = getPosition();

	//if someone tried to make an unhorizontal/diagonal move with the rook
	if (currPosition[0] != position[0] && currPosition[1] != position[1])
	{
		return false;
	}

	return true;
}