#include <string>
#include "objectTemplate.h"

using namespace std;

/*
Author: Nguyen Quang Minh
Contributor: Le Kim Bang, Tran Hong Nghiep
---
Class "Insurance" - Status: Complete
This class is inherited from Class "objectTemplate"
This class specifies these members below to define insurance details
*/
class Insurance : public objectTemplate {
/*
Delivered variables from objectTemplate
  # string ID           (Acronym of Insurance)
  # string name         (Name of Company providing Insurance)
*/
private:
  string description;
  /*
  (Details of Insurance)
  Header  
  (ID + " - Provided by " + name)
  Body (Extra Info)
  if (includeCollision == true) => "Include Collision Coverage"
  if (includeInjury == true) => "Include Injury Coverage"
  */

public:
  Insurance(string iID, string cpName, bool includeCollision, bool includeInjury);
  /*
  Constructor of Insurance to setup these menbers below
    ID = iID
    cpName = name
    desc = iID + name + desc
  Default Definition
    1. index is unassigned
    2. iID is "Undefined" when iID == ""
    3. cpName is "Undefined" when cpName == ""
    4. desc is "Undefined" ID or name is empty
    5. The body content will display if either includeCollision or includeInjury == true
  */
  
  string get_Description();
  // Function to return value of description
};