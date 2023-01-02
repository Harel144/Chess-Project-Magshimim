#include "Queen.h"

Queen::Queen(const string name, const string type, const string position) : Piece(name, type, position)
{
}

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

bool Queen::isLegitMove(const string position)
{
	string currPosition = getPosition();

	bool diagonalMove = std::abs(currPosition[1] - position[1]) == std::abs(currPosition[0] - position[0]);
	bool straightMove = (std::abs(currPosition[0] - position[0]) >= 1 && std::abs(currPosition[1] - position[1]) == 0) || (std::abs(currPosition[0] - position[0]) == 0 && std::abs(currPosition[1] - position[1]) >= 1);

	return straightMove || diagonalMove;
}