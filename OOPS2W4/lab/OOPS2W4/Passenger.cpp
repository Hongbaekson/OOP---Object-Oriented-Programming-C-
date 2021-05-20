/***********************************************************
// OOP244 Workshop 4 : Constructors
// File Passenger.h
// Version 2.0
// Date : 07/jun/2018

// Author : Hongback Son (hbson1@myseneca.ca 133181164 )
// Description
//  this cpp file is excuted in w4_in_lab.cpp
//
//
// Revision History
///////////////////////////////////////////////////////////
//Name            Date             Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {

	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';

	}

	Passenger::Passenger(const char name[], const char destination[]) {
		m_name[0] = '\0';
		m_destination[0] = '\0';


		if (name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0') {
			strcpy(m_name, name);
			strcpy(m_destination, destination);


		}
		else {
		}
	}


	bool Passenger::isEmpty() const
	{
		bool yes;
		if (m_name != nullptr && m_destination != nullptr && m_name[0] != '\0' && m_destination[0] != '\0') { yes = false; }
		else { yes = true; }
		return yes;
	}






	void Passenger::display() const
	{
		if (false == this->isEmpty())
		{
			cout << m_name << " - " << m_destination << endl;

		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}
}
