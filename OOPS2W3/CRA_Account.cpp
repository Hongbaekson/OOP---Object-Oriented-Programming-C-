/***********************************************************
// OOP244 Workshop 3 : Classes and Privacy
// File CRA_Account.cpp
// Version 2.0
// Date : 27 - Sep - 2017
// Author : Dayoung Lee (121693162/dlee133@myseneca.ca)
// Description
// This file is a cpp file for w3_in_lab.cpp
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name         Date         Reason
// Dayoung Lee  27-Sep-2017
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin >= MIN_SIN && sin <= MAX_SIN) { // if sin is a valid SIN
			strcpy_s(m_familyName, familyName);
			strcpy_s(m_givenName, givenName);
			m_sin = sin;
		}
		else {
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
			m_sin = 0;
		}
	
	}

	bool CRA_Account::isEmpty() const{
		bool result = true;
		if (m_sin <= MIN_SIN){
			return result;
		}else if(m_sin >= MAX_SIN) {
			return result;
		 }
		else
			return !result;
	}

	void CRA_Account::display() const{
		if (!isEmpty()) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}