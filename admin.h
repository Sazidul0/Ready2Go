#ifndef ADMIN_H
#define ADMIN_H
#include<QMessageBox>
#include<QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>


#include "mainmenu.h"

#include <QWidget>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:


    void on_BackToMenu_clicked();

    void on_Admin_login_Button_clicked();

    void on_Menu_Button_clicked();

    void on_BackToMenu_2_clicked();

    void on_Completed_Order_clicked();

    void on_Track_Order_clicked();

    void on_Panding_Order_clicked();

    void on_All_Users_clicked();

    void on_Delivery_Boy_clicked();

    void on_All_Sellers_clicked();

    void on_Available_Items_clicked();

    void on_All_Warehouse_clicked();

private:
    Ui::Admin *ui;
    QString admin_username, admin_userpass;
    QSqlDatabase db;
};

#endif // ADMIN_H
