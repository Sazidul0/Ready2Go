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

private:
    Ui::Admin *ui;
    QString admin_username, admin_userpass;
    QSqlDatabase db;
};

#endif // ADMIN_H
