#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CreateTrain.h"
#include "CreatePlain.h"
#include "showPlain.h"
#include "showTrain.h"
#include "Plain.h"
#include <QMainWindow>
#include <QCoreApplication>
#include <QMessageBox>

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

    void on_showPlain_clicked();

    void on_showTrain_clicked();

    void on_pExit_clicked();

signals:
    void trainCreated(PassengerTrain* train);
    void plainCreated(Plain* plane);

private:
    Ui::MainWindow *ui;
    CreateTrain *createTrain;
    CreatePlain *createPlain;
    showTrain *showTrainDialog;
    showPlain *showPlainDialog;
    Plain *plain;
    PassengerTrain *train;
};
#endif // MAINWINDOW_H
