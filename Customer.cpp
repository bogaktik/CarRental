#include <iostream>
#include <string>
#include <regex>
#include "Customer.h"

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Customer" -  Status: Working
This file contains the definitions of the functions to implement the operations of the class Customer.
*/

Customer :: Customer() : profileTemplate(){
  /*
  phoneNumber = "";
  firstName = "";
  lastName = "";
  fullName = "";
  */
}

void Customer :: add_CustomerINFO(){
  string tempNum, tempFName, tempLName;
  regex pattern_tempNum("^[0-9]{10}$");
  /*
  Pattern of tempNum
  ^         => Indicate the start of the string
  [0-9]{9}  => Require 10 Digits
  $         => Indicate the end of the string
  */
  
  bool check_tempNum;
  cout << "Provide Your Personal Info" << endl;
  
  do 
  {
    cout << "Phone Number: ";
    cin >> tempNum;
    check_tempNum = regex_match(tempNum, pattern_tempNum);
    if (check_tempNum == false)
      cout << "Phone Number \"" << tempNum << "\" is invalid!\n" << endl;
  } while(check_tempNum == false);
  
  phoneNumber = tempNum;
  cout << "First Name: ";
  cin >> tempFName;
  cout << "Last Name: ";
  cin >> tempLName;
  
  firstName = tempFName;
  lastName = tempLName;
  fullName = lastName + " " + firstName;
  
  cout<<"\nYour Info is successfully created!"<<endl;
  Customer :: profileINFO();
}