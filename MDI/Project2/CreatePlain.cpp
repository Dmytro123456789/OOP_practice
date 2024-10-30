#include "CreatePlain.h"
#include "ui_CreatePlain.h"
#include "Plain.h"
#include <QMessageBox>

CreatePlain::CreatePlain(QWidget *parent)
    : QDialog(parent), ui(new Ui::createPlain)
{
    ui->setupUi(this);
}

CreatePlain::~CreatePlain()
{
    delete ui;
}

void CreatePlain::clearFields()
{
    ui->departurePoint->clear();
    ui->destinationPoint->clear();
    ui->numberWay->clear();
    ui->timeFly->clear();
    ui->durationP->clear();
    ui->generalSitsP->clear();
}

void CreatePlain::on_btCreatePlain_clicked()
{
    QString departurePoint = ui->departurePoint->text();
    QString destinationPoint = ui->destinationPoint->text();
    QString flightNumber = ui->numberWay->text();
    QString departureTime = ui->timeFly->text();
    QString travelDuration = ui->durationP->text();
    QString numberOfSeats = ui->generalSitsP->text();

    if (departurePoint.isEmpty() || destinationPoint.isEmpty() || flightNumber.isEmpty() ||
        departureTime.isEmpty() || travelDuration.isEmpty() || numberOfSeats.isEmpty()) {

        QMessageBox::critical(this, "Помилка", "Помилка введення даних про Літак - деякі поля порожні");
    } else {
        Plain *plain = new Plain(
            0,
            departurePoint.toStdString(),
            destinationPoint.toStdString(),
            flightNumber.toStdString(),
            departureTime.toStdString(),
            travelDuration.toDouble(),
            numberOfSeats.toInt()
            );

        emit plainCreated(plain);

        QMessageBox::information(this, "Успіх", "Новий об'єкт Літак успішно створено!");
        this->clearFields();
        this->accept();
    }
}
