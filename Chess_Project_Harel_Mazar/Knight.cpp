#include "Knight.h"

/*
constructor of Knight.
input: name, type and position of Piece.
output: none.
*/
Knight::Knight(const string name, const string type, const string position) : Piece(name, type, position)
{
}

/*
this function moves the Knight and returns if the function moved the Knight or not (return is by values that the frontend understands)
input: new position for Knight
output: code that the frondend understand.
*/
string Knight::move(const string newPosition)
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
this function returns if the Knight can reach given position
input: position to check.
output: true or false
*/
bool Knight::isLegitMove(const string position)
{
	string currPosition = getPosition();
	//yes I check every possible move.

	bool topLeftRight = currPosition[0] - position[0] == 1 && currPosition[1] - position[1] == -2;
	bool topLeftLeft = currPosition[0] - position[0] == 2 && currPosition[1] - position[1] == -1;
	bool topLeft = topLeftLeft || topLeftRight;

	bool topRightLeft = currPosition[0] - position[0] == -1 && currPosition[1] - position[1] == -2;
	bool topRightRight = currPosition[0] - position[0] == -2 && currPosition[1] - position[1] == -1;
	bool topRight = topRightLeft || topRightRight;


	bool bottomRightLeft = currPosition[0] - position[0] == -1 && currPosition[1] - position[1] == 2;
	bool bottomRightRight = currPosition[0] - position[0] == -2 && currPosition[1] - position[1] == 1;
	bool bottomRight = bottomRightLeft|| bottomRightRight;


	bool bottomLeftLeft = currPosition[0] - position[0] == 2 && currPosition[1] - position[1] == 1;
	bool bottomLeftRight = currPosition[0] - position[0] == 1 && currPosition[1] - position[1] == 2;
	bool bottomLeft = bottomLeftLeft || bottomLeftRight;


	return bottomLeft || bottomRight || topRight || topLeft;
}