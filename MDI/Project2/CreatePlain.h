#ifndef CREATEPLAIN_H
#define CREATEPLAIN_H

#include <QDialog>
#include "Plain.h"

namespace Ui {
class createPlain;
}

class CreatePlain : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePlain(QWidget *parent = nullptr);
    ~CreatePlain();
     void setPlain(Plain *p);
signals:
     void plainCreated(Plain* p);
private slots:
    void on_pExit_clicked();

    void on_btCreatePlain_clicked();

    void on_btShowInfo_clicked();

    void on_btnBack_clicked();

private:
    Ui::createPlain *ui;
    Plain *plain;
};

#endif // CREATEPLAIN_H
