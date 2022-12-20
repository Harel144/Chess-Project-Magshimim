#include "Bishop.h"

Bishop::Bishop(const string name, const string type, const string position) : Piece(name, type, position)
{
}

string Bishop::move(const string newPosition)
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
this function checks if the position is legit for this piece and returns true if legit and false otherwise.
input: new position.
output: true if it's a legit bishop move and false otherwise.
*/
bool Bishop::isLegitMove(const string position)
{
	string currPosition = getPosition();

	//if someone tried to make an undiagonal move with the bishop
	if (std::abs(currPosition[0] - position[0]) != std::abs(currPosition[1] - position[1]))
	{
		return false;
	}

	return true;
}