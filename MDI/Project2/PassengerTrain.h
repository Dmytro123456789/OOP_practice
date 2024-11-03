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
    std::string getName() const {
        return name;
    }
    int getTrainNumber() const {
        return trainNumber;
    }

    std::string getTrainName() const {
        return name;
    }

    std::string getDepartureTime() const {
        return departureTime;
    }

    std::string getDepartureStation() const {
        return departureStation;
    }

    std::string getDestinationStation() const {
        return destinationStation;
    }

    std::string getRoute() const {
        return route;
    }

    double getTravelDuration() const {
        return travelDuration;
    }

    int getGeneralSeats() const {
        return generalSeats;
    }

    int getCoupeSeats() const {
        return coupeSeats;
    }

    int getReservedSeats() const {
        return reservedSeats;
    }

    int getLuxurySeats() const {
        return luxurySeats;
    }

    void somePureVirtualMethod() override;
};

#endif // PASSENGERTRAIN_H
