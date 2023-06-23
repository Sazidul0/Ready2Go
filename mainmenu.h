#ifndef MAINMENU_H
#define MAINMENU_H

#include "admin.h"
#include "user.h"
#include "deliveryboy.h"
#include "seller.h"
#include "warehouse.h"
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_admin_clicked();

    void on_pushButton_user_clicked();

    void on_pushButton_seller_clicked();

    void on_pushButton_warehouse_clicked();

    void on_pushButton_deliveryBoy_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;
    QSqlDatabase db3;
};
#endif // MAINMENU_H
