// Final Project Milestone 1
//
// Version 1.0
// Date          29/NOV/2017
// Author        Hongback Son(133181164)
// Description   Milestone1
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H
#define SICT_DATE_H

#include <iostream>

namespace sict {
	
const int min_year = 2000;
const int max_year = 2030;
#define   NO_ERROR 0
#define   CIN_FAILED 1 
#define   YEAR_ERROR 2 
#define   MON_ERROR 3 
#define   DAY_ERROR 4 



	class Date {
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;

		void errCode(int errorCode);
		int value() const;


	public:
		//declare constructor of the class

		Date();
		Date(int, int, int);

		int mdays(int, int)const;
		// declare errCode
		int errCode() const;
		bool bad() const;

		//declare operator functions

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;


		//declare IO member-funtions

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};


	
	std::istream& operator >> (std::istream& istreamO, Date& d);
	std::ostream& operator << (std::ostream& ostreamO, const Date& s);

}
#endif