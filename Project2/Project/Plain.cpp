#include "Plain.h"
#include <iostream>

Plain::Plain() : Base(), flightNumber("") {}

Plain::Plain(int id, const string& departureStation, const string& destinationStation,
             const string& flightNumber, const string& departureTime,
             double travelDuration, int generalSeats)
    : Base(id, departureStation, destinationStation, departureTime, travelDuration, generalSeats),
    flightNumber(flightNumber) {}

void Plain::displayInfo() const {
    displayBaseInfo();
    cout << "Номер рейсу: " << flightNumber << endl;
}

void Plain::somePureVirtualMethod() {
    cout << "Реалізація чисто віртуального методу в класі Plain." << endl;
}
