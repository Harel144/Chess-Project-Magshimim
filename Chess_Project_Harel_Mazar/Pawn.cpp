#include "Pawn.h"

Pawn::Pawn(const string name, const string type, const string position) : Piece(name, type, position)
{
	changePawnMove(true);
}

string Pawn::move(const string newPosition)
{
	string returnString = to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
	if (isLegitMove(newPosition) || isLegitEatingMove(newPosition))
	{
		if (isItFirstMove())
		{
			changePawnMove(false);
		}
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
	if (isItFirstMove())
	{
		if (this->getName() == "P")
		{
			straightOnce = ((currPosition[1] - position[1] == -2) || (currPosition[1] - position[1] == -1)) && (currPosition[0] - position[0] == 0);
		}
		else
		{
			straightOnce = (currPosition[1] - position[1] == 2) || (currPosition[1] - position[1] == 1) && (currPosition[0] - position[0] == 0);
		}

	}
	else
	{
		if (this->getName() == "p")
		{
			straightOnce = currPosition[1] - position[1] == -1 && (currPosition[0] - position[0] == 0);
		}
		else
		{
			straightOnce = currPosition[1] - position[1] == 1 && (currPosition[0] - position[0] == 0);
		}

	}

	return straightOnce;
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

