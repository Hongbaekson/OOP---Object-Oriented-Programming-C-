/***********************************************************
// OOP244 Workshop 4 : Constructors
// File Passenger.h
// Version 2.0
// Date : 04/Oct/2017
// Author : Hongback Son (hbson1@myseneca.ca 133181164 )
// Description
// This headfile excutes for w4_in_lab.cpp
//
//
// Revision History
///////////////////////////////////////////////////////////
//Name            Date             Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

using namespace std;

namespace sict {

	class Passenger {
		char m_name[32];
		char m_destination[32];
	public:
		Passenger();
		Passenger(const char name[], const char destination[]);
		bool isEmpty() const;
		void display() const;

	};

}
#endif