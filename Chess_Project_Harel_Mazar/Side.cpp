#include "Side.h"

/*
constructor of Side.
input: none.
output: none.
*/
Side::Side()
{
	this->thisSideTurn = false;
	this->isChecked = false;
}

/*
this function adds a piece to Pieces field (vector).
input: pointer to piece to add.
output: none.
*/
void Side::addPiece(Piece* newPiece)
{
	this->Pieces.push_back(newPiece);
}

/*
this function remove a piece from Pieces field (vector).
input: position of piece to remove.
output: none.
*/
void Side::removePiece(const string position)
{

	for (int i = 0; i < this->Pieces.size(); i++)
	{
		Piece* currPiece = getPiecesVector()[i];
		if(currPiece->getPosition() == position)
		{
			this->Pieces.erase(this->Pieces.begin() + i);
			i = this->Pieces.size();
		}
	}
}

/*
this function returns the pieces field (vector)
input: none.
output: Pieces field
*/
vector<Piece*> Side::getPiecesVector() const
{
	return this->Pieces;
}

/*
this function changes the turn.
input: none.
output: none.
*/
void Side::changeTurnState()
{
	this->thisSideTurn = !this->thisSideTurn;
}

/*
this function returns if it's the side turn.
input: none.
output: true or false.
*/
bool Side::isItSideTurn() const
{
	return this->thisSideTurn;
}

/*
this function returns if one of this side pieces is at given location.
input: location to search a piece on.
output: true or false.
*/
bool Side::isOneOfMyPiecesAtXLocation(const string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getPosition() == location)
		{
			return true;
		}
	}
	return false;
}

/*
operator =
*/
Side Side::operator=(Side& otherSide)
{
	this->Pieces = otherSide.getPiecesVector();
	this->thisSideTurn = otherSide.isItSideTurn();
	return *this;
}

/*
this function returns the piece at given location. 
input: location to search a piece at.
output: The piece at the given location.
*/
//note: function is called only when there is a piece at the given location 100%
Piece* Side::getPieceAtLocationX(const string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getPosition() == location)
		{
			return this->Pieces[i];
		}
	}
}

/*
this function moves a piece at Pieces field from source position to destination position (both parameters)
input: source and destination (strings)
output: code that helps to communicate with the frondend (See Piece.h for code's values).
*/
string Side::movePiece(const string sourcePosOfPiece, const string destinationPosOfPiece)
{
	string returnString = to_string(ILLEGALMOVENOORIGINALPIECE);

	if (isOneOfMyPiecesAtXLocation(destinationPosOfPiece))
	{
		return to_string(ILLEGALMOVETHEREISALLY);
	}

	if (isOneOfMyPiecesAtXLocation(sourcePosOfPiece))
	{
		Piece* pieceAtXLocation = getPieceAtLocationX(sourcePosOfPiece);
		returnString = pieceAtXLocation->move(destinationPosOfPiece);
	}

	return returnString;
}

/*
This function returns if a piece at Pieces field can reach given location.
input: location to check if a piece can reach to.
output: true or false.
*/
bool Side::isOneOfMyPiecesCanReachXLocation(const string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		string oldPos = this->Pieces[i]->getPosition();

		if (this->Pieces[i]->isLegitMove(location))
		{
			return true;
		}
	}
	return false;
}

/*
this function returns the king piece location.
input: none.
output: king location.
*/
string Side::getKingLocation() const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getType() == "King")
		{
			return this->Pieces[i]->getPosition();
		}
	}
}

/*
this function sets check field.
input: new isChecked field's value.
output: none.
*/
void Side::setCheckState(const bool check)
{
	this->isChecked = check;
}

/*
this function checks if a pawn can eat from source to destination.
input: dource and destination locations to check
output: true or false.
*/
bool Side::isLegitEatingMoveForPawn(const string source,const string destination)
{
	bool diagonalOnce = false;
	Piece* pawnPiece = getPieceAtLocationX(destination);	//when function runs, the destination supposed to be the place of the pawn.

	//black can eat 1 diagonal forward which is backward for white
	if (pawnPiece->getName() == "P")
	{
		diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
	}
	else
	{
		diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
	}

	return diagonalOnce;
}