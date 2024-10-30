#include "PlainDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "plain.h"

PlainDialog::PlainDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    idLineEdit = new QLineEdit(this);
    departurePointLineEdit = new QLineEdit(this);
    destinationPointLineEdit = new QLineEdit(this);
    flightNumberLineEdit = new QLineEdit(this);
    departureTimeLineEdit = new QLineEdit(this);
    travelDurationLineEdit = new QLineEdit(this);
    numberOfSeatsLineEdit = new QLineEdit(this);

    layout->addWidget(new QLabel("ID:"));
    layout->addWidget(idLineEdit);

    layout->addWidget(new QLabel("Точка відправлення:"));
    layout->addWidget(departurePointLineEdit);

    layout->addWidget(new QLabel("Точка призначення:"));
    layout->addWidget(destinationPointLineEdit);

    layout->addWidget(new QLabel("Номер рейсу:"));
    layout->addWidget(flightNumberLineEdit);

    layout->addWidget(new QLabel("Час відправлення:"));
    layout->addWidget(departureTimeLineEdit);

    layout->addWidget(new QLabel("Тривалість подорожі:"));
    layout->addWidget(travelDurationLineEdit);

    layout->addWidget(new QLabel("Кількість місць:"));
    layout->addWidget(numberOfSeatsLineEdit);

    QPushButton *createButton = new QPushButton("Створити", this);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked, this, &PlainDialog::onCreateClicked);
}

void PlainDialog::onCreateClicked() {
    Plain *plain = new Plain(
        idLineEdit->text().toInt(),
        departurePointLineEdit->text().toStdString(),
        destinationPointLineEdit->text().toStdString(),
        flightNumberLineEdit->text().toStdString(),
        departureTimeLineEdit->text().toStdString(),
        travelDurationLineEdit->text().toDouble(),
        numberOfSeatsLineEdit->text().toInt()
        );

    emit plainCreated(plain);
    accept();
}
