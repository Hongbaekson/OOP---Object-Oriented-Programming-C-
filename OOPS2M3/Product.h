// Final Project Milestone 3
//
// Version 1.0
// Date          08/DEC/2017
// Author        Hongback Son(133181164)
// Description   
// This file is a header file of Milestone 3
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>

using namespace std;

namespace sict {
	class Product {


	public:
		virtual fstream& store(fstream& file, bool newLine = true) const = 0;
		virtual fstream& load(fstream& file) = 0;
		virtual ostream& write(ostream& os, bool linear) const = 0;
		virtual istream& read(istream& is) = 0;

		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char * name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const Product&) const = 0;


	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator >> (std::istream&, Product&);
	double operator+=(double&, const Product&);

	Product* CreateProduct();
	Product* CreatePerishable();
}
#endif