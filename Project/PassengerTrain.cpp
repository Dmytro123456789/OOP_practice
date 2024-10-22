#include <iostream>
#include <string>
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
    PassengerTrain() : Base(), trainNumber(0), name(""), route(""), coupeSeats(0), reservedSeats(0), luxurySeats(0) {}

    PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                   const string& departureStation, const string& destinationStation,
                   const string& route, double travelDuration,
                   int generalSeats, int coupeSeats, int reservedSeats, int luxurySeats)
        : Base(id, departureStation, destinationStation, departureTime, travelDuration, generalSeats),
        trainNumber(trainNumber), name(name), route(route),
        coupeSeats(coupeSeats), reservedSeats(reservedSeats), luxurySeats(luxurySeats) {}

    void displayInfo() const {
        displayBaseInfo();
        cout << "Номер поїзда: " << trainNumber << endl;
        cout << "Назва поїзда: " << name << endl;
        cout << "Маршрут: " << route << endl;
        cout << "Місця в купе: " << coupeSeats << endl;
        cout << "Зарезервовані місця: " << reservedSeats << endl;
        cout << "Люкс місця: " << luxurySeats << endl;
    }
};

int main() {
    PassengerTrain train(1, 120, "Стріла", "08:00", "Київ", "Львів", "Київ-Львів", 5, 300, 100, 50, 20);
    train.displayInfo();
    return 0;
}
