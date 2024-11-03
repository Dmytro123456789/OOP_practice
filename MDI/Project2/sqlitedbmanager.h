#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "Plain.h"
#include "PassengerTrain.h"

class sqlitedmanager
{
public:
    sqlitedmanager();
    ~sqlitedmanager();

    void connectToDataBase();
    void closeDataBase();
    QSqlDatabase getDB();
    bool createTables();
    bool insertIntoTable(const Plain& plainDB);
    bool insertIntoTable(const PassengerTrain& trainBD);
private:
    QSqlDatabase db;
};

#endif // SQLITEDBMANAGER_H
