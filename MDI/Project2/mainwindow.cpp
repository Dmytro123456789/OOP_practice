#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CreateTrain.h"
#include "CreatePlain.h"
#include <QSqlTableModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    plain(nullptr), train(nullptr)
{
    ui->setupUi(this);

    try {
        dbManager = new sqlitedmanager();
        dbManager->connectToDataBase();
        if (!dbManager->createTables()) {
            qCritical() << "Failed to create tables.";
            QMessageBox::critical(this, "Database Error", "Не вдалося створити таблиці в базі даних.");
            return;
        }
    } catch (const std::runtime_error &e) {
        qCritical() << "Runtime error:" << e.what();
        QMessageBox::critical(this, "Database Error", "Не вдалося підключитися до бази даних. Перевірте з'єднання!");
        return;
    }

    loadPlainTable();
    loadPassengerTrainTable();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete dbManager;
}

void MainWindow::on_createTrain_clicked()
{
    CreateTrain *dialog = new CreateTrain(this);
    connect(dialog, &CreateTrain::trainCreated, this, &MainWindow::onPassengerTrainCreated);
    dialog->show();
}

void MainWindow::on_createPlain_clicked()
{
    CreatePlain *dialog = new CreatePlain(this);
    connect(dialog, &CreatePlain::plainCreated, this, &MainWindow::onPlainCreated);
    dialog->show();
}


void MainWindow::onPlainCreated(Plain* plainDB)
{
    dbManager->insertIntoTable(*plainDB);
    loadPlainTable();
}

void MainWindow::onPassengerTrainCreated(PassengerTrain* trainDB)
{
    dbManager->insertIntoTable(*trainDB);
    loadPassengerTrainTable();
}

void MainWindow::loadPlainTable()
{
    QSqlTableModel *model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable("plain");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
}

void MainWindow::loadPassengerTrainTable()
{
    QSqlTableModel *model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable("passengertrain");
    model->select();

    ui->tableView_2->setModel(model);
    ui->tableView_2->hideColumn(0);
}

void MainWindow::on_pExit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Вихід", "Вийти з програми?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::exit(0);
    }
}
