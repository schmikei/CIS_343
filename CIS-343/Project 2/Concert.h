#ifndef Concert
/*********************************************************

A class that holds information about a given concert 
and implements overloading of comparison and cout print
functions

@author Keith Schmitt
**********************************************************/

#include <string>
#include <vector>
#include <ctime>

class Concert
{
	public:

		/******************************************************
		*	Default Constructor
		*  initializes variables to dummy variables
		******************************************************/
		Concert();


		/******************************************************
		*	Constructor
		*   Initializes based off of parameters
		******************************************************/
		Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date );



		/******************************************************
		*	less-than (<) Operator Overload
		*
		*	providing a way to compare different Concerts 
		*	by looking at dates first, and then by desire
		******************************************************/
		bool operator<(const Concert& other) const;

		
		/******************************************************
		*	Getters
		* -standard getters
		*******************************************************/
		const std::string getConcertName();
		const std::vector<std::string> getFriends();
		const int getDesire();
		const std::tm getDate();



		/******************************************************
		*	less-than (<) Operator Overload
		*
		*	providing a way to compare different Concerts 
		*	by looking at dates first, and then by desire
		******************************************************/
		std::ostream& operator<<(std::ostream& out, Concert  &c);

	private:

		// A string holding the name of the Concert
		std::string concertName;

		// A list of the people you want
		// to take with you.  May be empty
		// or arbitrarily full.
		std::vector<std::string> friends;

		// A value from 1-10 concerning how
		// badly you want to see this show.
		int desire;

		// The date of the show
		// See http://en.cppreference.com/w/cpp/chrono/c/tm
		std::tm date;

	
};

#endif
