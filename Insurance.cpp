#include <iostream>
#include <string>
#include "Insurance.h"

using namespace std;

/*
Author: Nguyen Quang Minh
Contributor: Le Kim Bang, Tran Hong Nghiep
---
Class "Insurance" - Status: Complete
This file contains the definitions of the functions to implement the operations of the class Insurance.
*/
Insurance :: Insurance(string iID, string cpName, bool includeCollision, bool includeInjury) {
  
  // Default ID of Insurance
  ID = (iID.length() > 0)? iID : "";
  // Default Name of Insurance
  name = (cpName.length() > 0)? cpName : "";
  // Default Description of Insurance
  
  if (ID.length() + name.length() > 0) 
  {
    description = ID + ", provided by " + name;
    if (includeCollision == true)
      description = description + "\n+ Include Collision Coverage";
    if (includeInjury == true)
      description = description + "\n+ Include Injury Coverage";
  }
  else description = "Undefined";
}

string Insurance :: get_Description() {
  return description;
}