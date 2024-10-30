#ifndef SHOWPLAIN_H
#define SHOWPLAIN_H

#include "Plain.h"
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class showPlain;
}

class showPlain : public QDialog
{
    Q_OBJECT

public:
    explicit showPlain(QWidget *parent = nullptr);
    ~showPlain();

public slots:
    void onPlainReceived(Plain *plane);

private:
    Ui::showPlain *ui;
};

#endif // SHOWPLAIN_H
