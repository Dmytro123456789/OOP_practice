#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CreateTrain.h"
#include "CreatePlain.h"
#include "Plain.h"
#include <QMainWindow>
#include <QCoreApplication>
#include <QMessageBox>
#include "QListWidgetItem"
#include <QSqlTableModel>
#include "sqlitedbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createTrain_clicked();

    void on_createPlain_clicked();

    void on_pExit_clicked();

    void onPlainCreated(Plain* plainDB);

    void onPassengerTrainCreated(PassengerTrain* trainDB);

signals:
    void trainCreated(PassengerTrain* train);
    void plainCreated(Plain* plane);

private:
    Ui::MainWindow *ui;
    sqlitedmanager *dbManager;
    CreateTrain *createTrain;
    CreatePlain *createPlain;
    Plain *plain;
    PassengerTrain *train;

    void loadPlainTable();
    void loadPassengerTrainTable();
};
#endif // MAINWINDOW_H
