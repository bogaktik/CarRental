#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <fstream>
#include "Booking.h"

using namespace std;
/*
Author: Tran Hong Nghiep
Contributor: Le Kim Bang, Nguyen Quang Minh
---
Class "Booking" -  Status: Working
This file contains the definitions of the functions to implement the operations of the class Booking.
*/
// Setup Current time in second based on computer system 
time_t currentTime = time(0);

Booking :: Booking() {
  // Default time of pickUpDate
  pickUpDate = currentTime;
  // Default time of returnDate
  returnDate = pickUpDate; 
  // Default value of pickUpLocation
  pickUpLocation = "";
  // Default value of returnLocaion
  returnLocation = "";
  // Default value of bill
  bill = 0;
}

/*
2 Exclusive functions to test valid date
Reference:
https://www.geeksforgeeks.org/program-check-date-valid-not/
*/

// Sub function to check leap year
bool isLeapYear(int y){
  /*
  Default Defintion of Leap Year:
    If 2 ending digits of leap year is not 00
    => Divisible by 4
    If 2 ending digits of leap year is 00
    => Divisible by 400 but not 100
    Other cases will return false
  */
  if ( ( (y % 4 == 0) && (y % 100 != 0) ) || (y % 400 == 0) )
    return true;
  
  else return false;
}

// Sub function to check valid date
bool isValidDate(int m, int d, int y){
  // Month must be at range 1 to 12
  if (m < 1 || m > 12)
    return false;
  
  // Day must be at range 1 to 31
  if (d < 1 || d > 31)
    return false;
  
  // If month is 2, check if selected year is leap year
  if (m == 2) 
  {
    // Leap Year must be 29 days
    if (isLeapYear(y))
      return (d <= 29);    // Return false if d > 29
    // None Leap Year must be 28 days
    else return (d <= 28); // Return false if d > 28
  }
  
  // Month 4, 6, 9, 11 must be 30 days
  if (m == 4 || m == 6 || m == 9 || m == 11)
    return (d <= 30);      // Return false if d > 30
  return true;
}

time_t Booking :: inputDate() {
  time_t tempTime;
  int month, day, year, hour;
  bool checkDate;
  
  do {
    do {
      cout << "Date [MM DD YYYY]: ";
      cin >> month >> day >> year;
      
      checkDate = isValidDate(month, day, year);
      if (checkDate == false)
        cout << "Input date is invalid!\n" << endl;
    } while (checkDate == false);
    
    do {
      cout << "Hour [Range: 0 - 23]: ";
      cin >> hour;
      
      if (hour < 0 || hour > 23)
        cout << "Hour must be at range from 0 to 23!\n" << endl;
    } while(hour < 0 || hour > 23);
    
    tm tm{};
    // tm_mday  (Range: 0 - 31)
    tm.tm_mday = day;
    // tm_month (Range: 0 - 11)
    tm.tm_mon = month - 1;
    // tm_year  (Range: 1900 - Current Time)
    tm.tm_year = year - 1900;
    // tm_hour  (Range: 0 - 23)
    tm.tm_hour = hour;
    
    tempTime = mktime(&tm);
    if (tempTime < currentTime)
      cout<<"Error: Selected date is before "<<ctime(&currentTime)<<endl;
  } while(tempTime < currentTime);
  
  return tempTime;
}

void Booking :: set_rentDays() {
  cout << "Pick your date to pick up vehicle" << endl;
  pickUpDate = inputDate();
  
  cout << "\nPick your date to return vehicle" << endl;
  do {
    returnDate = inputDate();
    if (returnDate <= pickUpDate)
      cout << "Input date must be after "<< ctime(&pickUpDate) << endl;
  } while(returnDate <= pickUpDate);
  
  /*
  Calculate difference in seconds between 2 dates
  Reference: 
  https://www.programiz.com/cpp-programming/library-function/ctime/difftime
  */
  double seconds = difftime(returnDate, pickUpDate);
  
  /*
  Time Conversion:
  60 seconds = 1 minutes
  60 minutes = 1 hours
  24 hours = 1 days
  => days = hours / 24
     days = minutes / (60 * 24)
     days = seconds / (60 * 60 * 24)
  */
  rentDays = static_cast<int>(seconds / (60 * 60 * 24));
  
  if (rentDays <= 0)
    rentDays = 1;
  cout<<endl;
}

// Sub function to add location based on city and address
string addLocation() {
  // cin>>ws ensure to extract white spaces from inputs
  string city, address, location;
  
  cout << "City: ";
  getline(cin>>ws, city);
  cout << "Address: ";
  
  getline(cin>>ws, address);
  location = address + ", " + city;
  
  return location;
}

void Booking :: set_Location() {
  cout << "Add Pick-Up and Return Location" << endl;
  cout << "Rent Days: " << rentDays << endl;
  
  cout << "Pick-Up Location: " << endl;
  pickUpLocation = addLocation();
  
  cout << "\nReturn Location: " << endl;
  returnLocation = addLocation();
}

double Booking :: calculate_Bill(double tempVehiclePrice) {
  bill = tempVehiclePrice * rentDays;
  
  return bill;
}

void Booking :: INFO() {
  cout << "\nYour booking has been completed!" << endl;
  
  cout << "Pick Up at " << pickUpLocation << endl;
  cout << "on " << ctime(&pickUpDate);
  
  cout << "Return to " << returnLocation << endl;
  cout << "on " << ctime(&returnDate);
  
  cout << "Payout: $" << fixed << setprecision(2) << bill << endl;
}

void Booking :: print_BookingINFO(string tempCustomer, string tempVehicle, string tempDriver) {
  /*
  Reference of function strftime:
  https://www.programiz.com/cpp-programming/library-function/ctime/strftime
  */
  tm *currentTime_local = localtime(&currentTime);
  
  /*
  Pattern of currentTimeINFO
  %b => Short word of month
  %d => Day in month with 2 digits
  %Y => Year with 4 digits
  Example: Sep272023
  Size of char:  10 characters (Include "\0")
  */
  
  char currentTimeINFO[10];
  strftime(currentTimeINFO, 10, "%b%d%Y", currentTime_local);
  
  /*
  Reference of fstream library:
  https://www.w3schools.com/cpp/cpp_files.asp
  */
  string fileName = "BK_" + string(currentTimeINFO) + ".txt";
  ofstream bookingFile;
  bookingFile.open(fileName);
  
  bookingFile << "Customer: " << tempCustomer << endl;
  bookingFile << "Rent Days: " << rentDays << endl;
  bookingFile << "Payout: $" << setprecision(5) << bill << endl;
  bookingFile << "\nPick Up at:" << endl;
  bookingFile << pickUpLocation << "\non " << ctime(&pickUpDate);
  bookingFile << "Return to:" << endl;
  bookingFile << returnLocation << "\non " << ctime(&returnDate);
  bookingFile << "---" << endl;
  
  if (tempDriver.length() > 0)
    bookingFile << "Driver: " << tempDriver << endl;
  bookingFile << "Vehicle:\n" << tempVehicle;
  
  bookingFile.close();
}