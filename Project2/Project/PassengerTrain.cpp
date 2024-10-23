#include "PassengerTrain.h"

PassengerTrain::PassengerTrain() : Base(), trainNumber(0), name(""), route(""), coupeSeats(0), reservedSeats(0), luxurySeats(0) {}

PassengerTrain::PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                               const string& departureStation, const string& destinationStation,
                               const string& route, double travelDuration,
                               int generalSeats, int coupeSeats, int reservedSeats, int luxurySeats)
    : Base(id, departureStation, destinationStation, departureTime, travelDuration, generalSeats),
    trainNumber(trainNumber), name(name), route(route),
    coupeSeats(coupeSeats), reservedSeats(reservedSeats), luxurySeats(luxurySeats) {}

void PassengerTrain::displayInfo() const {
    displayBaseInfo();
    cout << "Номер поїзда: " << trainNumber << endl;
    cout << "Назва поїзда: " << name << endl;
    cout << "Маршрут: " << route << endl;
    cout << "Місця в купе: " << coupeSeats << endl;
    cout << "Зарезервовані місця: " << reservedSeats << endl;
    cout << "Люкс місця: " << luxurySeats << endl;
}

istream& operator>>(istream& in, PassengerTrain& train) {
    cout << "Введіть ID: ";
    in >> train.id;
    cout << "Введіть номер поїзда: ";
    in >> train.trainNumber;
    cout << "Введіть назву поїзда: ";
    in >> train.name;
    cout << "Введіть пункт відправлення: ";
    in >> train.departureStation;
    cout << "Введіть пункт призначення: ";
    in >> train.destinationStation;
    cout << "Введіть час відправлення: ";
    in >> train.departureTime;
    cout << "Введіть тривалість подорожі: ";
    in >> train.travelDuration;
    cout << "Введіть кількість загальних місць: ";
    in >> train.generalSeats;
    cout << "Введіть кількість місць в купе: ";
    in >> train.coupeSeats;
    cout << "Введіть кількість зарезервованих місць: ";
    in >> train.reservedSeats;
    cout << "Введіть кількість люкс місць: ";
    in >> train.luxurySeats;
    return in;
}

ostream& operator<<(ostream& out, const PassengerTrain& train) {
    train.displayInfo();
    return out;
}

bool PassengerTrain::operator==(const PassengerTrain& other) const {
    return id == other.id && trainNumber == other.trainNumber &&
           name == other.name && departureStation == other.departureStation &&
           destinationStation == other.destinationStation &&
           route == other.route && travelDuration == other.travelDuration &&
           generalSeats == other.generalSeats && coupeSeats == other.coupeSeats &&
           reservedSeats == other.reservedSeats && luxurySeats == other.luxurySeats;
}
