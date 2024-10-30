#include "showPlain.h"
#include "ui_showPlain.h"

showPlain::showPlain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showPlain)
{
    ui->setupUi(this);
}

showPlain::~showPlain()
{
    delete ui;
}
void showPlain::onPlainReceived(Plain *plane)
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString("Пункт відправлення: %1, Пункт призначення: %2, Номер рейсу: %3")
                      .arg(QString::fromStdString(plane->getDeparturePoint()))
                      .arg(QString::fromStdString(plane->getDestinationPoint()))
                      .arg(QString::fromStdString(plane->getFlightNumber())));
    ui->plainListWidget->addItem(item);
}
