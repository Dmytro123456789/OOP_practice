#ifndef PASSENGERTRAINDIALOG_H
#define PASSENGERTRAINDIALOG_H

#include "PassengerTrain.h"
#include <QDialog>
#include <QLineEdit>

class PassengerTrainDialog : public QDialog {
    Q_OBJECT

public:
    explicit PassengerTrainDialog(QWidget *parent = nullptr);

signals:
    void trainCreated(PassengerTrain *train);

private slots:
    void onCreateClicked();

private:
    QLineEdit *idLineEdit;
    QLineEdit *trainNumberLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *departureTimeLineEdit;
    QLineEdit *departureStationLineEdit;
    QLineEdit *destinationStationLineEdit;
    QLineEdit *routeLineEdit;
    QLineEdit *travelDurationLineEdit;
    QLineEdit *generalSeatsLineEdit;
    QLineEdit *coupeSeatsLineEdit;
    QLineEdit *reservedSeatsLineEdit;
    QLineEdit *luxurySeatsLineEdit;
};

#endif // PASSENGERTRAINDIALOG_H
