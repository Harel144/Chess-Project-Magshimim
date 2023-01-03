#include "King.h"

/*
constructor of King.
input: name, type and position of Piece.
output: none.
*/
King::King(const string name, const string type, const string position) : Piece(name, type, position)
{
}

/*
this function moves the King and returns if the function moved the King or not (return is by values that the frontend understands).
input: new position for King.
output: code that the frondend understand.
*/
string King::move(const string newPosition)
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
this function returns if the King can reach given position
input: position to check.
output: true or false
*/
bool King::isLegitMove(const string position)
{
	string currPosition = getPosition();

	bool diagonalOnce = std::abs(currPosition[1] - position[1]) == 1 && std::abs(currPosition[0] - position[0]) == 1;
	bool straightOnce = (std::abs(currPosition[0] - position[0]) == 1 && std::abs(currPosition[1] - position[1]) == 0) || (std::abs(currPosition[0] - position[0]) == 0 && std::abs(currPosition[1] - position[1]) == 1);

	if (straightOnce || diagonalOnce)
	{
		return true;
	}

	return false;

}