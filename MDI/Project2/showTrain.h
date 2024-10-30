#ifndef SHOWTRAIN_H
#define SHOWTRAIN_H

#include "PassengerTrain.h"
#include <QDialog>
#include <QListWidget>
#include <QListView>

namespace Ui {
class showTrain;
}

class showTrain : public QDialog
{
    Q_OBJECT

public:
    explicit showTrain(QWidget *parent = nullptr);
    ~showTrain();

public slots:
    void onTrainReceived(PassengerTrain *train);

private:
    Ui::showTrain *ui;
};

#endif // SHOWTRAIN_H
