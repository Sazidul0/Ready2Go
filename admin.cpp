#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

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

