// OOP244 Workshop 5: operators overloading
// File: w5_in_home.cpp
// Version: 1.0
// Date: 2018/06/17
// Author: HONGBACK SON
// Description:

/////////////////////////////////////////////



// header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// create namespace
namespace sict {

	//define the Fraction class
	class Fraction {

	private:
		int numberators;
		int denominators;

		// make safe empty state function

		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 
	public:
		//declare the member functions
		Fraction();
		Fraction(int number, int denomi);

		bool isEmpty() const;
		void display() const;

		//declare the + operator overload
		Fraction operator+(const Fraction&) const;

		//declare the * operator overload
		Fraction operator*(const Fraction&) const;

		//declare the == ioeratir overload (this doesn't return a value but return true or false)
		bool operator==(const Fraction&) const;

		//declare the != ioeratir overload (this doesn't return a value but return true or false)
		bool operator!=(const Fraction&) const;

		//declare the += ioeratir overload
		Fraction operator+=(const Fraction&);

	};
}
#endif