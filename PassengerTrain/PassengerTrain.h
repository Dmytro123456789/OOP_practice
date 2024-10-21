
#ifndef PASSENGERTRAIN_H
#define PASSENGERTRAIN_H

#include <string>

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

    void setId(int id);
    void setTrainNumber(int trainNumber);
    void setName(const string& name);
    void setDepartureTime(const string& departureTime);
    void setDepartureStation(const string& departureStation);
    void setDestinationStation(const string& destinationStation);
    void setRoute(const string& route);
    void setTravelDuration(double travelDuration);
    void setGeneralSeats(int generalSeats);
    void setCoupeSeats(int coupeSeats);
    void setReservedSeats(int reservedSeats);
    void setLuxurySeats(int luxurySeats);
};

#endif
