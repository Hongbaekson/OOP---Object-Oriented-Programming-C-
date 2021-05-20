// Final Project Milestone 1
//
// Version 1.0
// Date          29/NOV/2017
// Author        HongbackSon(133181164)
// Description   
// This file is a cpp file of Milestone 1
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////


#ifndef PERISHABLE_H
#define PERISHABLE_H

#include <iostream>
#include "Date.h"
#include "Product.h"
#include "NonPerishable.h"
#include "ErrorMessage.h"


using namespace std;
namespace sict {
	class Perishable : public NonPerishable {
		
	private:
		Date expiryD;

	protected: 
		char type()const;
	
	public:
		Perishable();

		fstream& store(fstream& file, bool newLine = true) const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear) const;
		istream& read(istream& is);
		const Date& expiry() const;
	};

	Product* CreatePerishable();

}


#endif
