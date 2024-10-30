#ifndef CREATETRAIN_H
#define CREATETRAIN_H

#include <QDialog>
#include "PassengerTrain.h"
#include "qlistwidget.h"

namespace Ui {
class createTrain;
}

class CreateTrain : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTrain(QWidget *parent = nullptr);
    ~CreateTrain();
    void clearFields();
signals:

    void trainCreated(PassengerTrain*);

private slots:

    void on_btCreateTrain_clicked();

private:
    Ui::createTrain *ui;
};

#endif // CREATETRAIN_H
