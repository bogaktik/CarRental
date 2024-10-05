#include <iostream>
#include <string>
#include "Driver.h"

using namespace std;

/*
Author: Nguyen Quang Minh
Contributor: Le Kim Bang, Tran Hong Nghiep
---
Class "Driver" - Status: Complete
This file contains the definitions of the functions to implement the operations of the class Driver.
*/

// Defining Driver constructor using profileTemplate constructor
Driver :: Driver(string dNum, string dFName, string dLName) : profileTemplate(dNum, dFName, dLName) {
  /*
  Passing Values to parameters in profileTemplate
  profileTemplate(string pNum, string fName, string lName)
  Example:
     Driver("0123456789", "Nghiep", "Tran")
  => profileTemplate("0123456789", "Nghiep", "Tran")
  */
}

bool Driver :: search_DriverINFO() {
  if (fullName.length() > 0 && phoneNumber.length() > 0)
    return true;
  else 
    return false;
}