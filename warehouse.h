#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QWidget>
#include "mainmenu.h"
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class Warehouse;
}

class Warehouse : public QWidget
{
    Q_OBJECT

public:
    explicit Warehouse(QWidget *parent = nullptr);
    ~Warehouse();

private slots:
    void on_BackToMenu_clicked();

    void on_warehouse_login_Button_clicked();

    void on_Menu_Button_clicked();

private:
    Ui::Warehouse *ui;
    QString warehouse_login_name,warehouse_login_pass;
    QSqlDatabase db6;
};

#endif // WAREHOUSE_H
