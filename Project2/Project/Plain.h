#ifndef PLAIN_H
#define PLAIN_H

#include <string>
#include <iostream>

using namespace std;

class Plain {
protected:
    int id;
    string departurePoint;
    string destinationPoint;
    string flightNumber;
    string departureTime;
    double travelDuration;
    int numberOfSeats;

public:
    Plain();
    Plain(int id, const string& departurePoint, const string& destinationPoint,
          const string& flightNumber, const string& departureTime,
          double travelDuration, int numberOfSeats);

    void displayInfo() const;

    friend istream& operator>>(istream& in, Plain& plane);
    friend ostream& operator<<(ostream& out, const Plain& plane);
    bool operator==(const Plain& other) const;
};

#endif // PLAIN_H
