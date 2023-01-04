#include "Pawn.h"

/*
constructor of Pawn.
input: name, type and position of Piece.
output: none.
*/
Pawn::Pawn(const string name, const string type, const string position) : Piece(name, type, position)
{
	changePawnMove(true);
}

/*
this function moves the Pawn and returns if the function moved the Pawn or not (return is by values that the frontend understands)
input: new position for Pawn
output: code that the frondend understand.
*/
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

/*
this function returns if the Pawn can reach given position
input: position to check.
output: true or false
*/
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
		if (this->getName() == "P")
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

/*
this function returns if the Pawn can reach given position while eating.
input: position to check.
output: true or false
*/
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
		diagonalOnce = currPosition[1] - position[1] == 1 && std::abs(currPosition[0] - position[0]) == 1;
	}

	return diagonalOnce;
}

