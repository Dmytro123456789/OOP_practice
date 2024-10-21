#include "PassengerTrain.h"

using namespace std;

PassengerTrain::PassengerTrain()
    : id(0), trainNumber(0), name(""), departureTime(""), departureStation(""),
    destinationStation(""), route(""), travelDuration(0.0),
    generalSeats(0), coupeSeats(0), reservedSeats(0), luxurySeats(0) {}

PassengerTrain::PassengerTrain(int id, int trainNumber, const  string& name, const  string& departureTime,
                               const  string& departureStation, const  string& destinationStation,
                               const  string& route, double travelDuration,
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

int PassengerTrain::getId() const { return id; }
int PassengerTrain::getTrainNumber() const { return trainNumber; }
 string PassengerTrain::getName() const { return name; }
 string PassengerTrain::getDepartureTime() const { return departureTime; }
 string PassengerTrain::getDepartureStation() const { return departureStation; }
 string PassengerTrain::getDestinationStation() const { return destinationStation; }
 string PassengerTrain::getRoute() const { return route; }
double PassengerTrain::getTravelDuration() const { return travelDuration; }
int PassengerTrain::getGeneralSeats() const { return generalSeats; }
int PassengerTrain::getCoupeSeats() const { return coupeSeats; }
int PassengerTrain::getReservedSeats() const { return reservedSeats; }
int PassengerTrain::getLuxurySeats() const { return luxurySeats; }

void PassengerTrain::setId(int id) { this->id = id; }
void PassengerTrain::setTrainNumber(int trainNumber) { this->trainNumber = trainNumber; }
void PassengerTrain::setName(const  string& name) { this->name = name; }
void PassengerTrain::setDepartureTime(const  string& departureTime) { this->departureTime = departureTime; }
void PassengerTrain::setDepartureStation(const  string& departureStation) { this->departureStation = departureStation; }
void PassengerTrain::setDestinationStation(const  string& destinationStation) { this->destinationStation = destinationStation; }
void PassengerTrain::setRoute(const  string& route) { this->route = route; }
void PassengerTrain::setTravelDuration(double travelDuration) { this->travelDuration = travelDuration; }
void PassengerTrain::setGeneralSeats(int generalSeats) { this->generalSeats = generalSeats; }
void PassengerTrain::setCoupeSeats(int coupeSeats) { this->coupeSeats = coupeSeats; }
void PassengerTrain::setReservedSeats(int reservedSeats) { this->reservedSeats = reservedSeats; }
void PassengerTrain::setLuxurySeats(int luxurySeats) { this->luxurySeats = luxurySeats; }
