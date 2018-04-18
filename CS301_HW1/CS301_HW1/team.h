#ifndef team_h
#define team_h
#include <iostream>
#include <string>
//Hal DiMarchi
//Header file for class Team

//Class Team
//Stores and Manages Team Name and Number of Wins
//Invariants:
//		0<=wins_
class Team {
// ******** Ctors, Dtors, Move and Copy
public:
	// Default Ctor
	//Sets name_ to an empty string
	//Sets wins_ to zero
	//Pre: none
	//Post: name_ is an empty string, wins_ is equal to zero
	Team() {
		setName("");
		setWins(0); 
	}
	//Ctor from data
	//Sets name_ and wins_ to whatever values are passed
	//Pre: wins >= 0
	//Post: name_ & wins_ are the values passed
	Team(std::string name, int wins) {
		setName(name);
		setWins(wins);
	}
	//The Big Five; using compiler generated versions
	Team(const Team & ) = default;
	Team(Team && ) = default;
	~Team() = default;
	Team & operator=(const Team & rhs) = default;
	Team & operator=(Team && rhs) = default;

	// ***** Team: General public functions *****
	//get, set, toString, compare functions, increment and decrement functions

	//getName
	//returns the name_ of the implicit team object
	//Pre: none
	//Post: Returns the proper name_ as a string
	std::string getName() const; // Defined in Source File
	
	//getWins
	//returns the wins_ of the implicit team object
	//Pre: none
	//Post: Returns the proper wins_ as an int
	int getWins() const; //Defined in Source File

	//setName
	//sets the name_ to a passed string
	//Pre: none
	//Post: name_ is equal to the passed string
	void setName(std::string name); //Defined in Source File

	//setWins
	//sets the wins_ to the value of a passed int
	//Pre: wins is greater than or equal to zero
	//Post: wins_ is equal to the passed value
	void setWins(int wins); //Defined in Source File

	//toString
	//returns the name and win count of a team object in the format "name_ ['Wins: 'wins_]"
	//Pre: none
	//Post: returns a string in the format described with the correct values
	std::string toString() const; //Defined in Source File

	//op ==
	//compares two team objects and returns true if their wins_ and names_ are equal
	//Pre: none
	//Post: a correct true or false value is returned
	friend bool operator==(const Team & lhs, const Team & rhs); //Defined in Source File
	//op !=
	//compares two team objects and returns true if their wins_ and names_ are NOT equal
	//Pre: none
	//Post: a correct true or false value is returned
	friend bool operator!=(const Team & lhs, const Team & rhs); //Defined in Source File

	//op++
	//adds a 1 to the implicit team object's wins_ and then returns it
	//Pre: none
	//Post: a 1 has been added to the implicit team object, and it has been returned with that value
	Team & operator++(); //Defined in Source File

	//++op
	//returns an implicit team object and then adds 1 to its wins_
	//Pre: none
	//Post: a 1 has been added to a copy of the implicit team object after it has been returned with its implicit value
	Team operator++(int); //Defined in Source File

	//op--
	//subtracts one from the implicit team objects wins_ and then returns it
	//Pre: wins_>0;
	//Post: one has been subtracted from the number of wins_ and then the implicit team object has been returned
	Team & operator--(); //Defined in Source File
	
	//--op
	//returns an implicit team object and then subtracts one from its number of wins_
	//Pre: wins_>=0
	//Post: a copy of the implicit team object has been returned and then one is subtracted from the original
	Team operator--(int); //Defined in Source File

	//ostream op<<
	//passes a toString representation of the team object to an ostream, and then returns the ostream
	//Pre: none
	//Post: a toString has been passed to an ostream, which has then been returned
	friend std::ostream & operator<<(std::ostream & os, const Team & rhs); //Defined in Source File



private:
	std::string name_;
	int wins_;
};









#endif
