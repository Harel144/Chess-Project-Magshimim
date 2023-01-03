#include "Knight.h"

Knight::Knight(const string name, const string type, const string position) : Piece(name, type, position)
{
}


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


bool Knight::isLegitMove(const string position)
{
	string currPosition = getPosition();
	//i check every possible move.

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