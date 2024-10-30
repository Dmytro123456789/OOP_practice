#include "showTrain.h"
#include "ui_showTrain.h"

showTrain::showTrain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showTrain)
{
    ui->setupUi(this);
}

showTrain::~showTrain()
{
    delete ui;
}

void showTrain::onTrainReceived(PassengerTrain *train)
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString("Номер поїзда: %1, Назва поїзда: %2, Час відправлення: %3")
                      .arg(train->getTrainNumber())
                      .arg(QString::fromStdString(train->getTrainName()))
                      .arg(QString::fromStdString(train->getDepartureTime())));
    ui->trainListWidget->addItem(item);
}
