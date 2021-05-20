// Final Project Milestone 1
//
// Version 1.0
// Date          07/Aug/2018
// Author         Hongback Son(133181164)
// Description
// This file is a implementation file of Milestone 1
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"
using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_
  int Date::value() const {
    return year_ * 372 + mon_ * 13 + day_;
  }

  int Date::mdays(int mon_, int year_)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
    month--;
    return days[month] + int((month == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }

  void Date::errCode(int errorCode) {
    readErrorCode_ = errorCode;
  }

  int Date::errCode()const {
    return readErrorCode_;
  }

  bool Date::bad()const {
    bool confirm = false;
    if (readErrorCode_ != 0) {
      confirm = true;
    }
    return confirm;
  }

  // Set the default constructor
  Date::Date() {
    year_ = 0;
    mon_ = 0;
    day_ = 0;
    readErrorCode_ = NO_ERROR;
  }

  // Set the three argument constructor
  Date::Date(int yearNumber, int monthNumber, int dayNumber) {

    if (yearNumber < min_year || yearNumber > max_year || 
        monthNumber < 1 || monthNumber > 12 || 
        dayNumber < 1 || dayNumber > mdays(monthNumber, dayNumber)) {
      errCode(NO_ERROR);
      year_ = 0;
      mon_ = 0;
      day_ = 0;
    }

    else {
      year_ = yearNumber;
      mon_ = monthNumber;
      day_ = dayNumber;
      readErrorCode_ = NO_ERROR;

    }
  }

  //comparing object(integer values)
  bool Date::operator==(const Date & rhs) const {
    bool confirm = false;
    if (year_ == rhs.year_ && mon_ == rhs.mon_ && day_ == rhs.day_) {
      confirm = true;
    }
    return confirm;
  }

  //comparing object(integer values)
  bool Date::operator!=(const Date & rhs) const {
    bool confirm = true;
    if (*this == rhs) {
      
      confirm= false;
    }
    return confirm;
  }
  
  //comparing object
  bool Date::operator<(const Date & rhs) const {
    bool confirm;

    if (this->value() < rhs.value())
      confirm = true;
    else
      confirm = false;

    return confirm;
  }

  //comparing object
    bool Date::operator>(const Date & rhs) const {
    bool confirm;

    if (this->value() > rhs.value())
      confirm = true;
    else
      confirm = false;
    return confirm;
  }
  
  //comparing object
  bool Date::operator<=(const Date & rhs) const {
    bool confirm = false;

    if (this->value() <= rhs.value()) {
      confirm = true;
    }

    return confirm;
  }

  //comparing object
  bool Date::operator>=(const Date & rhs) const { 
    bool confirm = false;

    if (this->value() >= rhs.value()) {
      confirm = true;
    }

    return confirm;
   }

  
  istream & Date::read(istream & istr)
  {
    
    //to ignore the special characters such as / ? $ % and buffer need a syntax "cin.ignore(); " one by one
    //assigning values to each variable from the user console input
    istr >> year_;
    istr.ignore();
    
    istr >> mon_;
    istr.ignore();
    
    istr >> day_;
    
    // fail<-- built-in function in iostream
    // checking the integer values of year, momth and date if they are valid or not
    if (!(istr.fail())) {
      if (year_ < min_year|| year_ > max_year) {
        errCode(YEAR_ERROR);
        year_ = 0;
        mon_ = 0;
        day_ = 0;
      }
      else if (mon_ < 1 || mon_>12) {
        errCode(MON_ERROR);
        year_ = 0;
        mon_ = 0;
        day_ = 0;
      }
      
      else if (day_ < 1 || day_ > mdays(mon_, year_)) {
        errCode(DAY_ERROR);
        year_ = 0;
        mon_ = 0;
        day_ = 0;
      }
    }
    
    // error occured if above condition does not match 
    else {
      readErrorCode_= CIN_FAILED;
    }

    return istr;
  }
  
  // write on the console with the specific format provided 
  ostream & Date::write(ostream & ostr) const {
    ostr << year_;
    ostr << "/";
    if (mon_ < 10) { ostr << "0"; }
    ostr << mon_;
    ostr << "/";
    if (day_ < 10) { ostr << "0"; }
    ostr << day_;
    return ostr;
  }

  istream & operator >> (istream & istreamO, Date & d) {
    d.read(istreamO);
    return istreamO;
  }

  ostream & operator<<(ostream & ostreamO, const Date & s) {
    s.write(ostreamO);
    return ostreamO;
  }
  
}
