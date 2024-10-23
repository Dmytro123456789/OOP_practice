#ifndef PLAIN_H
#define PLAIN_H

#include <string>
#include "Base.h"

using namespace std;

class Plain : public Base {
private:
    string flightNumber;

public:
    Plain();
    Plain(int id, const string& departureStation, const string& destinationStation,
          const string& flightNumber, const string& departureTime,
          double travelDuration, int generalSeats);

    void displayInfo() const;

    void somePureVirtualMethod() override; // Реалізація чисто віртуального методу
};

#endif // PLAIN_H
