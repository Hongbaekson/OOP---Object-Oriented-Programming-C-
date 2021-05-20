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

#define _CRT_SECURE_NO_WARNINGS


#include "NonPerishable.h"
#include "Product.h"
#include "ErrorMessage.h"

using namespace std;
namespace sict {
	// no argument constructor
	NonPerishable::NonPerishable() {
		type[0] = '\0';
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';

		m_Cquantity = 0;
		m_Nquantity = 0;
		m_price = 0.0;
		m_taxed = true;
	}
		
	// zero-one constructor
	NonPerishable::NonPerishable(const char * sku1, const char * name1, const char unit1[])
	{
		if (sku1 != nullptr) {
		strncpy(m_sku, sku1, max_sku_length);
		name(name1);
		strncpy(m_unit, unit1, max_unit_length);
		m_Cquantity = 0;
		m_Nquantity = 0;
		m_price = 0;
		}
		else {
			*this = NonPerishable();
		}
	
	}

	// seven arguemnts comstructor
	NonPerishable::NonPerishable(const char * sku1, const char * name1, const char * unit1, int quantity1, bool taxed1, double price1, int Nquantity1)
	{
		strncpy(m_sku, sku1, max_sku_length);
		name(name1);
		strncpy(m_unit, unit1, max_unit_length);
		quantity(quantity1);
		m_taxed = taxed1;
		m_price = price1;
		m_Nquantity = Nquantity1;
	}

	// copy constructor
	NonPerishable::NonPerishable(const NonPerishable & other)
	{
		m_name = nullptr;
		*this = other;
	}

	// copy Assignment operator
	NonPerishable & NonPerishable::operator=(const NonPerishable & other)
	{
		strncpy(m_sku, other.m_sku, max_sku_length);
		name(other.m_name);
		strncpy(m_unit, other.m_unit, max_unit_length);
		quantity(other.quantity());
		m_taxed = other.m_taxed;
		m_price = other.m_price;
		m_Nquantity = other.m_Nquantity;
		
		return *this;
	}

	// destructor
	NonPerishable::~NonPerishable()
	{
		if (m_name) {
			delete[] m_name;
		}
	}
	
	void NonPerishable::name(const char * name)
	{
		if (name != nullptr) {
			int length = strlen(name) + 1;
			m_name = new char[length + 1]; // create dynamic memory
			strncpy(m_name, name, length); // store the name in dynamically allocated
			m_name[length] = '\0';
		}
	}

	const char * NonPerishable::name() const
	{
		return m_name;
	}

	double NonPerishable::cost() const
	{
		double total = 0.0;
		if (m_taxed == true) {
			total = m_price * (taxrate + 1);
		}
		else
		{
			total = m_price;
		}
		return total;
	}

	double NonPerishable::total_cost() const
	{
		double totalCost = 0.0;
		return totalCost += quantity() * cost();
	}

	void NonPerishable::message(const char * message){ m_err.message(message); }
	bool NonPerishable::isClear() const { return m_err.isClear(); }
		

	void NonPerishable::quantity(int quantity1)
	{
		m_Cquantity = quantity1;
	}

	int NonPerishable::quantity() const
	{
		return m_Cquantity;
	}
	
	int NonPerishable::qtyNeeded() const
	{
		return m_Nquantity;
	}
	
	bool NonPerishable::isEmpty() const
	{
		bool result = false;
		if (m_sku[0] == '\0' && m_name == nullptr && m_price == 0.0 && m_taxed == true && m_Cquantity == 0 && m_Nquantity == 0) {
			result = true;
		}
		return result;
	}

	// ==operator overload
	bool NonPerishable::operator==(const char * other) const
	{
		bool result = false;
		if (strcmp(m_sku, other) == 0) { // compare objects
			result = true;
		}
		return result;
	}
	// >operator
	bool NonPerishable::operator>(const char * other) const
	{
		bool result = false;
		int compare = strcmp(other, m_sku);
		if (compare == 1) { // 'other' is greater than 'm_sku'
			result = true;
		}
		return result;
	}

	// += opeator
	int NonPerishable::operator+=(int addProduct)
	{
		if (addProduct > 0) {
			m_Cquantity += addProduct;
			return m_Cquantity;
		}
		else
			return m_Cquantity;
	}

	// >operator 
	bool NonPerishable::operator>(const Product & other) const
	{
		string a = other.name();
		string b = m_name;

		bool result = false;
		if (a > b) {
			result = true;
		}
		return result;
	}


	ostream & operator<<(ostream &ostr, const Product & mf)
	{
		return mf.write(ostr, true);
	}

	istream & operator>>(istream & istr, Product & mf)
	{
		return mf.read(istr);
	}

	double operator+=(double & d, const Product & p)
	{
		d += p.total_cost();
		return d;
	}

	fstream & NonPerishable::store(fstream & file, bool newLine) const
	{		
		
		return file;
	}


	fstream & NonPerishable::load(fstream & file)
	{		
		return file;
	}


	ostream & NonPerishable::write(ostream & os, bool linear) const
	{		
		return os;
	}

	istream & NonPerishable::read(istream & is)
	{		
		return is;
	}

	Product * CreateProduct()
	{
		NonPerishable * a = new NonPerishable();
		delete a;
		return 0;
	}

}