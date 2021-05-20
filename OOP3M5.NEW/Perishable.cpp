// Final Project Milestone 5
//
// Version 1.0
// Date          07/Aug/2018
// Author         Hongback Son (133181164)
// Description   
// This file is a implementation file of Milestone 5
//
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <iomanip>
#include "Perishable.h"

namespace AMA {

  Perishable::Perishable():Product('P'){
  }

  std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
    Product::store(file, false);
    file << ',';
    expDate_.write(file); 
    if (newLine)
      file << std::endl;
   
    return file; 
  }

  std::fstream& Perishable::load(std::fstream& file){
    Product::load(file);
    file.get();
    expDate_.read(file);
    file.get();
    return file;
  }

  std::ostream& Perishable::write(std::ostream& os, bool linear) const{
    Product::write(os, linear);
    if ( isClear() && !isEmpty() ){
      if ( ! linear ){
        os << std::endl << " Expiry date: ";
      }
      expDate_.write(os);
    }

    return os;
  }

  std::istream& Perishable::read(std::istream& is){
    Date newDate;

    Product::read(is);
    std::cout << " Expiry date (YYYY/MM/DD): ";
    newDate.read(is);

    // if bad, set an error message
    if(newDate.bad()){
      is.setstate(std::ios::failbit);
      if ( newDate.errCode() == CIN_FAILED )
        message("Invalid Date Entry");
      else if  ( newDate.errCode() ==  YEAR_ERROR )
        message("Invalid Year in Date Entry");
      else if ( newDate.errCode() == MON_ERROR )
        message("Invalid Month in Date Entry");
      else if ( newDate.errCode() == DAY_ERROR )
        message("Invalid Day in Date Entry");
    }
    else{
      expDate_ = newDate;
    }
    return is;
  }

  const Date& Perishable::expiry() const{
    return expDate_;
  }




}
