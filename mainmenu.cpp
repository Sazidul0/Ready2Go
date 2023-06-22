#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_pushButton_admin_clicked()
{
    this->hide();
    Admin *admin_window;
    admin_window = new Admin();
    admin_window->show();
}


void MainMenu::on_pushButton_user_clicked()
{
    this->hide();
    User *user_window;
    user_window=new User();
    user_window->show();


}


void MainMenu::on_pushButton_seller_clicked()
{
    this->hide();
    Seller *seller_window;
    seller_window=new Seller();
    seller_window->show();
}


void MainMenu::on_pushButton_warehouse_clicked()
{
    this->hide();
    Warehouse *warehouse_window;
    warehouse_window=new Warehouse();
    warehouse_window->show();
}


void MainMenu::on_pushButton_deliveryBoy_clicked()
{
    this->hide();
    DeliveryBoy *delivery_window;
    delivery_window=new DeliveryBoy();
    delivery_window->show();

}


void MainMenu::on_Enter_login_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

