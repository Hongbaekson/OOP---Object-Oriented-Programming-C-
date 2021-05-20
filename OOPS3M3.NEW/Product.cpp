// Final Project Milestone 3
//
// Version 1.0
// Date          31/07/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a implementation file of Milestone 3
//
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;

namespace AMA{

	void Product::name(const char* nameProd){
		if (nameProd == nullptr){
			nameProd_[0] = '\0';
		}
		else {
			strncpy(nameProd_, nameProd, max_name_length);
			nameProd_[max_name_length] = '\0';
		}
	}

	const char* Product::name() const{
		if (nameProd_ == nullptr){
			return "";
		}
		else {
			return nameProd_;
		}
	}

	const char* Product::sku() const{
		return sku_;	
	}

	const char* Product::unit() const{
		return unitDesc_;
	}

	bool Product::taxed() const{
		return taxable_;
	}

	double Product::price() const{
		return priceSingleUnit_;	
	}

	double Product::cost() const{
		double costToRet = 0;
		if (taxed()){
			costToRet = (1 + tax/100) * price();
		}
		else {
			costToRet = price();
		}
		return costToRet;
	}

	void Product::message(const char* msg){
		errorState_.message(msg);		
	}

	bool Product::isClear() const{
		return errorState_.isClear();
	}

	Product::Product(char type){
		type_ = type;
		sku_[0] = '\0';
		nameProd_ = nullptr;
		unitDesc_[0] = '\0';
		numOnHand_ = 0;
		numNeeded_ = 0;
		priceSingleUnit_ = 0;
		taxable_ = false;
		errorState_.clear();
	}

	Product::Product(const char* sku, const char* nameProd, const char* unitDesc, int numOnHand, 
									 bool taxable, double priceSingleUnit, int numNeeded){

		strncpy(sku_, sku, max_sku_length);
		sku_[max_sku_length] = '\0';

		nameProd_ = new char[max_name_length+1];
		name(nameProd);

		strncpy(unitDesc_, unitDesc, max_unit_length);
		sku_[max_sku_length] = '\0';

		numOnHand_ = numOnHand;
		numNeeded_ = numNeeded;
		priceSingleUnit_ = priceSingleUnit;
		taxable_ = taxable;

		errorState_.clear();
	}

	Product::Product(const Product& src){
		nameProd_ = nullptr;
		*this = src;
	}

	Product& Product::operator=(const Product& src){
		if (&src != this){
			type_ = src.type_;
			strcpy(sku_, src.sku());

			if (nameProd_ == nullptr){
				nameProd_ = new char[max_name_length+1];
			}	
			name(src.name());

			strcpy(unitDesc_, src.unit());	
			numOnHand_ = src.quantity();
			numNeeded_ = src.qtyNeeded();
			priceSingleUnit_ = src.price();
			taxable_ = src.taxed();
			message(src.errorState_.message());
		}

		return *this;

	}
	
	Product::~Product(){
		delete [] nameProd_;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine)const{
		file << type_ << "," << sku() << "," << name() << "," <<  unit()  << ","
				 << quantity() << "," << qtyNeeded() << "," << price() << "," << taxed() << ",";
		if (newLine) 
			file << endl;
		return file;
	}

	std::fstream& Product::load(std::fstream& file){

		char type_1;

		char sku_1[max_sku_length+1];
		char nameProd_1[max_name_length+1];
		char unitDesc_1[max_unit_length+1];

		int numOnHand_1;
		int numNeeded_1;
		double priceSingleUnit_1;
		bool taxable_1;

		char comma;

		file >> type_1 >> comma >> sku_1 >> comma >> nameProd_1 >> comma >> unitDesc_1 >> comma >>
						numOnHand_1 >> comma >> numNeeded_1 >> comma >> priceSingleUnit_1 >> comma >>
						taxable_1; 

		Product newProd(sku_1, nameProd_1, unitDesc_1, numOnHand_1, taxable_1, 
										priceSingleUnit_1, numNeeded_1);

		*this = newProd;
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const{
		if ( linear ){
			os  << left 
					<< setw(max_sku_length)	<< sku()			<< "|" 
					<< setw(20)						<< name()    		<< "|"
					<< right
					<< setw(7)						<< fixed << setprecision(2) << cost() << "|" 
					<< setw(4)						<< quantity() 	<< "|" 	
					<< left
					<< setw(10)						<< unit()       << "|" 	
					<< right
					<< setw(4)            << qtyNeeded()	<< "|";
		}
		else {
			os << "Sku: "								<< sku()				<< endl;
			os << "Name (no spaces): "	<< name()				<< endl;
			os << "Price: "							<< price()      << endl;
			if (taxable_)
				os << "Price after tax: " << cost()				<< endl;
			else
				os << "N/A" << endl;
			os << "Quantity on hand: "	<< quantity()   << endl;
			os << "Quantity needed: "		<< qtyNeeded()  << endl;
		}

		return os;
	}

	std::istream& Product::read(std::istream& is){

		//temp
		char sku_1[max_sku_length+1] = { 0 };
		char nameProd_1[max_name_length+1] = { 0 };
		char unitDesc_1[max_unit_length+1] = { 0 };
		bool taxable_1 = false;
		char taxable_char_1 = '\0';
		double priceSingleUnit_1 = 0;
		int numOnHand_1 = 0;
		int numNeeded_1 = 0;

		bool isSuccessful = true;

		// Set SKU
		cout << " Sku: ";
		is.getline(sku_1, sizeof(sku_1));

		if (is.fail()){
			is.clear();
			is.ignore(2000, '\n');
			isSuccessful = false;
		}	

		// Set NAME
		if ( isSuccessful ){
      cout << " Name (no spaces): ";
			is.getline(nameProd_1, sizeof(nameProd_1));

			if (is.fail()){
				is.clear();
				is.ignore(2000, '\n');
				isSuccessful = false;
			}	
		}

		// Set Unit
		if ( isSuccessful ){
			cout << " Unit: ";
			is.getline(unitDesc_1, sizeof(unitDesc_1));

			if (is.fail()){
				is.clear();
				is.ignore(2000, '\n');
				isSuccessful = false;
			}	
		}

		// Set tax
		if ( isSuccessful ){
			cout << " Taxed? (y/n): " ;
			is >> taxable_char_1;
			if ( taxable_char_1 == 'y' || taxable_char_1 == 'Y' ){
				taxable_1 = true;
				is.ignore(2000, '\n');
			}
			else if ( taxable_char_1 == 'n' || taxable_char_1 == 'N' ){
				taxable_1 = false;
				is.ignore(2000, '\n');
			}
			else{
				is.clear();
				is.ignore(2000, '\n');
        is.setstate( ios::failbit );
				isSuccessful = false;
        message("Only (Y)es or (N)o are acceptable");
			}
		}

		// Set Price
		if ( isSuccessful ){
			cout << " Price: " ;
			is >> priceSingleUnit_1;
			if (is.fail()){
				message("Invalid Price Entry");                              
				isSuccessful = false;
				is.clear();
			}
			is.ignore(2000, '\n');
		}

		// Set Quanity on hand
		if ( isSuccessful ){
			cout << " Quantity on hand: " ;
			is >> numOnHand_1;
			if (is.fail()){
				message("Invalid Quantity Entry");
				isSuccessful = false;
				is.clear();
			}
			is.ignore(2000, '\n');
		}

		// Set Quanity needed
		if ( isSuccessful ){
      cout << " Quantity needed: " ;
			is >> numNeeded_1;
			if (is.fail()){
				message("Invalid Quantity Needed Entry");
				isSuccessful = false;
				is.clear();
			}
			is.ignore(2000, '\n');
		}

		// Everything is good
		if ( isSuccessful ){
			Product newProd(sku_1, nameProd_1, unitDesc_1, numOnHand_1, taxable_1, 
											priceSingleUnit_1, numNeeded_1);

			*this = newProd;
		}

		return is;
	}

	bool Product::operator==(const char* sku) const{
		return strcmp(sku_, sku) == 0;
	}

	double Product::total_cost() const{
		return cost() * quantity();
	}

	void Product::quantity(int newNum){
		numOnHand_ = newNum;
	}

	bool Product::isEmpty() const{
		return	sku_[0] == '\0' && nameProd_ == nullptr && unitDesc_[0] == '\0' &&
						numOnHand_ == 0 && numNeeded_ == 0 && priceSingleUnit_ == 0 &&
						taxable_ && errorState_.isClear();
	}

	int Product::qtyNeeded() const{
		return numNeeded_;
	}

	int Product::quantity() const{
		return numOnHand_;
	}

	bool Product::operator>(const char* sku1) const{
		return strcmp(sku(), sku1) > 0;
	}

	bool Product::operator>(const Product& prod) const{
		return strcmp(name(), prod.name()) > 0;
	}

	int Product::operator+=(int toAdd){
		if ( toAdd > 0 ){
			quantity(quantity() + toAdd);			
		}
		return quantity();
	}

	// Helper functions

  std::ostream& operator<<(std::ostream& os, const Product& prod){
		prod.write(os, true);
		return os;
	}

  std::istream& operator>>(std::istream& is, Product& prod){
		prod.read(is);
		return is;
	}

  double operator+=(double& total, const Product& prod){
		total = total + prod.total_cost();
		return total;
	}
	
}
