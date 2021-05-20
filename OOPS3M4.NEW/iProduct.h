// Final Project Milestone 4
//
// Version 1.0
// Date          10/Apr/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a header file of Milestone 4
//

#ifndef AMA_IPRODUCT_H__
#define AMA_IPRODUCT_H__

#include <iostream>
#include <fstream>

namespace AMA{

  class iProduct {

    public:

        // Receives a reference to an fstream object and an optional bool and returns a reference to the fstream object
        virtual std::fstream& store(std::fstream& file, bool newLine=true)const = 0;

        // Receives a reference to an fstream object and returns a reference to that fstream object.
        virtual std::fstream& load(std::fstream& file) = 0;

        // Receives a reference to an ostream object and a bool and returns a reference to the ostream object
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;

        // Receives a reference to an istream object and returns a reference to the istream object. 
        virtual std::istream& read(std::istream& is) = 0;

        // Receive the address of an unmodifiable C-style null-terminated string and 
        // return true if the string is identical to the stock keeping unit of an iProduct record; false otherwise.
        virtual bool operator==(const char*) const = 0;

        // Return the address of a C-style null-terminated string containing the name of an iProduct.
        virtual double total_cost() const = 0;

        // Return the address of a C-style null-terminated string containing the name of an iProduct.
        virtual const char* name() const = 0;

        // Receive an integer holding the number of units of an iProduct that are currently available. 
        // This function will set the number of units available.
        virtual void quantity(int) = 0;

        // Return the number of units of an iProduct that are needed.
        virtual int qtyNeeded() const = 0;

        // Return the number of units of an iProduct that are currently available.
        virtual int quantity() const = 0;

        // Receive an integer identifying the number of units to be added to the iProduct and 
        // return the updated number of units currently available. 
        virtual int operator+=(int) = 0;

        // receive an unmodifiable reference to an iProduct object and return true if the current object is greater 
        // than the referenced iProduct object; false otherwise.
        virtual bool operator>(const iProduct&) const = 0;
    };



    // Receive a reference to an ostream object and an unmodifiable reference to an iProduct object and return a 
    // reference to the ostream object. 
    std::ostream& operator<<(std::ostream&, const iProduct&);

    // Receive a reference to an istream object and a reference to an iProduct object and return a reference to 
    // the istream object. 
    std::istream& operator>>(std::istream&, iProduct&);

    // Receive a reference to a double and an unmodifiable reference to an iProduct object and return a double. 
    double operator+=(double&, const iProduct&);

    // Return the address of a Product object.
    iProduct* CreateProduct();

    // Return the address of a Perishable object.
    iProduct* CreatePerishable();
}

#endif
