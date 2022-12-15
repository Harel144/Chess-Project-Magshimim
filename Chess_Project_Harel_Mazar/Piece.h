#pragma once
#include <string>

using std::string;

class Piece
{
public:
	//c'tor
	Piece(string name, string type, string position);
	
	//setters and getters
	void setName(string name);
	void setPosition(string newPosition);
	void setType(string type);
	string getName();
	string getPosition();
	string getType();

	//other methods
	virtual int move(string newPosition) = 0;
	virtual bool isLegitMove(string position) = 0;
	
private:
	//fields
	string name;
	string type;
	string position;
};