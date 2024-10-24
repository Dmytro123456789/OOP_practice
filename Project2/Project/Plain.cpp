#include "Plain.h"
#include <iostream>

Plain::Plain() : Base(), flightNumber("") {}

Plain::Plain(int id, const std::string& departureStation, const std::string& destinationStation,
             const std::string& flightNumber, const std::string& departureTime,
             double travelDuration, int generalSeats)
    : Base(id, departureStation, destinationStation, departureTime, travelDuration, generalSeats),
    flightNumber(flightNumber) {}

void Plain::displayInfo() const {
    displayBaseInfo();
    std::cout << "Номер рейсу: " << flightNumber << std::endl;
}

void Plain::somePureVirtualMethod() {
    std::cout << "Реалізація чисто віртуального методу в класі Plain." << std::endl;
}

std::istream& operator>>(std::istream& in, Plain& plane) {
    std::cout << "Введіть ID: ";
    in >> plane.id;
    std::cout << "Введіть пункт відправлення: ";
    in >> plane.departureStation;
    std::cout << "Введіть пункт призначення: ";
    in >> plane.destinationStation;
    std::cout << "Введіть номер рейсу: ";
    in >> plane.flightNumber;
    std::cout << "Введіть час відправлення: ";
    in >> plane.departureTime;
    std::cout << "Введіть тривалість подорожі: ";
    in >> plane.travelDuration;
    std::cout << "Введіть кількість загальних місць: ";
    in >> plane.generalSeats;
    return in;
}
