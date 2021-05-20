// Final Project Milestone 2
//
// Version 1.0
// Date          23/Mar/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a header file of Milestone 2
//
#define _CRT_SECURE_NO_WARNINGS

#include "ErrorState.h"

using namespace std;

namespace AMA{


	//implementation of a default constructor
	ErrorState::ErrorState() {

		message_ = nullptr;
	}

	//implementation of a constructor with an arguement
	ErrorState::ErrorState(const char* errorMessage) {
		
		message_ = nullptr;
		message(errorMessage);
	}

	//implementation of an operator 
	ErrorState& ErrorState::operator=(const char* errorMessage) {
		
		clear();
		message(errorMessage);

		return *this;
	}

	// implementation of de-allocate the momoney pointed by message_
	ErrorState::~ErrorState() {

		delete[] message_;
	}


	//implementation of flush dealocate memory
	void ErrorState::clear() {

		delete[] message_;
		message_ = nullptr;
	}


	// implementation of checking if the variable is cleared or not.
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


	// the variable message_ has the address itself. Thus, I do not need to put &<---mark.
	// char* message_; and char message[] ==> smae thing.
	const char*ErrorState::message()const {

		return message_;
	}

	//implementation of the helper fucntion for cout
	ostream& operator<<(ostream& os, const ErrorState& errorMSG) {
		
		if (!errorMSG.isClear()) {
			os << errorMSG.message();
		}

		return os;	
	}
}

