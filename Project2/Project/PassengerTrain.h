#ifndef PASSENGERTRAIN_H
#define PASSENGERTRAIN_H

#include <string>
#include <iostream>
#include "Base.h"

using namespace std;

class PassengerTrain : public Base {
private:
    int trainNumber;
    string name;
    string route;
    int coupeSeats;
    int reservedSeats;
    int luxurySeats;

public:
    PassengerTrain();
    PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                   const string& departureStation, const string& destinationStation,
                   const string& route, double travelDuration,
                   int generalSeats, int coupeSeats, int reservedSeats, int luxurySeats);

    void displayInfo() const;

    friend istream& operator>>(istream& in, PassengerTrain& train);
    friend ostream& operator<<(ostream& out, const PassengerTrain& train);
    bool operator==(const PassengerTrain& other) const;

    void somePureVirtualMethod() override;
};

#endif // PASSENGERTRAIN_H
