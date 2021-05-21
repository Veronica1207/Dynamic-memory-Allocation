// Date_and_Times.h
// Name: Veronica 
// Date: 2021-04-19

#ifndef DATE_AND_TIMES_H
#define DATE_AND_TIMES_H

#include "Date.h"
#include "Time.h"

// class Date_and_Times definition
class Date_and_Times
{
public:

   // You supply missing functions here
	Date_and_Times(Date, Time *, const size_t);		//constructor
	Date_and_Times(const Date_and_Times &);		//copy constructor
	~Date_and_Times();		//destructor

	const Date_and_Times & operator=(const Date_and_Times&);	//assignment operator overloading

	void display() const;		//display Date and Times
   
   // For simplicity sake, you need not worry about seconds value becoming greater than 59.
   void addFiveSecs();  // adds 5 seconds to each Time object

private:
	size_t _size;  // # of Time objects to be created dynamically
	Date _date;    // Date object
	Time * _timePtr; //ptr to array of Time objects created dynamically

}; // end class Date_and_Times

#endif
