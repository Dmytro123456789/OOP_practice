#ifndef CREATETRAIN_H
#define CREATETRAIN_H

#include <QDialog>
#include "PassengerTrain.h"

namespace Ui {
class createTrain;
}

class CreateTrain : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTrain(QWidget *parent = nullptr);
    ~CreateTrain();
signals:
    void trainCreated(PassengerTrain* train);

private slots:
    void on_pExit_clicked();

    void on_btCreateTrain_clicked();

    void on_btnBack_clicked();

private:
    Ui::createTrain *ui;
    PassengerTrain *train;
};

#endif // CREATETRAIN_H
