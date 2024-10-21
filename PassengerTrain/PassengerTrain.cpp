#include "PassengerTrain.h"
using namespace std;

PassengerTrain::PassengerTrain()
    : id(0), trainNumber(0), name(""), departureTime(""), departureStation(""),
    destinationStation(""), route(""), travelDuration(0.0),
    generalSeats(0), coupeSeats(0), reservedSeats(0), luxurySeats(0) {}

PassengerTrain::PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                               const string& departureStation, const string& destinationStation,
                               const string& route, double travelDuration,
                               int generalSeats, int coupeSeats, int reservedSeats, int luxurySeats)
    : id(id), trainNumber(trainNumber), name(name), departureTime(departureTime),
    departureStation(departureStation), destinationStation(destinationStation),
    route(route), travelDuration(travelDuration), generalSeats(generalSeats),
    coupeSeats(coupeSeats), reservedSeats(reservedSeats), luxurySeats(luxurySeats) {}

PassengerTrain::PassengerTrain(const PassengerTrain& other)
    : id(other.id), trainNumber(other.trainNumber), name(other.name),
    departureTime(other.departureTime), departureStation(other.departureStation),
    destinationStation(other.destinationStation), route(other.route),
    travelDuration(other.travelDuration), generalSeats(other.generalSeats),
    coupeSeats(other.coupeSeats), reservedSeats(other.reservedSeats),
    luxurySeats(other.luxurySeats) {}

PassengerTrain::~PassengerTrain() {}

istream& operator>>(istream& in, PassengerTrain& train) {
    cout << "Введіть ID поїзда: ";
    in >> train.id;
    cout << "Введіть номер поїзда: ";
    in >> train.trainNumber;
    in.ignore();
    cout << "Введіть назву поїзда: ";
    getline(in, train.name);
    cout << "Введіть час відправки: ";
    getline(in, train.departureTime);
    cout << "Введіть станцію відправлення: ";
    getline(in, train.departureStation);
    cout << "Введіть станцію призначення: ";
    getline(in, train.destinationStation);
    cout << "Введіть маршрут: ";
    getline(in, train.route);
    cout << "Введіть тривалість подорожі (у годинах): ";
    in >> train.travelDuration;
    cout << "Введіть кількість загальних місць: ";
    in >> train.generalSeats;
    cout << "Введіть кількість місць у купе: ";
    in >> train.coupeSeats;
    cout << "Введіть кількість плацкартних місць: ";
    in >> train.reservedSeats;
    cout << "Введіть кількість люксових місць: ";
    in >> train.luxurySeats;

    return in;
}

ostream& operator<<(ostream& out, const PassengerTrain& train) {
    out << "ID поїзда: " << train.id << endl;
    out << "Номер поїзда: " << train.trainNumber << endl;
    out << "Назва поїзда: " << train.name << endl;
    out << "Час відправки: " << train.departureTime << endl;
    out << "Станція відправлення: " << train.departureStation << endl;
    out << "Станція призначення: " << train.destinationStation << endl;
    out << "Маршрут: " << train.route << endl;
    out << "Тривалість подорожі: " << train.travelDuration << " годин" << endl;
    out << "Загальні місця: " << train.generalSeats << endl;
    out << "Місця у купе: " << train.coupeSeats << endl;
    out << "Плацкартні місця: " << train.reservedSeats << endl;
    out << "Люкс місця: " << train.luxurySeats << endl;

    return out;
}

bool PassengerTrain::operator==(const PassengerTrain& other) const {
    return (id == other.id &&
            trainNumber == other.trainNumber &&
            name == other.name &&
            departureTime == other.departureTime &&
            departureStation == other.departureStation &&
            destinationStation == other.destinationStation &&
            route == other.route &&
            travelDuration == other.travelDuration &&
            generalSeats == other.generalSeats &&
            coupeSeats == other.coupeSeats &&
            reservedSeats == other.reservedSeats &&
            luxurySeats == other.luxurySeats);
}
