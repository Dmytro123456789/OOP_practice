#include "mainwindow.h"
#include "PassengerTrain.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pbCreateTrain_clicked()
{
    if (ui->lineEdit_name_2->text().isEmpty() || ui->lineEdit_trainNumber_2->text().isEmpty() ||
        ui->lineEdit_departureTime_2->text().isEmpty() || ui->lineEdit_departureStation_2->text().isEmpty() ||
        ui->lineEdit_destinationStation_2->text().isEmpty() || ui->lineEdit_route_2->text().isEmpty() ||
        ui->lineEdit_travelDuration_2->text().isEmpty() || ui->lineEdit_generalSeats_2->text().isEmpty() ||
        ui->lineEdit_coupeSeats_2->text().isEmpty() || ui->lineEdit_reservedSeats_2->text().isEmpty() ||
        ui->lineEdit_luxurySeats_2->text().isEmpty()) {

        QMessageBox::warning(this, "Помилка", "Заповніть усі обов’язкові поля!");
        return;
    }
}

void MainWindow::on_pbShowTrain_clicked()
{
    int trainNumber = ui->lineEdit_trainNumber_2->text().toInt();
    string name = ui->lineEdit_name_2->text().toStdString();
    string departureTime = ui->lineEdit_departureTime_2->text().toStdString();
    string departureStation = ui->lineEdit_departureStation_2->text().toStdString();
    string destinationStation = ui->lineEdit_destinationStation_2->text().toStdString();
    string route = ui->lineEdit_route_2->text().toStdString();
    double travelDuration = ui->lineEdit_travelDuration_2->text().toDouble();
    int generalSeats = ui->lineEdit_generalSeats_2->text().toInt();
    int coupeSeats = ui->lineEdit_coupeSeats_2->text().toInt();
    int reservedSeats = ui->lineEdit_reservedSeats_2->text().toInt();
    int luxurySeats = ui->lineEdit_luxurySeats_2->text().toInt();

    PassengerTrain *train = new PassengerTrain(0,trainNumber,name,departureTime,
                                               departureStation, destinationStation,
                                               route, travelDuration, generalSeats,
                                               coupeSeats, reservedSeats, luxurySeats);

    QMessageBox::information(this, "Об'єкт створено", train->toString());
}



void MainWindow::on_pbQuit_clicked()
{
    QApplication::quit();
}

