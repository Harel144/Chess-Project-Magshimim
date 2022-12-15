#pragma once
#include <string>

using std::string;

class Piece
{
public:
	//c'tor
	Piece(const string name, const string type, const string position);
	
	//setters and getters
	void setName(const string name);
	void setType(const string type);
	string getName() const;
	string getPosition() const;
	string getType() const;

	//other methods
	virtual int move(const string newPosition) = 0;
	virtual bool isLegitMove(const string position) = 0;
	
private:
	//fields
	string name;
	string type;
	string position;

	//methods
	void setPosition(const string newPosition);
};