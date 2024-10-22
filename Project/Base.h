#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

using namespace std;

class Base {
protected:
    int id;
    string departureStation;
    string destinationStation;
    string departureTime;
    double travelDuration;
    int generalSeats;

public:
    Base() : id(0), departureStation(""), destinationStation(""), departureTime(""), travelDuration(0.0), generalSeats(0) {}

    Base(int id, const string& departureStation, const string& destinationStation,
         const string& departureTime, double travelDuration, int generalSeats)
        : id(id), departureStation(departureStation), destinationStation(destinationStation),
        departureTime(departureTime), travelDuration(travelDuration), generalSeats(generalSeats) {}

    int getId() const { return id; }
    string getDepartureStation() const { return departureStation; }
    string getDestinationStation() const { return destinationStation; }
    string getDepartureTime() const { return departureTime; }
    double getTravelDuration() const { return travelDuration; }
    int getGeneralSeats() const { return generalSeats; }

    void displayBaseInfo() const {
        cout << "ID: " << id << endl;
        cout << "Пункт відправлення: " << departureStation << endl;
        cout << "Пункт призначення: " << destinationStation << endl;
        cout << "Час відправлення: " << departureTime << endl;
        cout << "Тривалість подорожі: " << travelDuration << " годин" << endl;
        cout << "Число загальних місць: " << generalSeats << endl;
    }
};

#endif // BASE_H
