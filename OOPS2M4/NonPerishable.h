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


#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "ErrorMessage.h"
#include "Product.h"

const int max_sku_length = 7;
const int max_unit_length = 10;
const int max_name_length = 75;
const double taxrate = 0.13;

namespace sict {

	class NonPerishable : public Product
	{
	private: 
		// private instance members
		char type[20];
		char m_sku[max_sku_length + 1]; 
		char *m_name; 
		char m_unit[max_unit_length + 1]; 
		int m_Cquantity;
		int m_Nquantity;
		double m_price;
		bool m_taxed;
		ErrorMessage m_err;

		
	protected:
		// protected member functions
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	
		
	public:
		// public member functions
		NonPerishable(); // no argument constructor
		NonPerishable(const char*, const char*, const char unit1[]); // zero-one argument constructor
		NonPerishable(const char* sku1, const char* name1, const char* unit1, int quantity1, bool taxed1, double price1, int Nquantity1); // seven argument constructor
		NonPerishable(const NonPerishable &other); // copy constructor
		NonPerishable& operator=(const NonPerishable &other); // copy assignment operator
		~NonPerishable(); // destructor
		
		
		double total_cost() const;
		void quantity(int);
		int quantity() const;		
		int qtyNeeded() const;
		

		// isEmpty function
		bool isEmpty() const;	
		// operator functions
		bool operator==(const char*) const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;


		fstream& store(fstream& file, bool newLine = true) const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear) const;
		istream& read(istream& is);
	};
	
	// helper functions
	ostream& operator<<(ostream&, const Product&);
	istream& operator>>(istream&, Product&);
	double operator+=(double&, const Product&);

	Product* CreateProduct();
}

#endif