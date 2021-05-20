// Final Project Milestone 2
//
// Version 1.0
// Date          07/Aug/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a header file of Milestone 2
//

#ifndef AMA_ErrorState_H__
#define AMA_ErrorState_H__

#include <iostream>
#include <cstring>

namespace AMA {

  class ErrorState {

    private:

      char* message_;


    public:

      //declare default constructor
      ErrorState();

      //declare a constructor with an arguement
      ErrorState(const char* errorMessage);


      //declare a deleted copy constructor to prevent an ErrorMessage object to be copied.
      ErrorState(const ErrorState& em) = delete;

      //declare a deleted assignment operator overload to prevent an ErrorMessage object to be assigned to another
      ErrorState& operator=(const ErrorState& em) = delete;

      //
      ErrorState& operator=(const char* errorMessage);

      //declare a deconstructor
      virtual ~ErrorState();

      //declare clear function to deallocate new memory
      void clear();

      //declare the isClear function to check if the variable is nullptr or not
      bool isClear()const;

      //set the error message and make the error message equal to value
      void message(const char* value);

      //declare the function to show the error message
      const char* message()const;
  };


    // declare the helper function of stream. 
  std::ostream& operator<<(std::ostream& os, const ErrorState& errorMSG);

}
#endif
