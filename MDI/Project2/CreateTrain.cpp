#include "CreateTrain.h"
#include "ui_CreateTrain.h"
#include <QMessageBox>

CreateTrain::CreateTrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTrain)
{
    ui->setupUi(this);
}

CreateTrain::~CreateTrain()
{
    delete ui;
}

void CreateTrain::on_pExit_clicked()
{
    QCoreApplication::quit();
}


void CreateTrain::on_btCreateTrain_clicked()
{
    if (ui->numberTrain->text().isEmpty() || ui->nameTrain->text().isEmpty() ||
        ui->departureTime->text().isEmpty() || ui->departureStation->text().isEmpty() ||
        ui->destinationStation->text().isEmpty() || ui->route->text().isEmpty() ||
        ui->duration->text().isEmpty() || ui->generalSits->text().isEmpty() ||
        ui->coupeSits->text().isEmpty() || ui->reservedSits->text().isEmpty() ||
        ui->luxurySits->text().isEmpty()) {

        QMessageBox::warning(this, "Помилка", "Заповніть усі обов’язкові поля!");
        return;
    }

    int numberTrainE = ui->numberTrain->text().toInt();
    QString nameTrainE = ui->nameTrain->text();
    QString departureTimeE = ui->departureTime->text();
    QString departureStationE = ui->departureStation->text();
    QString destinationStationE = ui->destinationStation->text();
    QString routeE = ui->route->text();
    double durationE = ui->duration->text().toDouble();
    int generalSitsE = ui->generalSits->text().toInt();
    int coupeSeatsE = ui->coupeSits->text().toInt();
    int reservedSeatsE = ui->reservedSits->text().toInt();
    int luxurySeatsE = ui->luxurySits->text().toInt();

    train = new PassengerTrain(0, numberTrainE, nameTrainE.toStdString(), departureTimeE.toStdString(),
                               departureStationE.toStdString(), destinationStationE.toStdString(),
                               routeE.toStdString(), durationE, generalSitsE, coupeSeatsE, reservedSeatsE, luxurySeatsE);

    emit trainCreated(train);

    QMessageBox::information(this, "Об’єкт створено", "Новий об'єкт поїзда успішно створено!");
}


void CreateTrain::on_btnBack_clicked()
{
    this->reject();
}

