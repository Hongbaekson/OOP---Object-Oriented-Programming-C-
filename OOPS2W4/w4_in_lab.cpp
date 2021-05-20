/***********************************************************
// OOP244 Workshop 4 : Constructors
// File Passenger.h
// Version 2.0
// Date : 04/Oct/2017
// Author : Hongback Son (hbson1@myseneca.ca 133181164 )
// Description
//  This main Cpp is about constructor function and the constructor that initializes an object's data at creation time
//  in addition, constructor that sets an object to a safe empty state
//
// Revision History
///////////////////////////////////////////////////////////
//Name            Date             Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#include <iostream>
#include "Passenger.h"
#include "Passenger.h" // this is intentional

using namespace std;
using namespace sict;

int main()
{
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passenger 5 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger vanessa("Vanessa", "Paris"),
		      mike("Mike", "Tokyo"),
		      alice("Alice", "Paris");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	travellers[0].display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
