#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->Login->setCurrentIndex(0);

}

Admin::~Admin()
{
    delete ui;
}






void Admin::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window = new MainMenu();
    main_window->show();
}


void Admin::on_Admin_login_Button_clicked()
{
    admin_username = ui->Admin_login_Input_UserName->text();
    admin_userpass = ui->Admin_login_Input_Password->text();

    if(admin_username == "admin" && admin_userpass == "admin"){
        ui->Login->setCurrentIndex(1);
    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->Admin_login_Input_Password->clear();
    ui->Admin_login_Input_UserName->clear();
}


void Admin::on_Menu_Button_clicked()
{
        ui->Login->setCurrentIndex(0);
}


void Admin::on_BackToMenu_2_clicked()
{
        this->hide();
        MainMenu *main_window;
        main_window = new MainMenu();
        main_window->show();
}


void Admin::on_Completed_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Admin::on_Track_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Admin::on_Panding_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Admin::on_All_Users_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Admin::on_Delivery_Boy_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Admin::on_All_Sellers_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void Admin::on_Available_Items_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void Admin::on_All_Warehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

