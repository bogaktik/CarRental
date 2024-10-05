#include "Dataset.h"
#include <iostream>
#include <string>
#include <time.h>
/*
This file include files Insurance.h, Vehicle.h, Driver.h
Dataset includes insuranceLists, vehiclesGarage, driverLists
*/
#include "Booking.h"
#include "Customer.h"

using namespace std;

int i = 0,              // Set current index of each object in lists
    countFound = 0;     // Increase if any object is found
char testChar;          // Get random char inputs
string testSTR;         // Get random string inputs

int main() {
  // Setup current index of each object in vehiclesGarage
  for (i = 0; i < vehiclesGarage_size; i++)
    vehiclesGarage[i].set_VehicleIndex(i);
  
  // ---Proccess to Book Vehicle---
  
  // Step 1: Search Vehicle
  // Scan vehicles in vehiclesGarage when testSTR is added inside function search_Model(string tempModel) 
  // If countFound <= 0 => Redo entire do-while loop 
  // If countFound > 0  => Display any vehicles whose model match testSTR
  do 
  {
    cout << "Which vehicle do you prefer?\nModel: ";
    cin >> testSTR;
    cout << endl;
    
    for (i = vehiclesGarage_size - 1; i >= 0; i--) {
      countFound = countFound + vehiclesGarage[i].search_Model(testSTR);
      if (vehiclesGarage[i].search_Model(testSTR) == true)
        vehiclesGarage[i].INFO();
    }
    
    if (countFound <= 0)
      cout << "\"" << testSTR << "\" is not available!\n" << endl;
  } while (countFound <= 0);
  
  // Step 2: Select Vehicle based on index
  string vehicleINFO;
  double myPayout;
  
  // Using i to select vehicle index
  cout << "Select Your Favorite Vehicle\nIndex: ";
  cin >> i;
  
  // Extract INFO of selected vehicle
  vehicleINFO = vehiclesGarage[i].get_VehicleINFO();
  
  // Extract model price of selected vehicle
  myPayout = vehiclesGarage[i].get_ModelPrice();
  cout << endl;
  
  // Step 3: Assign Random Driver to Vehicle
  // Only if customers request. Else, move to step 4
  string driverINFO;
  cout << "Do you wish to hire a personal driver?\nY/N: ";
  cin >> testChar;
  
  if (tolower(testChar) == 'y') 
  {
    // Using i to select driver
    // Scan if chosen driver Info is valid
    // If countFound != 1 => Redo entire do-while loop
    // If countFound == 1 => Display chosen driver
    do {
      // Value of i will be different in each execution
      srand((int)time(0));
      i = rand() % driverLists_size;
      countFound = driverLists[i].search_DriverINFO();
      
      if (countFound == 1)
        driverLists[i].profileINFO();
    } while (countFound != 1);
    
    // Extract driver info
    driverINFO = driverLists[i].get_profileINFO();
  }
  
  // Step 4: Ask Customer Contact Info
  string myINFO;
  Customer newCustomer;
  // Proccess to fill customer info (Input Syntax Only)
  // If proccess fails     => Redo entire proccess
  // If proccess successes => Display customer info
  // Expect users to provide exact name and phone number to continue step 6
  
  newCustomer.add_CustomerINFO();
  // Extract customer info
  myINFO = newCustomer.get_profileINFO();
  
  // Step 5: Ask Pickup Date + Return Date
  Booking newBooking;
  // If proccess fails     => Redo entire proccess
  // If proccess successes => calculate and update bill
  
  newBooking.set_rentDays();
  myPayout = newBooking.calculate_Bill(myPayout);
  
  // Step 6: Ask Pickup Location + Return Location
  // Expect users to provide exact location from Google Map to finish booking proccess
  newBooking.set_Location();
  
  // Step 7: Collect Data and Print Results
  newBooking.INFO();
  newBooking.print_BookingINFO(myINFO, vehicleINFO, driverINFO);
  
  return 0;
}