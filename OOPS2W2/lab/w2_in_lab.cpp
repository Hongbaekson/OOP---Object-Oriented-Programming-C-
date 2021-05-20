
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Date 24/5,2018	
// Author Hongback Son (133181164 , hbson1@myseneca.ca)
// Description
//  to allocate and deallocate dynamic memory for an array of elements
    to resize the amount of dynamically allocated memory 

***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;


void read(sict::Kingdom&);

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	
	// TODO: declare the kingdoms pointer here (don't forget to initialize it)

	Kingdom* pKingdom = nullptr;

	
	cout << "==========\n" 
		 << "Input data\n" 
		 << "==========\n" 
		 << "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();
	if (count < 1) return 1;
	
	// TODO: allocate dynamic memory here for the kingdom pointer
	pKingdom = new Kingdom[count];
	
	for (int i = 0; i < count; ++i)
	{
		cout << "Kingdom #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for the kingdom i
	
		cout << "Enter the name of the Kingdom" <<": ";
		cin >> pKingdom[i].m_name;
		cout << "Enter the number of people living in " << pKingdom[i].m_name << ": ";
		cin >> pKingdom[i].m_population;
	}
	cout << "==========" << endl << endl;


	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// TODO: deallocate the dynamic memory here
	
	delete[] pKingdom;

	return 0;
}

void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}