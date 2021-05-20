// Final Project Milestone 2
//
// Version 1.0
// Date          07/Aug/2018
// Author         Hongback Son(133181164)
// Description   
// This file is a implementation file of Milestone 2
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "ErrorState.h"

using namespace std;

namespace AMA{

  ErrorState::ErrorState() {
    message_ = nullptr;
  }

  ErrorState::ErrorState(const char* errorMessage) {
    message_ = nullptr;
    message(errorMessage);
  }

  ErrorState& ErrorState::operator=(const char* errorMessage) {
    clear();
    message(errorMessage);

    return *this;
  }

  ErrorState::~ErrorState() {
    delete[] message_;
  }

  void ErrorState::clear() {
    delete[] message_;
    message_ = nullptr;
  }


  bool ErrorState::isClear() const {
    bool result = false;
    if (message_ == nullptr) {
      result = true;
    }
    return result;
  }


  void ErrorState::message(const char* value) {
    if (value){

      clear();

      //Confirming the number of letter length from the argument(parameter)
      int checkingLength = strlen(value) + 1;

      //allocatring new memory into the variable "message_"
      message_ = new char[checkingLength+1];

      //copy the value of the parameter "value" into the variable "message_ with the length"
      strncpy(message_, value, checkingLength);
    }
    else {
      message_ = nullptr;
    }

  }

  const char*ErrorState::message()const {
    return message_;
  }

  ostream& operator<<(ostream& os, const ErrorState& errorMSG) {
    if (!errorMSG.isClear()) {
      os << errorMSG.message();
    }

    return os;  
  }
}

