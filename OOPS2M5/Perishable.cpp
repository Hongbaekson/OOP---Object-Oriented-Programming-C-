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


#include "NonPerishable.h"
#include "Perishable.h"
#include "ErrorMessage.h"

namespace sict{
	
	Perishable::Perishable()
	{
		expiryD = Date();
	}
	char Perishable::type() const
	{
		return 'P';
	}

	const Date & Perishable::expiry() const
	{
		return expiryD;
	}

	fstream & Perishable::store(fstream & file, bool newLine) const
	{
		NonPerishable::store(file, false) << "," << expiryD;
		if (newLine == true) {
			file << endl;
		}
		return file;
	}

	fstream & Perishable::load(fstream & file)
	{
		
		NonPerishable::load(file);
		expiryD.read(file);

		return file;
	}

	ostream & Perishable::write(ostream & os, bool linear) const
	{
		NonPerishable::write(os, linear);
		if (isClear()) {
			if (linear == true) {
				os << expiryD;
			}
			else {
				os << endl << "Expiry date: " << expiryD;
			}
		}
		return os;
	}

	istream & Perishable::read(istream & is)
	{
		Date tempObject;

		NonPerishable::read(is);
		
		if (isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";
			is >> tempObject;

			if (tempObject.bad()) {
				switch (tempObject.errCode()) {
				case CIN_FAILED:
					message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					message("Invalid Day in Date Entry");
					break;
				}
				is.setstate(ios::failbit);
			}
			else {
				expiryD = tempObject;
			}
		}
		return is;
	}

	

	Product * CreatePerishable()
	{
		Perishable * a = new Perishable();
		delete a;
		return a;
	}
}