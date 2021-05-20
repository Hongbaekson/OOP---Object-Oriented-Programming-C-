// Final Project Milestone 1
//
// Version 1.0
// Date          29/NOV/2017
// Author        HongbackSon(133181164)
// Description   
// This file is a cpp file of Milestone 1
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

#define NO_ERROR 0
#define	CIN_FAILED 1 
#define YEAR_ERROR 2 
#define	MON_ERROR 3 
#define	DAY_ERROR 4 

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {
	  int m_year;
	  int m_month;
	  int m_day;
	  int readErrorCode;
	  
	  void errCode(int errorCode);
	  int value() const;
	  int mdays(int, int)const;
 
  public:
	  Date();
	  Date(int, int, int);	  
	 
	  int errCode() const;
	  bool bad() const;

	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;	  

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
 
  };

  std::ostream& operator << (std::ostream& os, const Date& d);
  std::istream& operator >> (std::istream& is, Date& d);


}
#endif