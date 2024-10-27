#include "Base.h"
#include <iostream>

Base::Base() : id(0), departureStation(""), destinationStation(""), departureTime(""), travelDuration(0.0), generalSeats(0) {}

Base::Base(int id, const string& departureStation, const string& destinationStation,
           const string& departureTime, double travelDuration, int generalSeats)
    : id(id), departureStation(departureStation), destinationStation(destinationStation),
    departureTime(departureTime), travelDuration(travelDuration), generalSeats(generalSeats) {}

void Base::displayBaseInfo() const {
    cout << "ID: " << id << endl;
    cout << "Пункт відправлення: " << departureStation << endl;
    cout << "Пункт призначення: " << destinationStation << endl;
    cout << "Час відправлення: " << departureTime << endl;
    cout << "Тривалість подорожі: " << travelDuration << " годин" << endl;
    cout << "Число загальних місць: " << generalSeats << endl;
}
