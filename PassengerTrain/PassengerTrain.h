#ifndef PASSENGERTRAIN_H
#define PASSENGERTRAIN_H

#include <string>
#include <iostream>

using namespace std;

class PassengerTrain {
private:
    int id;
    int trainNumber;
    string name;
    string departureTime;
    string departureStation;
    string destinationStation;
    string route;
    double travelDuration;
    int generalSeats;
    int coupeSeats;
    int reservedSeats;
    int luxurySeats;

public:
    PassengerTrain();
    PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                   const string& departureStation, const string& destinationStation,
                   const string& route, double travelDuration,
                   int generalSeats, int coupeSeats, int reservedSeats, int luxurySeats);
    PassengerTrain(const PassengerTrain& other);
    ~PassengerTrain();

    int getId() const { return id; }
    int getTrainNumber() const { return trainNumber; }
    string getName() const { return name; }
    string getDepartureTime() const { return departureTime; }
    string getDepartureStation() const { return departureStation; }
    string getDestinationStation() const { return destinationStation; }
    string getRoute() const { return route; }
    double getTravelDuration() const { return travelDuration; }
    int getGeneralSeats() const { return generalSeats; }
    int getCoupeSeats() const { return coupeSeats; }
    int getReservedSeats() const { return reservedSeats; }
    int getLuxurySeats() const { return luxurySeats; }

    void setName(const string& name) { this->name = name; }
    void setGeneralSeats(int seats) { generalSeats = seats; }

    friend istream& operator>>(istream& in, PassengerTrain& train);
    friend ostream& operator<<(ostream& out, const PassengerTrain& train);
    bool operator==(const PassengerTrain& other) const;
};

#endif // PASSENGERTRAIN_H
