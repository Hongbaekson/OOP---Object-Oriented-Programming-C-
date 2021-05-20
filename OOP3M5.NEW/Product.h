// Final Project Milestone 3
//
// Version 1.0
// Date          07/Aug/2018
// Author        Hongback Son (133181164)
// Description   
// This file is a header file of Milestone 3
//


#ifndef AMA_PRODUCT_H__
#define AMA_PRODUCT_H__

#include <iostream>
#include <cstring>
#include "ErrorState.h"
#include "iProduct.h"


namespace AMA{

  const int max_sku_length = 7;
  const int max_name_length = 10;
  const int max_unit_length = 75;
  const double tax = 13; // 13%

  class Product:public iProduct {

    private:

      char type_;
      char sku_[max_sku_length+1];
      char* nameProd_;
      char unitDesc_[max_unit_length+1];
      int numOnHand_;
      int numNeeded_;
      double priceSingleUnit_;
      bool taxable_;
      ErrorState errorState_;

    protected:

      //receives the address of a C-style null-terminated string that holds the name of the product. 
      void name(const char* nameProd);

      //returns the address of the C-style string that holds the name of the product. 
      const char* name() const;

      //returns the address of the C-style string that holds the sku of the product.
      const char* sku() const;

      //returns the address of the C-style string that holds the unit of the product. 
      const char* unit() const;

      //this query returns the taxable status of the product. 
      bool taxed() const;

      //this query returns the price of a single item of the product. 
      double price() const;

      //returns the price of a single item of the product plus any tax that applies to the product.
      double cost() const;

      //receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object. 
      void message(const char* msg);

      //returns true if the ErrorState object is clear; false otherwise.
      bool isClear() const;

    public:

    //zero-One argument Constructor 
    Product(char type = 'N');

    //Seven argument Constructor 
    Product(const char* sku, const char* nameProd, const char* unitDesc, int numOnHand = 0, 
            bool taxable = true, double priceSingleUnit = 0, int numNeeded = 0);

    //copy Constructor  
    Product(const Product& src);

    //copy assignment
    Product& operator=(const Product& src);
    
    //destructor
    ~Product();

    //receives a reference to an fstream object and an optional bool and returns a reference to the fstream object
    std::fstream& store(std::fstream& file, bool newLine=true)const;

    //receives a reference to an fstream object and returns a reference to that fstream object.
    std::fstream& load(std::fstream& file);

    //receives a reference to an ostream object and a bool and returns a reference to the ostream object
    std::ostream& write(std::ostream& os, bool linear) const;

    //receives a reference to an istream object and returns a reference to the istream object. 
    std::istream& read(std::istream& is);

    //receives the address of an unmodifiable C-style null-terminated string and returns true if the string is 
    //identical to the sku of the current object; false otherwise.
    bool operator==(const char* sku) const;

    //returns the total cost of all items of the product on hand, taxes included.
    double total_cost() const;

    //receives an integer holding the number of units of the Product that are on hand. 
    void quantity(int newNum);

    //returns true if the object is in a safe empty state; false otherwise.
    bool isEmpty() const;

    //returns the number of units of the product that are needed.
    int qtyNeeded() const;

    //returns the number of units of the product that are on hand.
    int quantity() const;

    //receives the address of a C-style null-terminated string holding a product sku and returns true if the sku 
    //of the current object is greater than the string stored at the received address (according to how the string 
    //comparison functions define ‘greater than’); false otherwise.
    bool operator>(const char* sku1) const;

    //receives an unmodifiable reference to a Product object and returns true if the name of the current object is 
    //greater than the name of the referenced Product object (according to how the string comparison functions define 
    //‘greater than’); false otherwise.
    bool operator>(const iProduct& prod) const;

    //receives an integer identifying the number of units to be added to the Product and returns the updated number 
    //of units on hand. If the integer received is positive-valued, this function adds it to the quantity on hand. 
    //If the integer is negative-valued or zero, this function does nothing and returns the quantity on hand (without modification).
    int operator+=(int toAdd);
  };

  //receives a reference to an ostream object and an unmodifiable reference to a Product object and returns a 
  //reference to the ostream object.
  std::ostream& operator<<(std::ostream& os, const iProduct& prod);

  //receives a reference to an istream object and a reference to a Product object and returns a reference to the istream 
  //object.
  std::istream& operator>>(std::istream& is, iProduct& prod);

  //receives a reference to a double and an unmodifiable reference to a Product object and returns a double. 
  double operator+=(double& total, const iProduct& prod);
}


#endif
