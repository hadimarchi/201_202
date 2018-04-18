#include "team.h"
//Hal DiMarchi
//Source file for class Team


//**************************************************************************
// Team public function definitions
//**************************************************************************

//Team, getName, header has docs
std::string Team::getName() const {
	return name_;
}

//Team, getWins, header has docs
int Team::getWins() const {
	return wins_;
}

//Team, setName, header has docs
void Team::setName(std::string name) {
	name_ = name;
}

//Team, setWins, header has docs
void Team::setWins(int wins) {
	if (wins < 0) {				//checks to ensure passed wins is greater than zero, wins cannot be negative
	}
	else {
		wins_ = wins;
	}
}

//Team, toString, header has docs
std::string Team::toString() const {
	std::string wins = std::to_string(getWins()); //creates a string representation of wins_
	std::string middle = " [wins: ";              //the middle dressing for rv
	std::string end = "]";						  //the end dressing for rv
	std::string rv = this->getName() + middle + wins + end; //creates rv as the combination of name_, wins, middle, end
	return rv;
}

//*************************************************************
// Operators for Team
//*************************************************************

//Team, == operator, header has docs
bool operator==(const Team & lhs, const Team & rhs) {
	bool names = (lhs.getName() == rhs.getName());   // bool for comparision of names_ of the two Team objects
	bool wins = (lhs.getWins() == rhs.getWins());	 // bool for comparison of wins_ of the two Team objects
	return names && wins;
}
//Team, != operator, header has docs
bool operator!=(const Team & lhs, const Team & rhs) {
	bool rv = (!(lhs == rhs));
	return rv;
}

//Team, ++op, header has docs
Team & Team::operator++() {
	++wins_;
	return *this;
}

//Team, op++, header has docs
Team Team::operator++(int) {
	Team copy = *this;    //creates a copy of implicit team object
	++*this;			  //preincrements team
	return copy;		  //returns copy, which has the original value
}

//Team, --op, header has docs
Team & Team::operator--() {
	if (getWins() == 0) {  //checks to make sure wins_ is greater than zero before subtracting from it
		return *this;
	}
	else {
		--wins_;
		return *this;
	}
}

//Team, op--, header has docs
Team Team::operator--(int) {
	Team copy = *this;	   //creats a copy of implicit team object
	--*this;               // predecrements team
	return copy;		   //returns copy, which has the original value
}

//Team, op<<, header has docs
std::ostream & operator<<(std::ostream & os, const Team & rhs) {
	os << rhs.toString();
	return os;
}
