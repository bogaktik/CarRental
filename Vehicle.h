#include "objectTemplate.h"
#include <string>

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Vehicle" - Status: Complete
This class is inherited from Class "objectTemplate"
This class specifies these members below to define vehicle details
*/
class Vehicle : public objectTemplate {
/*
Delivered variables from objectTemplate
  # string ID           (Plate Number of Vehicle)
  # string name         (Full name of Vehicle)
  # void INFO()         (Details of Vehicle)
*/
private:
  double modelPrice;     // (Based on vehicle model)
  string model,          // (Ex: Sedan, SUV, ...)
      color,
      brand, series,     // (name = brand + series)
      insuranceINFO;     // (Recieve Value of description in Insurance)
  bool isHidden;
  int vehicleIndex,      // (Number index of Vehicle in the lists)
      slots;             // (Not include delivery slots)
  /*
  Menber to check these conditions below
  Value of isHidden = true when
  ID = ""
  model = ""
  name = ""
  insuranceINFO = "" or "Undefined"
  price = 0;
  */

public:
  Vehicle(string vID, string vModel, string vBrand, string vSeries, string vColor, string vInsurance);
  /*
  Constructor of Vehicle to setup these menbers below
    ID = vID
    model = vModel
    brand = vBrand
    series = vSeries
    color = vColor
    insuranceINFO = vInsurance
  Default Definition
  1. index is unassigned
  2. vID must follow the template, else vID = "" (Template: ABC1234)
  3. model = vModel if vModel is not empty
  4. modelPrice depends on price on specific model, else = 0
  5. Either vBrand or vSeries is empty, fullName = ""
  6. Default color is black
  7. insuranceINFO = vInsurance when vInsurance is not empty
  */
  
  void set_VehicleIndex(int vIndex);
  // Function to setup current index based on size of specific objlist
  
  void INFO();
  // Function to display vehicle details (Not include ID, ishidden)
  
  bool search_Model(string tempModel);
  /*
  Function test if users input match any available vehicle model based these conditions
  1. isHidden == false
  2. tempModel == model
  */
  
  string get_VehicleINFO();
  // Function return color, model, name and ID of Vehicle
  
  double get_ModelPrice();
  // Function return modelPrice of Vehicle
};

// Enum class to define types of vehicle slots
enum vehicleSlots_preset {
  slotType_couple = 2,
  slotType_semiTruck = 4,
  slotType_standard = 5,
  slotType_family = 7,
  slotType_extended = 9,
};