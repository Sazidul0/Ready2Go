#ifndef DELIVERYBOY_H
#define DELIVERYBOY_H

#include <QWidget>
#include<QMessageBox>
#include<QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

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

    void on_DeliveryBoy_signup_button_clicked();

    void on_BackToMenu_2_clicked();

    void on_DeliveryBoy_signup_button_2_clicked();

    void on_Menu_Button_clicked();

    void on_BackToMenu_3_clicked();

    void on_DeliveryBoy_signup_button_3_clicked();

private:
    Ui::DeliveryBoy *ui;
    QString  DeliveryBoy_input_login_input_pass,DeliveryBoy_input_login_email,deliveryboy_signup_name,deliveryboy_signup_email,deliveryboy_signup_address,deliveryboy_signup_contact,deliveryboy_signup_password;
    QSqlDatabase db2;
};

#endif // DELIVERYBOY_H
