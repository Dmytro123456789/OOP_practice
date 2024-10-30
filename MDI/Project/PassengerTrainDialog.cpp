#include "PassengerTrainDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "PassengerTrain.h"

PassengerTrainDialog::PassengerTrainDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    idLineEdit = new QLineEdit(this);
    trainNumberLineEdit = new QLineEdit(this);
    nameLineEdit = new QLineEdit(this);
    departureTimeLineEdit = new QLineEdit(this);
    departureStationLineEdit = new QLineEdit(this);
    destinationStationLineEdit = new QLineEdit(this);
    routeLineEdit = new QLineEdit(this);
    travelDurationLineEdit = new QLineEdit(this);
    generalSeatsLineEdit = new QLineEdit(this);
    coupeSeatsLineEdit = new QLineEdit(this);
    reservedSeatsLineEdit = new QLineEdit(this);
    luxurySeatsLineEdit = new QLineEdit(this);

    layout->addWidget(new QLabel("ID:"));
    layout->addWidget(idLineEdit);

    layout->addWidget(new QLabel("Номер поїзда:"));
    layout->addWidget(trainNumberLineEdit);

    layout->addWidget(new QLabel("Назва поїзда:"));
    layout->addWidget(nameLineEdit);

    layout->addWidget(new QLabel("Час відправлення:"));
    layout->addWidget(departureTimeLineEdit);

    layout->addWidget(new QLabel("Станція відправлення:"));
    layout->addWidget(departureStationLineEdit);

    layout->addWidget(new QLabel("Станція прибуття:"));
    layout->addWidget(destinationStationLineEdit);

    layout->addWidget(new QLabel("Маршрут:"));
    layout->addWidget(routeLineEdit);

    layout->addWidget(new QLabel("Тривалість подорожі:"));
    layout->addWidget(travelDurationLineEdit);

    layout->addWidget(new QLabel("Загальні місця:"));
    layout->addWidget(generalSeatsLineEdit);

    layout->addWidget(new QLabel("Місця в купе:"));
    layout->addWidget(coupeSeatsLineEdit);

    layout->addWidget(new QLabel("Зарезервовані місця:"));
    layout->addWidget(reservedSeatsLineEdit);

    layout->addWidget(new QLabel("Люкс місця:"));
    layout->addWidget(luxurySeatsLineEdit);

    QPushButton *createButton = new QPushButton("Створити", this);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked, this, &PassengerTrainDialog::onCreateClicked);
}

void PassengerTrainDialog::onCreateClicked() {
    PassengerTrain *train = new PassengerTrain(
        idLineEdit->text().toInt(),
        trainNumberLineEdit->text().toInt(),
        nameLineEdit->text().toStdString(),
        departureTimeLineEdit->text().toStdString(),
        departureStationLineEdit->text().toStdString(),
        destinationStationLineEdit->text().toStdString(),
        routeLineEdit->text().toStdString(),
        travelDurationLineEdit->text().toDouble(),
        generalSeatsLineEdit->text().toInt(),
        coupeSeatsLineEdit->text().toInt(),
        reservedSeatsLineEdit->text().toInt(),
        luxurySeatsLineEdit->text().toInt()
        );

    emit trainCreated(train);
    accept();
}
