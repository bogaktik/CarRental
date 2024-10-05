#include "Vehicle.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Vehicle" - Status: Complete
This file contains the definitions of the functions to implement the operations
of the class Vehicle.
*/

Vehicle ::Vehicle(string vID, string vModel, string vBrand, string vSeries,
                  string vColor, string vInsurance) 
{
  // Default ID of Vehicle
  regex pattern_vID("^[A-Z]{3}[0-9]{4}$");
  /*
  Pattern of vehicleID
  ^        => Indicate the start of the string
  [A-Z]{3} => Require 3 Uppercases
  [0-9]{4} => Require 4 Digits
  $        => Indicate the end of the string
  */
  
  ID = (regex_match(vID, pattern_vID)) ? vID : "";
  
  // Default Model of Vehicle
  model = (vModel.length() > 0) ? vModel : "";
  
  // Default Model Price and Slots of Vehicle
  /*
  Lists of Cheapest Vehicle Price per day in the United States
  Source: https://www.kayak.com/United-States-Car-Rentals.253.crc.html
  If model = Exact Name of Model in kayak.com
  => modelPrice = Price per day of Model in kayak.com
  Example:
  If model = "MiniVan"   => Price per day of MiniVan in kayak.com
  Additional Notes:
  If model = "SUV"       => modelPrice = Price of Standard SUV Car
  If model = "Sedan"     => modelPrice = Price of Compact Medium Car
  If model = "Hatchback" => modelPrice = Price of Standard Large Car
  */
  
  modelPrice = 0;
  slots = 0;
  
  if (model == "SUV") {
    modelPrice = 30;
    slots = slotType_family;
  }
  if (model == "Sedan") {
    modelPrice = 12;
    slots = slotType_standard;
  }
  if (model == "Minivan") {
    modelPrice = 27;
    slots = slotType_extended;
  }
  if (model == "Pickup") {
    modelPrice = 34;
    slots = slotType_semiTruck;
  }
  if (model == "Hatchback") {
    modelPrice = 16;
    slots = slotType_standard;
  }
  if (model == "Convertible") {
    modelPrice = 55;
    slots = slotType_standard;
  }
  if (model == "Minibus") {
    /*
    Source: https://fash.com/costs/limo-rental-cost
    Large Limousine (10-16 Seats)
    Average Price = ($90 + $150) / 2 = $120
    */
    modelPrice = 120;
    slots = slotType_extended + 3;
  }
  if (model == "Crossover") {
    modelPrice = 26;
    slots = slotType_family;
  }
  
  // Default Name of Vehicle
  brand = vBrand;
  series = vSeries;
  name = brand + " " + series;
  
  if (brand.length() == 0 || series.length() == 0)
    name = "";
  
  // Default Color of Vehicle
  color = (vColor.length() > 0) ? vColor : "Black";
  
  // Default Insurance INFO of Vehicle
  insuranceINFO = (vInsurance.length() > 0) ? vInsurance : "";
  
  // Default isHidden of Vehicle
  if (ID.length() <= 0)
    isHidden = true;
  else if (model.length() <= 0)
    isHidden = true;
  else if (name.length() <= 0)
    isHidden = true;
  else if (insuranceINFO.length() <= 0 || insuranceINFO == "Undefined")
    isHidden = true;
  else if (modelPrice <= 0)
    isHidden = true;
  else
    isHidden = false;
}

void Vehicle ::set_VehicleIndex(int vIndex) { vehicleIndex = vIndex; }

void Vehicle ::INFO() {
  cout << name;
  cout << " [" << color << " " << model << ", " << slots << " seats]" << endl;
  cout << "Insurance Details:" << endl;
  cout << insuranceINFO << left;
  cout << "\t\tModel Price: $" << modelPrice << endl;
  cout << "---Index " << vehicleIndex << "---\n" << endl;
}

bool Vehicle ::search_Model(string tempModel) {
  if (tempModel == model && isHidden == false)
    return true;
  else
    return false;
}

string Vehicle ::get_VehicleINFO() {
  return color + " " + model + " - " + name + "\nLicense Plate: " + ID;
}

double Vehicle ::get_ModelPrice() { return modelPrice; }