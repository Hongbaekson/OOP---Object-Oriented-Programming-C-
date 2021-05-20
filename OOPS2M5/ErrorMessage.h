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


#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H


#include <iostream>
#include <cstring>

namespace sict {
	class ErrorMessage {
		char * m_message;

		public : 
			ErrorMessage();
			explicit ErrorMessage(const char* errorMessage);
			ErrorMessage(const ErrorMessage& em) = delete;
			
			ErrorMessage& operator=(const ErrorMessage& em) = delete;
			ErrorMessage& operator=(const char* errorMessage);
			
			virtual ~ErrorMessage();
			
			void clear();
			bool isClear() const;
			void message(const char* str);
			const char* message()const;

	};
	std::ostream& operator << (std::ostream& os, const ErrorMessage& err);
}

#endif