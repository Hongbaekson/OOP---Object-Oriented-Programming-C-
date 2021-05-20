// Final Project Milestone 5
//
// Version 1.0
// Date          07/Aug/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a header file of Milestone 5
//

#ifndef AMA_PERISHABLE_H__
#define AMA_PERISHABLE_H__

#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"


namespace AMA{

  class Perishable:public Product{

    private:
      
      Date expDate_;      

    public:

      // No-arg constructor
      Perishable();

      // Receives a reference to an fstream object and an optional bool and 
      // returns a reference to the modified fstream object. This function 
      // stores a single file record for the current object.
      std::fstream& store(std::fstream& file, bool newLine=true) const;

      // Receives a reference to an fstream object and returns a reference 
      // to that fstream object. This function extracts the data fields for 
      // a single file record from the fstream object.
      std::fstream& load(std::fstream& file);

      // Receives a reference to an ostream object and a bool flag and returns 
      // a reference to the modified ostream object.
      std::ostream& write(std::ostream& os, bool linear) const;

      // Receives a reference to an istream object and returns a reference to 
      // the modified istream object. This function populates the current 
      // object with the data extracted from the istream object.
      std::istream& read(std::istream& is);

      // Returns the expiry date for the perishable product.
      const Date& expiry() const;
  };


}
#endif
