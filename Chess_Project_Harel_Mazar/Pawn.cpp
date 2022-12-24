#include "Pawn.h"

Pawn::Pawn(const string name, const string type, const string position) : Piece(name, type, position)
{
	this->isFirstMove = true;
}

string Pawn::move(const string newPosition)
{
	string returnString = to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);

	if (isLegitMove(newPosition) || isLegitEatingMove(newPosition))
	{
		setPosition(newPosition);
		returnString = to_string(LEGALMOVE);
	}

	return returnString;
}

bool Pawn::isLegitMove(const string position)
{
	string currPosition = getPosition();
	bool straightOnce = false;

	//black can move 1 forward which is backward for white
	if (isFirstMove)
	{
		isFirstMove = false;

		if (this->getName() == "P")
		{
			straightOnce = (currPosition[1] - position[1] == -2) || (currPosition[1] - position[1] == -1);
		}
		else
		{
			straightOnce = (currPosition[1] - position[1] == 2) || (currPosition[1] - position[1] == 1);
		}

	}
	else
	{
		if (this->getName() == "P")
		{
			straightOnce = currPosition[1] - position[1] == -1;
		}
		else
		{
			straightOnce = currPosition[1] - position[1] == 1;
		}

	}
	if (straightOnce)
	{
		return true;
	}

	return false;
}

bool Pawn::isLegitEatingMove(const string position)
{
	string currPosition = getPosition();

	bool diagonalOnce = false;

	//black can eat 1 diagonal forward which is backward for white
	if (getName() == "P")
	{
		diagonalOnce = currPosition[1] - position[1] == -1 && std::abs(currPosition[0] - position[0]) == 1;
	}
	else
	{
		diagonalOnce = currPosition[1] - position[1] == -1 && std::abs(currPosition[0] - position[0]) == 1;
	}

	if (diagonalOnce)
	{
		return true;
	}

	return false;
}