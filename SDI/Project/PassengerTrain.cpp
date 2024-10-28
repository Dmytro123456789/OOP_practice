#include "PassengerTrain.h"


using namespace std;

PassengerTrain::PassengerTrain() : id(0), trainNumber(0), travelDuration(0.0),
    generalSeats(0), coupeSeats(0), reservedSeats(0), luxurySeats(0) {}

PassengerTrain::PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                               const string& departureStation, const string& destinationStation,
                               const string& route, double travelDuration, int generalSeats,
                               int coupeSeats, int reservedSeats, int luxurySeats)
    : id(id), trainNumber(trainNumber), name(name), departureTime(departureTime),
    departureStation(departureStation), destinationStation(destinationStation), route(route),
    travelDuration(travelDuration), generalSeats(generalSeats), coupeSeats(coupeSeats),
    reservedSeats(reservedSeats), luxurySeats(luxurySeats) {}

PassengerTrain::PassengerTrain(const PassengerTrain& other) : id(other.id), trainNumber(other.trainNumber),
    name(other.name), departureTime(other.departureTime),
    departureStation(other.departureStation),
    destinationStation(other.destinationStation),
    route(other.route), travelDuration(other.travelDuration),
    generalSeats(other.generalSeats), coupeSeats(other.coupeSeats),
    reservedSeats(other.reservedSeats), luxurySeats(other.luxurySeats) {}

PassengerTrain::~PassengerTrain() {}

QString PassengerTrain::toString() {
    return QString("Номер поїзда: %1\n"
                   "Назва: %2\n"
                   "Час відправки: %3\n"
                   "Станція відправлення: %4\n"
                   "Станція призначення: %5\n"
                   "Маршрут: %6\n"
                   "Тривалість подорожі: %7 год.\n"
                   "Загальні місця: %8\n"
                   "Купе місця: %9\n"
                   "Плацкартні місця: %10\n"
                   "Люкс місця: %11")
        .arg(trainNumber)
        .arg(QString::fromStdString(name))
        .arg(QString::fromStdString(departureTime))
        .arg(QString::fromStdString(departureStation))
        .arg(QString::fromStdString(destinationStation))
        .arg(QString::fromStdString(route))
        .arg(travelDuration)
        .arg(generalSeats)
        .arg(coupeSeats)
        .arg(reservedSeats)
        .arg(luxurySeats);
}


