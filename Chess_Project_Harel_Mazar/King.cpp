#include "King.h"

King::King(const string name, const string type, const string position) : Piece(name, type, position)
{
}

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