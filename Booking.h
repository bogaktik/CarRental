#include <string>
#include <ctime>
#include "objectTemplate.h"

using namespace std;

/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Booking" - Status: Complete
This class is inherited from Class "objectTemplate"
This class specifies these members below to define booking details
*/
class Booking {
/*
Delivered variables from objectTemplate
  # string ID           (Plate Number of Vehicle)
  # string name         (Full name of Vehicle)
  # void INFO()         (Details of Booking)
*/

private:
  time_t pickUpDate,
    returnDate;
  string pickUpLocation,
    returnLocation;
  double bill;
  int rentDays;

public:
  Booking();
  /*
  Main constructor of Booking
  Default definition:
  When customers have not picked exact date
  1. Value of pickUpDate and returnDate equals to current time of computer system.
  2. Value of pickUpLocation and returnLocaion is empty
  3. bill equals to 0
  */
  
  time_t inputDate();                    
  /*
  Function to input and return date
  Default Definition:
  The proccess must be redo when
  1. Selected date is out of calendar
  2. Selected date is before the current date
  Note: 
  To understand how to setup date, check out file Booking.cpp
  */
  
  void set_rentDays();
  /*
  Function to set value of rentDays
  Default Definition:
  1. Value of pickUpDate will be setup using inputDate()
  2. Value of returnDate will be setup using inputDate()
  3. If returnDate is before pickUpDate, users must pick returnDate again
  4. rentDays = returnDate - pickUpDate
     If rentDays ~= 0 => rentDays = 1;
  */
  
  void set_Location();
  // Function to set the pick-up and return location
  
  double calculate_Bill(double tempVehiclePrice);
  /*
  Function to calculate bill based on Vehicle Price and rentDays
  bill = Vehicle Price * rentDays
  */
  
  void INFO();
  /*
  Function to display booking details 
  This function only display value of members in class Booking
  */
  
  void print_BookingINFO(string tempCustomer, string tempVehicle, string tempDriver);
  /*
  Function to create .txt and write Booking Info
  Name Format: BK_MMMDDYYYY.txt
  Example: BK_Sep272023.txt
  
  File Format:
  Customer: [Your Name, Your Phone Number]
  Rent Days: [Number of Rent Days]
  Payout: [Your Bill]
  ---
  Driver: [Driver Name, Driver Phone Number]
  Vehicle:
  [Vehicle Name with Color and Brand]
  License Plate: [Vehicle ID]
  */
};