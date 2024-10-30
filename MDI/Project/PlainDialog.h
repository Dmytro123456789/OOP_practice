#ifndef PLAINDIALOG_H
#define PLAINDIALOG_H

#include "Plain.h"
#include <QDialog>
#include <QLineEdit>

class PlainDialog : public QDialog {
    Q_OBJECT

public:
    explicit PlainDialog(QWidget *parent = nullptr);

signals:
    void plainCreated(Plain *plain);

private slots:
    void onCreateClicked();

private:
    QLineEdit *idLineEdit;
    QLineEdit *departurePointLineEdit;
    QLineEdit *destinationPointLineEdit;
    QLineEdit *flightNumberLineEdit;
    QLineEdit *departureTimeLineEdit;
    QLineEdit *travelDurationLineEdit;
    QLineEdit *numberOfSeatsLineEdit;
};

#endif // PLAINDIALOG_H
