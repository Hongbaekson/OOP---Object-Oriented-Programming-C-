// Final Project Milestone 1
//
// Version 1.0
// Date          29/NOV/2017
// Author        HONGBACK SON(13318164)
// Description   
// This file is a cpp file of Milestone 1
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "ErrorMessage.h"

namespace sict {
	ErrorMessage::ErrorMessage()
	{
		m_message = nullptr;
	}

	ErrorMessage::ErrorMessage(const char * errorMessage)
	{
		m_message = nullptr;
		message(errorMessage);
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) 
	{
		clear();
		message(errorMessage);
		return *this;
	}

	ErrorMessage::~ErrorMessage()
	{
		delete[] m_message;		
	}

	void ErrorMessage::clear()
	{
		delete[] m_message;
		m_message = nullptr;
	}

	bool ErrorMessage::isClear() const
	{
		bool result = false;
		if (m_message == nullptr) {
			result = true;
		}
		return result;
	}

	void ErrorMessage::message(const char * str)
	{
		clear();
		m_message = new char[strlen(str) + 1];
		strcpy(m_message, str);
	}

	const char * ErrorMessage::message() const
	{
		return m_message;
	}

	std::ostream & operator<<(std::ostream & os, const ErrorMessage & err)
	{
		if (!err.isClear()) {
			os << err.message();
		}
		return os;
	}

}