#include "King.h"

King::King(const string name, const string type, const string position) : Piece(name, type, position)
{
}

bool King::GetisChecked() const
{
	return this->isCheacked;
}

void King::changeCheck()
{
	this->isCheacked = !this->isCheacked;
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

	//if someone tried to move more than 1 square
	if (std::abs(currPosition[0] - position[0]) != 1 || std::abs(currPosition[1] - position[1]) != 1)
	{
		return false;
	}

	return true;
}