/***********************************************************
// OOP244 Workshop 3 : Classes and Privacy
// File CRA_Account.h
// Version 2.0
// Date : 27 - Sep - 2017
// Author : Dayoung Lee (121693162/dlee133@myseneca.ca)
// Description
// This file is a header file for w3_in_lab.cpp and CRA_Account.cpp
//
//
// Revision History
///////////////////////////////////////////////////////////
//Name            Date             Reason
//Dayoung Lee     27-SEP-2017
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999

using namespace std;

namespace sict {
	class CRA_Account {
		char m_familyName[MAX_NAME_LENGTH];
		char m_givenName[MAX_NAME_LENGTH];
		long long m_sin;
		
		
	public:
		
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
		
	};
}


#endif