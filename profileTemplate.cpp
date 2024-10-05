#include "profileTemplate.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "profileTemplate" - Status: Complete
This file contains the definitions of the functions to implement the operations
of the class profileTemplate.
*/

profileTemplate ::profileTemplate() {
  phoneNumber = "";
  firstName = "";
  lastName = "";
  fullName = "";
}

profileTemplate ::profileTemplate(string pNum, string fName, string lName) {
  // Default Phone Number of profileTemplate
  regex pattern_pNum("^[0-9]{10}$");
  /*
  Pattern of customerID
  ^         => Indicate the start of the string
  [0-9]{9}  => Require 10 Digits
  $         => Indicate the end of the string
  */

  phoneNumber = (regex_match(pNum, pattern_pNum)) ? pNum : "";

  // Default Full Name of profileTemplate
  firstName = fName;
  lastName = lName;

  if (firstName.length() + lastName.length() == 0)
    fullName = "";
  else if (firstName.length() > 0 && lastName.length() > 0)
    fullName = lastName + " " + firstName;
  else if (firstName.length() == 0)
    fullName = lastName;
  else if (lastName.length() == 0)
    fullName = firstName;
}

void profileTemplate ::profileINFO() {
  cout << fullName;
  cout << "\nPhone Number: " << phoneNumber << "\n" << endl;
}

string profileTemplate ::get_profileINFO() {
  return fullName + ", " + phoneNumber;
}