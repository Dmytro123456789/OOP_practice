#include <iostream>
#include <string>
#include "Base.h"

using namespace std;

class Plain : public Base {
private:
    string flightNumber;

public:
    Plain() : Base(), flightNumber("") {}

    Plain(int id, const string& departureStation, const string& destinationStation,
          const string& flightNumber, const string& departureTime,
          double travelDuration, int generalSeats)
        : Base(id, departureStation, destinationStation, departureTime, travelDuration, generalSeats),
        flightNumber(flightNumber) {}

    void displayInfo() const {
        displayBaseInfo();
        cout << "Номер рейсу: " << flightNumber << endl;
    }
};

int main() {
    Plain flight(1, "Київ", "Лондон", "PS123", "15:30", 3, 180);
    flight.displayInfo();
    return 0;
}
