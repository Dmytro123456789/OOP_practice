#ifndef BASE_H
#define BASE_H

#include <string>

using namespace std;

class Base {
protected:
    int id;
    string departureStation;
    string destinationStation;
    string departureTime;
    double travelDuration;
    int generalSeats;

public:
    Base();
    Base(int id, const string& departureStation, const string& destinationStation,
         const string& departureTime, double travelDuration, int generalSeats);

    void displayBaseInfo() const;

    // Геттери
    int getId() const { return id; }
    const string& getDepartureStation() const { return departureStation; }
    const string& getDestinationStation() const { return destinationStation; }
    const string& getDepartureTime() const { return departureTime; }
    double getTravelDuration() const { return travelDuration; }
    int getGeneralSeats() const { return generalSeats; }

    // Сеттери
    void setId(int id) { this->id = id; }
    void setDepartureStation(const string& station) { departureStation = station; }
    void setDestinationStation(const string& station) { destinationStation = station; }
    void setDepartureTime(const string& time) { departureTime = time; }
    void setTravelDuration(double duration) { travelDuration = duration; }
    void setGeneralSeats(int seats) { generalSeats = seats; }
};

#endif // BASE_H
