#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CreateTrain.h"
#include "CreatePlain.h"

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    createTrain(new CreateTrain(this)),
    createPlain(new CreatePlain(this)),
    plain(nullptr), train(nullptr)
{
    ui->setupUi(this);

    connect(createPlain, &CreatePlain::plainCreated, this, [this](Plain* plane) {
        this->plain = plane;
    });

    connect(createTrain, &CreateTrain::trainCreated, this, [this](PassengerTrain* train) {
        this->train = train;
    });
}

void MainWindow::on_createTrain_clicked()
{
    createTrain->show();
}

void MainWindow::on_createPlain_clicked()
{
    createPlain->setPlain(plain);
    createPlain->exec();
}

void MainWindow::on_showPlain_clicked()
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

void MainWindow::on_showTrain_clicked()
{
    if (!train) {
        QMessageBox::warning(this, "Помилка", "Об'єкт поїзда не створено!");
        return;
    }

    QString infoMessage = QString("Номер поїзда: %1\n"
                                  "Назва поїзда: %2\n"
                                  "Час відправлення: %3\n"
                                  "Пункт відправлення: %4\n"
                                  "Пункт призначення: %5\n"
                                  "Маршрут: %6\n"
                                  "Тривалість: %7\n"
                                  "Загальні місця: %8\n"
                                  "Купейні місця: %9\n"
                                  "Зарезервовані місця: %10\n"
                                  "Люкс: %11")
                              .arg((train->getTrainNumber()))
                              .arg(QString::fromStdString(train->getTrainName()))
                              .arg(QString::fromStdString(train->getDepartureTime()))
                              .arg(QString::fromStdString(train->getDepartureStation()))
                              .arg(QString::fromStdString(train->getDestinationStation()))
                              .arg(QString::fromStdString(train->getRoute()))
                              .arg(train->getTravelDuration())
                              .arg(train->getGeneralSeats())
                              .arg(train->getCoupeSeats())
                              .arg(train->getReservedSeats())
                              .arg(train->getLuxurySeats());

    QMessageBox::information(this, "Інформація про об'єкт", infoMessage);
}

void MainWindow::on_pExit_clicked()
{
    QCoreApplication::quit();
}
