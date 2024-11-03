#include "sqlitedbmanager.h"

sqlitedmanager::sqlitedmanager() {
    connectToDataBase();
}

sqlitedmanager::~sqlitedmanager() {
    closeDataBase();
}

void sqlitedmanager::connectToDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("trasportBD.sqlite");

    if (!db.open()) {
        qCritical() << "Error: connection to database failed!";
        throw std::runtime_error("Не вдалося підключитися до бази даних");
    } else {
        qDebug() << "Database connected successfully!";
    }
}

void sqlitedmanager::closeDataBase() {
    if (db.isOpen()) {
        db.close();
    }
}

QSqlDatabase sqlitedmanager::getDB() {
    return db;
}

bool sqlitedmanager::createTables()
{
    QSqlQuery query;

    QString createPlainTable = "CREATE TABLE IF NOT EXISTS plain ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "departureStation TEXT, destinationStation TEXT, "
                               "flightNumber INTEGER, departureTime INTEGER, "
                               "travelDuration INTEGER, generalSeats INTEGER)";

    if (!query.exec(createPlainTable)) {
        qWarning() << "Failed to create Plain table:" << query.lastError();
        return false;
    }

    QString createPassengerTrainTable = "CREATE TABLE IF NOT EXISTS passengertrain ("
                                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "name TEXT, trainNumber TEXT, departureTime INTEGER, departureStation TEXT, "
                                        "destinationStation TEXT, route TEXT, travelDuration INTEGER, "
                                        "generalSeats INTEGER, coupeSeats INTEGER, reservedSeats INTEGER, luxurySeats INTEGER)";

    if (!query.exec(createPassengerTrainTable)) {
        qWarning() << "Failed to create PassengerTrain table:" << query.lastError();
        return false;
    }

    return true;
}


bool sqlitedmanager::insertIntoTable(const Plain& plainDB) {
    QSqlQuery query;
    query.prepare("INSERT INTO plain (departureStation, destinationStation, flightNumber, departureTime, travelDuration, generalSeats) "
                  "VALUES (:departureStation, :destinationStation, :flightNumber, :departureTime, :travelDuration, :generalSeats)");

    query.bindValue(":departureStation", QString::fromStdString(plainDB.getDeparturePoint()));
    query.bindValue(":destinationStation", QString::fromStdString(plainDB.getDestinationPoint()));
    query.bindValue(":flightNumber", QString::fromStdString(plainDB.getFlightNumber()));
    query.bindValue(":departureTime", QString::fromStdString(plainDB.getDepartureTime()));
    query.bindValue(":travelDuration", plainDB.getTravelDuration());
    query.bindValue(":generalSeats", plainDB.getGeneralSeats());

    if (!query.exec()) {
        qDebug() << "Failed to insert Plain:" << query.lastError();
        return false;
    }

    return true;
}


bool sqlitedmanager::insertIntoTable(const PassengerTrain& trainDB) {
    QSqlQuery query;
    query.prepare("INSERT INTO passengertrain (trainNumber, name, departureTime, departureStation, "
                  "destinationStation, route, travelDuration, generalSeats, coupeSeats, reservedSeats, luxurySeats) "
                  "VALUES (:trainNumber, :name, :departureTime, :departureStation, "
                  ":destinationStation, :route, :travelDuration, :generalSeats, :coupeSeats, :reservedSeats, :luxurySeats)");

    query.bindValue(":trainNumber", trainDB.getTrainNumber());
    query.bindValue(":name", QString::fromStdString(trainDB.getName()));
    query.bindValue(":departureTime", QString::fromStdString(trainDB.getDepartureTime()));
    query.bindValue(":departureStation", QString::fromStdString(trainDB.getDepartureStation()));
    query.bindValue(":destinationStation", QString::fromStdString(trainDB.getDestinationStation()));
    query.bindValue(":route", QString::fromStdString(trainDB.getRoute()));
    query.bindValue(":travelDuration", trainDB.getTravelDuration());
    query.bindValue(":generalSeats", trainDB.getGeneralSeats());
    query.bindValue(":coupeSeats", trainDB.getCoupeSeats());
    query.bindValue(":reservedSeats", trainDB.getReservedSeats());
    query.bindValue(":luxurySeats", trainDB.getLuxurySeats());

    if (!query.exec()) {
        qDebug() << "Failed to insert Train:" << query.lastError();
        return false;
    }

    return true;
}

