#include "CreatePlain.h"
#include "ui_CreatePlain.h"
#include "Plain.h"
#include <QMessageBox>

CreatePlain::CreatePlain(QWidget *parent)
    : QDialog(parent), ui(new Ui::createPlain), plain(nullptr)
{
    ui->setupUi(this);
}

CreatePlain::~CreatePlain()
{
    delete ui;
}

void CreatePlain::on_pExit_clicked()
{
    QCoreApplication::quit();
}

void CreatePlain::on_btCreatePlain_clicked()
{
    if (ui->departurePoint->text().isEmpty() || ui->destinationPoint->text().isEmpty() ||
        ui->numberWay->text().isEmpty() || ui->timeFly->text().isEmpty() ||
        ui->durationP->text().isEmpty() || ui->generalSitsP->text().isEmpty()) {

        QMessageBox::warning(this, "Помилка", "Заповніть усі обов’язкові поля!");
        return;
    }

    plain = new Plain(0,
                      ui->departurePoint->text().toStdString(),
                      ui->destinationPoint->text().toStdString(),
                      ui->numberWay->text().toStdString(),
                      ui->timeFly->text().toStdString(),
                      ui->durationP->text().toDouble(),
                      ui->generalSitsP->text().toInt());

    emit plainCreated(plain);
    QMessageBox::information(this, "Об’єкт створено", "Новий об'єкт літака успішно створено!");
}

void CreatePlain::on_btShowInfo_clicked()
{
    if (!plain) {
        QMessageBox::warning(this, "Помилка", "Об'єкт літака не створено!");
        return;
    }

    QString infoMessage = QString("Пункт відправлення: %1\n"
                                  "Пункт призначення: %2\n"
                                  "Номер рейсу: %3\n"
                                  "Час вильоту: %4\n"
                                  "Тривалість подорожі: %5\n"
                                  "Кількість загальних місць: %6")
                              .arg(QString::fromStdString(plain->getDeparturePoint()))
                              .arg(QString::fromStdString(plain->getDestinationPoint()))
                              .arg(QString::fromStdString(plain->getFlightNumber()))
                              .arg(QString::fromStdString(plain->getDepartureTime()))
                              .arg(plain->getTravelDuration())
                              .arg(plain->getGeneralSeats());

    QMessageBox::information(this, "Інформація про об'єкт", infoMessage);
}

void CreatePlain::setPlain(Plain *p) {
    plain = p;
}

void CreatePlain::on_btnBack_clicked()
{
    this->reject();
}
