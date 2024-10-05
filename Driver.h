#include <string>
#include "profileTemplate.h"

using namespace std;

/*
Author: Nguyen Quang Minh
Contributor: Le Kim Bang, Tran Hong Nghiep
---
Class "Driver" - Status: Complete
This class is inherited from Class "profileTemplate"
This class specifies these members below to define driver details
*/
class Driver : public profileTemplate {
/*
Delivered variables from profileTemplate
  # string phoneNumber
  # string firstName, lastName fullName;
Delivered functions from profileTemplate
  # void profileINFO()
  + profileTemplate()
  + profileTemplate(string pNum, string fName, string lName)
  + string get_profileINFO();
*/
  public:
    Driver(string dNum, string dFName, string dLName);
    /*
    Main constructor to setup values for these menbers below
      phoneNumber = dNum
      firstName = dFName
      lastName = dLName
    Default Definition
    1. If dNum is not follow the template => dNum = ""
    2. Value of fullName is assigned based on these cases below
       If dFName && dLName == "" => fullName = ""
       If dFName && dLName != "" => fullName = dFName + dLName
       If only dFName == ""      => fullName = dLName
       If only dLName == ""      => fullName = dFName
    */
    
  bool search_DriverINFO();
    // Function to check drivers with valid data
};