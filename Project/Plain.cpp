#include "Plain.h"

Plain::Plain() : id(0), departurePoint(""), destinationPoint(""),
    flightNumber(""), departureTime(""), travelDuration(0.0), numberOfSeats(0) {}

Plain::Plain(int id, const string& departurePoint, const string& destinationPoint,
             const string& flightNumber, const string& departureTime,
             double travelDuration, int numberOfSeats)
    : id(id), departurePoint(departurePoint), destinationPoint(destinationPoint),
    flightNumber(flightNumber), departureTime(departureTime),
    travelDuration(travelDuration), numberOfSeats(numberOfSeats) {}

void Plain::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Пункт відправлення: " << departurePoint << endl;
    cout << "Пункт призначення: " << destinationPoint << endl;
    cout << "Номер рейсу: " << flightNumber << endl;
    cout << "Час відправлення: " << departureTime << endl;
    cout << "Тривалість подорожі: " << travelDuration << " годин" << endl;
    cout << "Кількість місць: " << numberOfSeats << endl;
}

istream& operator>>(istream& in, Plain& plane) {
    cout << "Введіть ID: ";
    in >> plane.id;
    cout << "Введіть пункт відправлення: ";
    in >> plane.departurePoint;
    cout << "Введіть пункт призначення: ";
    in >> plane.destinationPoint;
    cout << "Введіть номер рейсу: ";
    in >> plane.flightNumber;
    cout << "Введіть час відправлення: ";
    in >> plane.departureTime;
    cout << "Введіть тривалість подорожі: ";
    in >> plane.travelDuration;
    cout << "Введіть кількість місць: ";
    in >> plane.numberOfSeats;
    return in;
}

ostream& operator<<(ostream& out, const Plain& plane) {
    plane.displayInfo();
    return out;
}

bool Plain::operator==(const Plain& other) const {
    return id == other.id && departurePoint == other.departurePoint &&
           destinationPoint == other.destinationPoint && flightNumber == other.flightNumber &&
           departureTime == other.departureTime && travelDuration == other.travelDuration &&
           numberOfSeats == other.numberOfSeats;
}
