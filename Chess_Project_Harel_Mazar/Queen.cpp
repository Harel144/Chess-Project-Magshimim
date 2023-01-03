#include "Queen.h"

/*
constructor of Queen.
input: name, type and position of Piece.
output: none.
*/
Queen::Queen(const string name, const string type, const string position) : Piece(name, type, position)
{
}

/*
this function moves the Queen and returns if the function moved the Queen or not (return is by values that the frontend understands).
input: new position for Queen.
output: code that the frondend understand.
*/
string Queen::move(const string newPosition)
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
this function returns if the Queen can reach given position
input: position to check.
output: true or false
*/
bool Queen::isLegitMove(const string position)
{
	string currPosition = getPosition();

	bool diagonalMove = std::abs(currPosition[1] - position[1]) == std::abs(currPosition[0] - position[0]);
	bool straightMove = (std::abs(currPosition[0] - position[0]) >= 1 && std::abs(currPosition[1] - position[1]) == 0) || (std::abs(currPosition[0] - position[0]) == 0 && std::abs(currPosition[1] - position[1]) >= 1);

	return straightMove || diagonalMove;
}