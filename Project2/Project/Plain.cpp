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

void Plain::showInfo() const {
    displayBaseInfo(); // Виведення інформації базового класу
    // Додайте виведення специфічної інформації для Plain
    cout << "Додаткові дані для літака" << endl;
}

std::ostream& operator<<(std::ostream& os, const Plain& plane) {
    // Виведіть специфічну інформацію про літак
    os << "Інформація про літак:\n";
    os << "ID: " << plane.id << "\n";
    os << "Пункт відправлення: " << plane.departureStation << "\n";
    os << "Пункт призначення: " << plane.destinationStation << "\n";
    os << "Час відправлення: " << plane.departureTime << "\n";
    os << "Тривалість подорожі: " << plane.travelDuration << " годин\n";
    os << "Число загальних місць: " << plane.generalSeats << "\n";
    return os;
}
