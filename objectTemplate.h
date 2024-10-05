#ifndef objectTemplate_H
#define objectTemplate_H

#include <string>

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Object" - Status: Complete
This class specifies these members below to define objects details
*/

// Default Value of Any Invalid or Missing Object Data
class objectTemplate{
  protected:
    string ID;       // (Unique, replacable)
    string name;     // (Full name or Provider of Object)
    void INFO();     // (Details of Object, Customizable)
};

// Base Class of "Vehicle", "Insurance", "Booking", "Service"

#endif