/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Date 24/5,2018
// Author Hongback Son (133181164 , hbson1@myseneca.ca)
// Description
//  ---to allocate and deallocate dynamic memory for an array of elements
    ---to resize the amount of dynamically allocated memory 
***********************************************************/


// TODO: header safeguards
#ifndef WESTEROS_KINGDOM_H_
#define WESTEROS_KINGDOM_H_

using namespace std;
// TODO: sict namespace
// TODO: add the declaration for the function display(...),
//         also in the sict namespace

namespace sict {

	class Kingdom {
	public:
		char m_name[32];
		int m_population;

		
		

	};

	void display(Kingdom&);

}








#endif
