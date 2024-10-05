#ifndef profileTemplate_H
#define profileTemplate_H

#include <string>

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
CLass "profileTemplate" - Status: Complete
This class specifies these members below to define personal profile
*/
class profileTemplate {
  protected:
    // Basic Personal Data of Profile
    string phoneNumber, 
      firstName, 
      lastName, 
      fullName;
  
  public:
    profileTemplate();
    /*
    Temporary Constructor of profileTemplate
    Default Definition
      phoneNumber = ""
      firstName = ""
      lastName = ""
      fullName = ""
    */
    
    profileTemplate(string pNum, string fName, string lName);
    /*
    Constructor of profileTemplate to setup these menbers below
      phoneNumber = pNum
      firstName = fName
      lastName = lName
    Default Definition
    1. If pNum is not follow the template, pNum = "" (Ex: 0909246357)
    2. Value of fullName is assigned based on these cases below
       If fName && lName == "" => fullName = ""
       If fName && lName != "" => fullName = fName + lName
       If only fName == ""     => fullName = lName
       If only lName == ""     => fullName = fName
    */
    
    void profileINFO();
    // Function to display profile details
    
    string get_profileINFO();
    // Function to return fullName and phoneNumber
};

// Base Class of "Customer", "Driver"

#endif