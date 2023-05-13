#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}




void User::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window=new MainMenu();
    main_window->show();
}


void User::on_User_login_Button_clicked()
{
    user_login_name=ui->User_login_Intput_UserName->text();
    user_login_pass=ui->User_login_Input_Password->text();
    if( user_login_name=="user" &&  user_login_pass=="123")
    {
        ui->User_Login->setCurrentIndex(1);

    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->User_login_Intput_UserName->clear();
    ui->User_login_Input_Password->clear();
}

