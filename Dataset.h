#ifndef Dataset_H
#define Dataset_H

#include "Driver.h"
#include "Insurance.h"
#include "Vehicle.h"
#include <array>
#include <string>

using namespace std;

// Database of insuranceLists
// Template: Insurance(string iID, string cpName, bool   includeCollision, bool
// includeInjury)
Insurance insuranceLists[] = {
    // Source:
    // https://www.forbes.com/advisor/car-insurance/best-car-insurance-companies/
    Insurance("US123", "USAA", true, false),
    Insurance("AF135", "AmericanFamily", false, true),
    Insurance("AO365", "AutoOwners", false, false),
    Insurance("AO640", "AutoOwners", true, false),
    Insurance("NW987", "NationWide", false, false),
    Insurance("GE012", "Geico", true, true),
};

// Database of vehiclesGarage
// Template: Vehicle(string vID, string vModel, string vBrand, string vSeries,
// string vColor, string vInsurance)
Vehicle vehiclesGarage[] = {
    Vehicle("ADC2023", "Sedan", "Ford", "Mustang", "Black",
            insuranceLists[0].get_Description()),
    Vehicle("SFE2000", "SUV", "Ford", "Everest", "White",
            insuranceLists[2].get_Description()),
    Vehicle("PCC2000", "Pickup", "Chevrolet", "Colorado", "White",
            insuranceLists[4].get_Description()),
    Vehicle("HBZ2000", "Hatchback", "Toyota", "Corrola", "White", ""),
    Vehicle("CBZ2000", "Convertible", "BMW", "Z4", "Grey",
            insuranceLists[1].get_Description()),
    Vehicle("MFT2000", "Minibus", "Ford", "Tourneo", "White",
            insuranceLists[3].get_Description()),
    Vehicle("UCR9495", "Minivan", "Toyota", "Sienna", "Grey",
            insuranceLists[5].get_Description()),
    Vehicle("JBP4892", "Crossover", "Cadillac", "XT5", "Black", ""),
    Vehicle("DNF9600", "SUV", "Chevrolet", "Suburban", "Silver",
            insuranceLists[1].get_Description()),
    Vehicle("ZMW8710", "Crossover", "Hyundai", "Santa Fe", "Red",
            insuranceLists[0].get_Description()),
    Vehicle("BAS3369", "Sedan", "Toyota", "Camry", "White", insuranceLists[1].get_Description()),
    Vehicle("EOW3635", "Sedan", "Chevrolet", "Impala", "White",
            insuranceLists[1].get_Description()),
    Vehicle("WHA7168", "Sedan", "BMW", "5-Series", "Black", ""),
    Vehicle("LGT0243", "Crossover", "BMW", "X5", "Grey",
            insuranceLists[2].get_Description()),
    Vehicle("PFF2000", "Pickup", "Ford", "F150", "Black",
            insuranceLists[4].get_Description()),
    Vehicle("PNT2000", "Pickup", "Nissan", "Titan", "Black",
            insuranceLists[5].get_Description()),
    Vehicle("AGE3703", "Minivan", "Kia", "Sedona", "Blue",
            insuranceLists[3].get_Description()),
    Vehicle("ZCF1709", "Hatchback", "Mini", "Cooper", "Green",
            insuranceLists[5].get_Description()),
    Vehicle("NCX5021", "Hatchback", "Mini", "Clubman", "Orange",
            insuranceLists[2].get_Description()),
};

int vehiclesGarage_size = end(vehiclesGarage) - begin(vehiclesGarage);

// Database of driverLists
// Template: Driver(string dNum, string dFName, string dLName)
// Phone Number Generator: https://codebeautify.org/random-  phone-number#
// Full Name Generator: https://www.name-generator.org.uk/
Driver driverLists[] = {
    Driver("2063428631", "Huffman", "Cain"),
    Driver("7175501675", "Baldwin", "Russell"),
    Driver("2487620356", "Buck", "Alec"),
    Driver("0123456789", "Fleming", "Mary"),
    Driver("0123456789", "Durham", "Helen"),
    Driver("0123456789", "Weiss", "Frances"),
};

int driverLists_size = end(driverLists) - begin(driverLists);

#endif