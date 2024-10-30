#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QListWidget>
#include <QPushButton>
#include "passengertrain.h"
#include "plain.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createPassengerTrain();
    void createPlain();
    void showPassengerTrainList();
    void showPlainList();
    void receivePassengerTrain(PassengerTrain *train);
    void receivePlain(Plain *plain);

private:
    QList<PassengerTrain*> passengerTrains;
    QList<Plain*> plains;
    QPushButton *createPassengerTrainBtn;
    QPushButton *createPlainBtn;
    QPushButton *showPassengerTrainListBtn;
    QPushButton *showPlainListBtn;
    QPushButton *exitBtn;
    QListWidget *passengerTrainListWidget;
    QListWidget *plainListWidget;
};

#endif // MAINWINDOW_H
