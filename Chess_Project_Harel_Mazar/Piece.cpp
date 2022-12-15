#include "Piece.h"

/*
c'tor of Piece
input: name of piece, piece's type and piece's current position on the board.
output: none.
*/
Piece::Piece(string name, string type, string position)
{
	this->name = name;
	this->position = position;
	this->type = type;
}

/*
this function changes the name of the piece.
input: new name of the piece.
output: none.
*/
void Piece::setName(string name)
{
	this->name = name;
}

/*
this function changes the position of the piece.
input: new position of the piece.
output: none.
*/
void Piece::setPosition(string newPosition)
{
	this->position = newPosition;
}

/*
this function changes the type of the piece.
input: new type of the piece.
output: none.
*/
void Piece::setType(string type)
{
	this->type = type;
}

/*
this function returns the name of the piece.
input: none.
output: name of the piece.
*/
string Piece::getName()
{
	return this->name;
}

/*
this function returns the position of the piece.
input: none.
output: position of the piece.
*/
string Piece::getPosition()
{
	return this->position;
}

/*
this function returns the type of the piece.
input: none.
output: type of the piece.
*/
string Piece::getType()
{
	return this->type;
}
