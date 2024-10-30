#ifndef PLAIN_H
#define PLAIN_H

#include "Base.h"
#include <string>
#include <iostream>

class Plain : public Base {
private:
    std::string flightNumber;

public:
    Plain();
    Plain(int id, const std::string& departureStation, const std::string& destinationStation,
          const std::string& flightNumber, const std::string& departureTime,
          double travelDuration, int generalSeats);

    void displayInfo() const ;
    void somePureVirtualMethod() override;
    std::string getDeparturePoint() const {
        return departureStation;
    }

    std::string getDestinationPoint() const {
        return destinationStation;
    }

    std::string getFlightNumber() const {
        return flightNumber;
    }

    std::string getDepartureTime() const {
        return departureTime;
    }

    double getTravelDuration() const {
        return travelDuration;
    }

    int getGeneralSeats() const {
        return generalSeats;
    }


    friend std::istream& operator>>(std::istream& in, Plain& plane);


};

#endif // PLAIN_H
