#pragma once
#include <string>

#define LEGALMOVE 0
#define LEGALMOVECHECK 1
#define ILLEGALMOVENOORIGINALPIECE 2
#define ILLEGALMOVETHEREISALLY 3
#define ILLEGALMOVESELFCHECK 4
#define ILLEGALMOVEILLEGALPOSITION 5
#define ILLEGALMOVEILLEGALMOVEMENTOFPIECE 6
#define ILLEGALMOVENOMOVE 7
#define LEGALMOVEMATE 8

using std::string;
using std::to_string;

class Piece
{
public:
	//c'tor
	Piece(const string name, const string type, const string position);
	
	//setters and getters
	void setName(const string name);
	void setType(const string type);
	void changePawnMove();
	string getName() const;
	string getPosition() const;
	string getType() const;
	bool isItFirstMove() const;
	void setPosition(const string newPosition);

	//other methods
	virtual string move(const string newPosition) = 0;
	virtual bool isLegitMove(const string position) = 0;
	
private:
	//fields
	string name;
	string type;
	string position;
	bool isItFirstPawnMove;
};