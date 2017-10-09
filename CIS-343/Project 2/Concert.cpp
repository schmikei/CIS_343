/*********************************************************
*	Implementation of a Concert class
*	This class has two constructors that initialize variables
* 	Overloads the less-than operator for Concert objects
*	Overloads the cout operator for Concert objects
* 	also has a main method that creates 10 Concerts and
* 	then prints out a sorted list of them using std::sort
**********************************************************/

#include "Concert.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <iostream>

/******************************************************
*	Default Constructor
*  	initializes variables
******************************************************/
Concert::Concert(){
	concertName = "";
	friends = {};
	desire = -1;
	date.tm_year = 1;
	date.tm_mon = 1;
	date.tm_mday = 1;
}


/******************************************************
*	Constructor
*   Initializes based off of parameters
******************************************************/
Concert::Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date ){
	this -> concertName = concertName;
	this -> friends = friends;
	this -> desire = desire;
	this -> date = date;
}



/******************************************************
*	less-than (<) Operator Overload
*
*	providing a way to compare different Concerts 
*	by looking at dates first, and then by desire
******************************************************/
bool Concert::operator<(const Concert& other) const{

	if (this-> date.tm_year < other.date.tm_year){
		return true;
	}
	else if (this->date.tm_year == other.date.tm_year){
		if(this->date.tm_mon < other.date.tm_mon){
			return true;
		}
		else if(this->date.tm_mon == other.date.tm_mon){
			if (this->date.tm_mday < other.date.tm_mday){
				return true;
			}
			else if(this->date.tm_mday == other.date.tm_mday){
				if(this-> desire > other.desire){
					return true;
				}
			}
		}
	}

	return false;
}


/******************************************************
*	Getters
* -standard getters
******************************************************/
const std::string Concert::getConcertName(){
	return concertName;
}

const std::vector<std::string> Concert::getFriends(){
	return friends;
}

const int Concert::getDesire(){
	return desire;
}

const std::tm Concert::getDate(){
	return date;
}


/******************************************************
*	cout Overload operator
*
*	providing a way to print out Concerts 
*	Format = Name  MM/DD/YYYY  Desire: #
*   could add friends list via iterator
*  	just requires a loop
******************************************************/
std::ostream& operator<<(std::ostream& out, Concert  &c) {
    out << c.getConcertName() <<  ": " << c.getDate().tm_mon << '/' << c.getDate().tm_mday << '/'<< c.getDate().tm_year << "  Desire: "<< c.getDesire();
    return out;
}



/*************************************
*	Main Method

Sorted list 

my sorted list should be 

1: Drake - 1/1/1999 Desire: 1
2: B.O.B. - 1/28/1999 Desire: 1
3: Coldplay - 2/1/1999 Desire: 4
4: Taylor Swift - 2/1/2005 Desire: 1
5: Thomas Rhett - 5/5/2009 Desire: 1
6: Lumineers - 1/2/2017 Desire: 1
7: Ed Sheeran - 2/1/2017 Desire: 1
8: Jon Bellion - 7/4/2017 Desire 5
9: Bruno Mars- 7/4/2017 Desire 4
10: John Mayer - 7/4/2017 Desire 3
****************************************/
int main(int argc, char* argv[]){


	//I want pointers because moving objects is more expensive
	std::vector<Concert> ConcertList;

	/******************************************
	1: Drake - 1/1/1999
	******************************************/
	std::tm testDate_0;
	testDate_0.tm_year = 1999;
	testDate_0.tm_mon = 1;
	testDate_0.tm_mday = 1;

	//helped come up with main method with Dylan Ryan and Keith
	std::vector<std::string> friendSample {"Dylan", "Ryan", "Keith"};

	Concert* concert_0 = new Concert("Drake", friendSample, 1, testDate_0);
	ConcertList.push_back(*concert_0);


	/*****************************************
	 3: Coldplay - 2/1/1999
	*****************************************/
	std::tm testDate_1;
	testDate_1.tm_year = 1999;
	testDate_1.tm_mon = 2;
	testDate_1.tm_mday = 1;

	Concert* concert_1 = new Concert("Coldplay", friendSample, 4, testDate_1);
	ConcertList.push_back(*concert_1);


	/*****************************************
	 2: B.O.B. - 1/28/1999
	*****************************************/
	std::tm testDate_2;
	testDate_2.tm_year = 1999;
	testDate_2.tm_mon = 1;
	testDate_2.tm_mday = 28;


	Concert* concert_2 = new Concert("B.O.B", friendSample, 1, testDate_2);
	ConcertList.push_back(*concert_2);


	/*****************************************
	 4: Taylor Swift - 2/1/2005
	*****************************************/
	std::tm testDate_3;
	testDate_3.tm_year = 2005;
	testDate_3.tm_mon = 2;
	testDate_3.tm_mday = 1;


	Concert* concert_3 = new Concert("Taylor Swift", friendSample, 1, testDate_3);
	ConcertList.push_back(*concert_3);

	/*****************************************
	 7: Ed Sheeran - 2/1/2017
	*****************************************/
	std::tm testDate_4;
	testDate_4.tm_year = 2017;
	testDate_4.tm_mon = 2;
	testDate_4.tm_mday = 1;

	Concert* concert_4 = new Concert("Ed Sheeran", friendSample, 1, testDate_4);
	ConcertList.push_back(*concert_4);

	/*****************************************
	8:Jon Bellion - 7/4/2017 Desire 5
	*****************************************/
	std::tm testDate_5;
	testDate_5.tm_year = 2017;
	testDate_5.tm_mon = 7;
	testDate_5.tm_mday = 4;

	Concert* concert_5 = new Concert("Jon Bellion", friendSample, 5, testDate_5);
	ConcertList.push_back(*concert_5);

	/*****************************************
	6: Lumineers - 1/2/2017
	*****************************************/
	std::tm testDate_6;
	testDate_6.tm_year = 2017;
	testDate_6.tm_mon = 1;
	testDate_6.tm_mday = 2;

	Concert* concert_6 = new Concert("Lumineers", friendSample, 1, testDate_6);
	ConcertList.push_back(*concert_6);

	/*****************************************
	 5: Thomas Rhett - 5/5/2009
	*****************************************/
	std::tm testDate_7;
	testDate_7.tm_year = 2009;
	testDate_7.tm_mon = 5;
	testDate_7.tm_mday = 5;

	Concert* concert_7 = new Concert("Thomas Rhett", friendSample, 1, testDate_7);
	ConcertList.push_back(*concert_7);

	/*****************************************
	9: Bruno Mars- 7/4/2017 Desire 4
	*****************************************/
	std::tm testDate_8;
	testDate_8.tm_year = 2017;
	testDate_8.tm_mon = 7;
	testDate_8.tm_mday = 4;

	Concert* concert_8 = new Concert("Bruno Mars", friendSample, 4, testDate_8);
	ConcertList.push_back(*concert_8);

	/*****************************************
	10: John Mayer - 7/4/2017 Desire 3
	*****************************************/
	std::tm testDate_9;
	testDate_9.tm_year = 2017;
	testDate_9.tm_mon = 7;
	testDate_9.tm_mday = 4;

	Concert* concert_9 = new Concert("John Mayer", friendSample, 3, testDate_9);
	ConcertList.push_back(*concert_9);





	//printing and sorting the vector 
	std::cout<<"Here is the sorted list: "<<std::endl;

	std::sort(ConcertList.begin(), ConcertList.begin()+ConcertList.size());

	for (int i = 0; i < ConcertList.size(); ++i){
		std::cout<<ConcertList[i]<<std::endl;
	}


	//cleaning up memory
	delete(concert_0);
	delete(concert_1);
	delete(concert_2);
	delete(concert_3);
	delete(concert_4);
	delete(concert_5);
	delete(concert_6);
	delete(concert_7);
	delete(concert_8);
	delete(concert_9);

	
};
