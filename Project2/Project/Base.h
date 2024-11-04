#ifndef BASE_H
#define BASE_H

#include <string>

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
    Base();
    Base(int id, const string& departureStation, const string& destinationStation,
         const string& departureTime, double travelDuration, int generalSeats);

    virtual void displayBaseInfo() const;

    virtual void somePureVirtualMethod() = 0;

    virtual ~Base() = default;
};

#endif // BASE_H
