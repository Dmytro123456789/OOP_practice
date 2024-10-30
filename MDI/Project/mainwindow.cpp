#include "mainwindow.h"
#include "passengertraindialog.h"
#include "plaindialog.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    createPassengerTrainBtn = new QPushButton("Створити PassengerTrain", this);
    createPlainBtn = new QPushButton("Створити Plain", this);
    showPassengerTrainListBtn = new QPushButton("Список PassengerTrain", this);
    showPlainListBtn = new QPushButton("Список Plain", this);
    exitBtn = new QPushButton("Вихід", this);

    passengerTrainListWidget = new QListWidget();
    passengerTrainListWidget->setHidden(true);

    plainListWidget = new QListWidget();
    plainListWidget->setHidden(true);

    layout->addWidget(createPassengerTrainBtn);
    layout->addWidget(createPlainBtn);
    layout->addWidget(showPassengerTrainListBtn);
    layout->addWidget(showPlainListBtn);
    layout->addWidget(exitBtn);
    layout->addWidget(passengerTrainListWidget);
    layout->addWidget(plainListWidget);

    connect(createPassengerTrainBtn, &QPushButton::clicked, this, &MainWindow::createPassengerTrain);
    connect(createPlainBtn, &QPushButton::clicked, this, &MainWindow::createPlain);
    connect(showPassengerTrainListBtn, &QPushButton::clicked, this, &MainWindow::showPassengerTrainList);
    connect(showPlainListBtn, &QPushButton::clicked, this, &MainWindow::showPlainList);
    connect(exitBtn, &QPushButton::clicked, this, &QMainWindow::close);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    qDeleteAll(passengerTrains);
    qDeleteAll(plains);
}

void MainWindow::createPassengerTrain() {
    PassengerTrainDialog dialog(this);
    connect(&dialog, &PassengerTrainDialog::trainCreated, this, &MainWindow::receivePassengerTrain);
    dialog.exec();
}

void MainWindow::createPlain() {
    PlainDialog dialog(this);
    connect(&dialog, &PlainDialog::plainCreated, this, &MainWindow::receivePlain);
    dialog.exec();
}

void MainWindow::showPassengerTrainList() {
    passengerTrainListWidget->setHidden(!passengerTrainListWidget->isHidden());
}

void MainWindow::showPlainList() {
    plainListWidget->setHidden(!plainListWidget->isHidden());
}

void MainWindow::receivePassengerTrain(PassengerTrain *train) {
    passengerTrains.append(train);
    passengerTrainListWidget->addItem(QString::fromStdString(train->getName()));
}

void MainWindow::receivePlain(Plain *plain) {
    plains.append(plain);
    plainListWidget->addItem(QString::fromStdString(plain->getFlightNumber()));
}
