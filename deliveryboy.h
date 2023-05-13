#ifndef DELIVERYBOY_H
#define DELIVERYBOY_H

#include <QWidget>
#include<QMessageBox>
#include<QDebug>
#include "mainmenu.h"

namespace Ui {
class DeliveryBoy;
}

class DeliveryBoy : public QWidget
{
    Q_OBJECT

public:
    explicit DeliveryBoy(QWidget *parent = nullptr);
    ~DeliveryBoy();

private slots:
    void on_DeliveryBoy_Button_2_clicked();

    void on_DeliveryBoy_Button_clicked();

    void on_BackToMenu_clicked();

private:
    Ui::DeliveryBoy *ui;
    QString  DeliveryBoy_input_login_input_pass,DeliveryBoy_input_login_email;
};

#endif // DELIVERYBOY_H
