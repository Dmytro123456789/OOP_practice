#include "mainwindow.h"
#include "showTrain.h"
#include "ui_mainwindow.h"
#include "CreateTrain.h"
#include "CreatePlain.h"
#include "showTrain.h"
#include "showPlain.h"

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    createTrain(new CreateTrain(this)),
    createPlain(new CreatePlain(this)),
    showTrainDialog(new showTrain(this)),
    showPlainDialog(new showPlain(this)),
    plain(nullptr), train(nullptr)
{
    ui->setupUi(this);

    connect(createPlain, &CreatePlain::plainCreated, this, [this](Plain* plane) {
        this->plain = plane;
        emit plainCreated(plane);
    });

    connect(createTrain, &CreateTrain::trainCreated, this, [this](PassengerTrain* train) {
        this->train = train;
        emit trainCreated(train);
    });

    connect(this, &MainWindow::plainCreated, showPlainDialog, &showPlain::onPlainReceived);
    connect(this, &MainWindow::trainCreated, showTrainDialog, &showTrain::onTrainReceived);
}

void MainWindow::on_createTrain_clicked()
{
    createTrain->show();
}

void MainWindow::on_createPlain_clicked()
{
    createPlain->show();
}

void MainWindow::on_showPlain_clicked()
{
    showPlainDialog->show();
}

void MainWindow::on_showTrain_clicked()
{
    showTrainDialog->show();
}

void MainWindow::on_pExit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Вихід", "Вийти з програми?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::exit(0);
    }
}
