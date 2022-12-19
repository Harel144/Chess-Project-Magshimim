#include "Side.h"

Side::Side()
{
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