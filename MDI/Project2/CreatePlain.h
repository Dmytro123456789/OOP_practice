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
     void clearFields();
signals:
     void plainCreated(Plain*);
private slots:

    void on_btCreatePlain_clicked();

private:
    Ui::createPlain *ui;
};

#endif // CREATEPLAIN_H
