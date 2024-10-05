#include <string>
#include "profileTemplate.h"

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Customer" - Status: Complete
This class is inherited from Class "profileTemplate"
This class specifies these members below to define customer details
*/
class Customer : public profileTemplate {
/*
Delivered variables from profileTemplate
  # string phoneNumber
  # string firstName, lastName fullName;
Delivered functions from profileTemplate
  # void profileINFO()
  + profileTemplate()
  + profileTemplate(string pNum, string fName, string lName)
  + select_FullName()
  + select_PhoneNumber()
*/
  public:
    Customer();
    /* 
    Constructor of Customer
    Default Definition
      phoneNumber = ""
      firstName = ""
      lastName = ""
      fullName = ""
    */
    
  void add_CustomerINFO();
    /*
    Function to fill value of these members below
    phoneNum = tempNum;
    firstName = tempFName
    lastName = tempLName
    fullName = lastName + " " firstName
    phoneNum can only be assigned when tempNum is follow the template (Ex: 0909246357)
    */
};