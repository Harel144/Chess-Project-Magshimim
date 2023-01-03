#include "Side.h"

Side::Side()
{
	this->thisSideTurn = false;
	this->isChecked = false;
}

void Side::addPiece(Piece* newPiece)
{
	this->Pieces.push_back(newPiece);
}

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

vector<Piece*> Side::getPiecesVector() const
{
	return this->Pieces;
}

void Side::changeTurnState()
{
	this->thisSideTurn = !this->thisSideTurn;
}

bool Side::isItSideTurn() const
{
	return this->thisSideTurn;
}

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

Side Side::operator=(Side& otherSide)
{
	this->Pieces = otherSide.getPiecesVector();
	this->thisSideTurn = otherSide.isItSideTurn();
	return *this;
}

//note: function is called only when there is a piece at the given location 100%
Piece* Side::getPieceAtLocationX(string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getPosition() == location)
		{
			return this->Pieces[i];
		}
	}
}

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

bool Side::isLegitEatingMoveForPawn(string source, string destination, string name)
{
	bool diagonalOnce = false;
	//black can eat 1 diagonal forward which is backward for white
	if (name == "P")
	{
		diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
	}
	else
	{
		diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
	}

	return diagonalOnce;
}

bool Side::isOneOfMyPiecesCanReachXLocation( string location)
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		string oldPos = this->Pieces[i]->getPosition();

		if (this->Pieces[i]->move(location) == "0" && this->Pieces[i]->getType() != "Pawn")
		{
			this->Pieces[i]->move(oldPos);
			return true;
		}

		if (this->Pieces[i]->getType() == "Pawn")
		{
			if (isLegitEatingMoveForPawn(oldPos, location, this->Pieces[i]->getName()) || this->Pieces[i]->move(location) == "0")
			{
				//forcing pawn back
				this->Pieces[i]->setPosition(oldPos);
				return true;
			}
			this->Pieces[i]->setPosition(oldPos);
		}
		this->Pieces[i]->move(oldPos);
	}
	return false;
}

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

void Side::setCheckState(const bool check)
{
	this->isChecked = check;
}
