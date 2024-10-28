#ifndef PASSENGERTRAIN_H
#define PASSENGERTRAIN_H

#include <string>
#include <QString>

using namespace std;

class PassengerTrain {
public:
    PassengerTrain();
    PassengerTrain(int id, int trainNumber, const string& name, const string& departureTime,
                   const string& departureStation, const string& destinationStation,
                   const string& route, double travelDuration, int generalSeats,
                   int coupeSeats, int reservedSeats, int luxurySeats);
    PassengerTrain(const PassengerTrain& other);
    ~PassengerTrain();

    int getId() const;
    int getTrainNumber() const;
    string getName() const;
    string getDepartureTime() const;
    string getDepartureStation() const;
    string getDestinationStation() const;
    string getRoute() const;
    double getTravelDuration() const;
    int getGeneralSeats() const;
    int getCoupeSeats() const;
    int getReservedSeats() const;
    int getLuxurySeats() const;
    QString toString();

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
};



#endif // PASSENGERTRAIN_H
