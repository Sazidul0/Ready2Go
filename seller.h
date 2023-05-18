#ifndef SELLER_H
#define SELLER_H

#include <QWidget>
#include "mainmenu.h"
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class Seller;
}

class Seller : public QWidget
{
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr);
    ~Seller();

private slots:
    void on_BackToMenu_clicked();

    void on_seller_login_Button_clicked();

    void on_Menu_Button_clicked();

private:
    Ui::Seller *ui;
    QString seller_login_email,seller_login_pass;
    QSqlDatabase db4;
};

#endif // SELLER_H
