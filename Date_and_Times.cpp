// Date_and_Times.cpp
// Name: Veronica 
// Date: 2021-04-19

#include <iostream>
#include "Date_and_Times.h"

using namespace std;

//Constructor for the Date_and_Time objects
Date_and_Times::Date_and_Times(Date date, Time *time, const size_t numberOfTimes)
	: _date(date), _timePtr(new Time[_size]), _size(numberOfTimes)
{
	if (numberOfTimes < 0) {
		throw invalid_argument("The size of the array of the Time objects must be greater than 0");
	}

	for (size_t i = 0; i < this->_size; ++i) {
		this->_timePtr[i] = time[i];
	}
}

//Copy constructor
Date_and_Times::Date_and_Times(const Date_and_Times & objToCopy)
	:_date(objToCopy._date), _size(objToCopy._size), _timePtr(new Time[_size])
{
	for (size_t i = 0; i < this->_size; ++i) {
		this->_timePtr[i] = objToCopy._timePtr[i];
	}
}

//Destructor
Date_and_Times::~Date_and_Times() {
	
	delete[] this->_timePtr;
	this->_size = 0;
	this->_timePtr = nullptr;
}

//Overload assignment operator
const Date_and_Times & Date_and_Times::operator= (const Date_and_Times& objToCopyFrom) {
	
	if (&objToCopyFrom != this) {

		if (this->_size != objToCopyFrom._size) {
			delete[] this->_timePtr;
			this->_size = objToCopyFrom._size;
			this->_timePtr = new Time[this->_size];
		}

		this->_date = objToCopyFrom._date;

		for (size_t i = 0; i < this->_size; ++i) {
			this->_timePtr[i] = objToCopyFrom._timePtr[i];
		}

	}

	return *this;

}

//Display Date and Times
void Date_and_Times::display() const {
	
	cout << "The date is: ";
	this->_date.print();
	
	cout << "\nThe times are:\n";
	for (int i = 0; i < _size; i++) {
		this->_timePtr[i].printUniversal();
		cout << " ";
	}
	cout << "\n\n";
}

//adds 5 seconds to each Time object
void Date_and_Times::addFiveSecs() {

	for (size_t i = 0; i < _size; i++) {

		this->_timePtr[i].setSecond(this->_timePtr[i].getSecond() + 5);

	}	
}