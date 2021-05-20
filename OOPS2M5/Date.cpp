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

#include <iostream>
#include <iomanip>
#include "Date.h"

namespace sict {

  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  int Date::value() const
  {
	  return m_year * 372 + m_month * 13 + m_day;
  }

  Date::Date()
  {
	  m_year = 0;
	  m_month = 0;
	  m_day = 0;
	  readErrorCode = NO_ERROR;
  }

  Date::Date(int year1, int month1, int day1)
  { 
	  int day_result = mdays(month1, year1);
	  if (year1 >= min_year && year1 <= max_year) {
			m_year = year1;				  
			readErrorCode = NO_ERROR;		
				if (month1 >= 1 && month1 <= 12) {
					  m_month = month1;
					  readErrorCode = NO_ERROR;

					  if (day1 >= 1 && day1 <= day_result) {
						  m_day = day1;
						  readErrorCode = NO_ERROR;
					  }			
					
				}		
			
		} else {
		  year1 = 0;
		  month1 = 0;
		  day1 = 0;
		  m_year = year1;
		  m_month = month1;
		  m_day = day1;
		  readErrorCode = NO_ERROR;
	  }	 
  }




  bool Date::operator==(const Date & rhs) const
  {
	  bool check = false;	
	  if (m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day) {
		  check = true;
	  }
	  return check;
  }

  bool Date::operator!=(const Date & rhs) const
  {
	  bool check = false;
	  if (m_year != rhs.m_year || m_month != rhs.m_month || m_day != rhs.m_day) {
		  check = true;
	  }
	  return check;
  }

  bool Date::operator<(const Date & rhs) const
  {
	  bool check = false;
	  if (this->value() < rhs.value()) {
		  check = true;
	  }
	  else
		  check = false;
		  return check;
  }

  bool Date::operator>(const Date & rhs) const
  {
	  bool check = false;
	  if (this->value() > rhs.value()) {
		  check = true;
	  }
	  else
		  check = false;
		  return check;
  }

  bool Date::operator<=(const Date & rhs) const
  {
	  bool check = false;
	  if (this->value() <= rhs.value()) {
		  check = true;
	  }
	  return check;
  }

  bool Date::operator>=(const Date & rhs) const
  {
	  bool check = false;
	  if (this->value() >= rhs.value()) {
		  check = true;
	  }
	  return check;
  }

  void Date::errCode(int errorCode)
  {
	  readErrorCode = errorCode;
  }

  int Date::errCode() const
  {
	  return readErrorCode;
  }

  bool Date::bad() const
  {
	  return readErrorCode != 0;
  }

  std::istream & Date::read(std::istream & istr)
  {
	 
	  istr >> m_year;
	  istr.ignore();
	  istr >> m_month;
	  istr.ignore();
	  istr >> m_day;
	  int day_result = mdays(m_month, m_year);
	 
	 if (!(istr.fail())) {
		  if (m_year < min_year || m_year > max_year) {
			  readErrorCode = YEAR_ERROR; 
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
		  }
		  else if (m_month < 1 || m_month > 12) {
			  readErrorCode = MON_ERROR;
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
		  }
		  else if (m_day < 1 || m_day > day_result) {
			  readErrorCode = DAY_ERROR;
			  m_year = 0;
			  m_month = 0;
			  m_day = 0;
		  }
	  }
	  else {
		  readErrorCode = CIN_FAILED;
	  }

	  
	  return istr;
  }

  std::ostream & Date::write(std::ostream & ostr) const
  {
	  ostr << m_year << "/";
	  if (m_month < 10) {
		  ostr << "0";
	  }
	  ostr << m_month << "/";
	  if (m_day < 10) {
		  ostr << "0";
		  }
	  ostr << m_day;
	  

	  return ostr;
  }

  std::ostream & operator<<(std::ostream & os, const Date & d)
  {
	  return d.write(os);
  }
  std::istream & operator>>(std::istream & is, Date & d)
  {
	  return d.read(is);
  }

}