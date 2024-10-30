#include "CreateTrain.h"
#include "ui_CreateTrain.h"
#include "PassengerTrain.h"
#include <QMessageBox>

CreateTrain::CreateTrain(QWidget *parent)
    : QDialog(parent), ui(new Ui::createTrain)
{
    ui->setupUi(this);
}

CreateTrain::~CreateTrain()
{
    delete ui;
}

void CreateTrain::clearFields()
{
    ui->numberTrain->clear();
    ui->nameTrain->clear();
    ui->departureTime->clear();
    ui->departureStation->clear();
    ui->destinationStation->clear();
    ui->route->clear();
    ui->duration->clear();
    ui->generalSits->clear();
    ui->coupeSits->clear();
    ui->reservedSits->clear();
    ui->luxurySits->clear();
}

void CreateTrain::on_btCreateTrain_clicked()
{
    QString numberTrain = ui->numberTrain->text();
    QString nameTrain = ui->nameTrain->text();
    QString departureTime = ui->departureTime->text();
    QString departureStation = ui->departureStation->text();
    QString destinationStation = ui->destinationStation->text();
    QString route = ui->route->text();
    QString duration = ui->duration->text();
    QString generalSits = ui->generalSits->text();
    QString coupeSits = ui->coupeSits->text();
    QString reservedSits = ui->reservedSits->text();
    QString luxurySits = ui->luxurySits->text();

    if (numberTrain.isEmpty() || nameTrain.isEmpty() || departureTime.isEmpty() ||
        departureStation.isEmpty() || destinationStation.isEmpty() || route.isEmpty() ||
        duration.isEmpty() || generalSits.isEmpty() || coupeSits.isEmpty() ||
        reservedSits.isEmpty() || luxurySits.isEmpty()) {

        QMessageBox::critical(this, "Помилка", "Помилка введення даних про Поїзд - деякі поля порожні");
        return;
    }

    PassengerTrain *train = new PassengerTrain(
        0,
        numberTrain.toInt(),
        nameTrain.toStdString(),
        departureTime.toStdString(),
        departureStation.toStdString(),
        destinationStation.toStdString(),
        route.toStdString(),
        duration.toDouble(),
        generalSits.toInt(),
        coupeSits.toInt(),
        reservedSits.toInt(),
        luxurySits.toInt()
        );

    emit trainCreated(train);

    QMessageBox::information(this, "Успіх", "Новий об'єкт Поїзд успішно створено!");
    this->clearFields();
    this->accept();
}
