#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{

    ui->setupUi(this);
    db5= QSqlDatabase::addDatabase("QSQLITE");
    db5.setDatabaseName("F:/QT/Ready2Go/Database.db");
    qDebug() <<db5.open();
       ui->User_Login->setCurrentIndex(1);

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

    QSqlQuery query;
    query.exec("SELECT *FROM user WHERE email='"+user_login_name+"' AND password='"+user_login_pass+"'");
    if(query.next())
    {
        ui->User_Login->setCurrentIndex(2);
    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->User_login_Intput_UserName->clear();
    ui->User_login_Input_Password->clear();
}


void User::on_User_goto_singup_Button_2_clicked()
{

        ui->User_Login->setCurrentIndex(3);

}


void User::on_pushButton_clicked()
{



}




void User::on_user_signup_button_clicked()
{

    user_signup_name= ui->user_signup_input_name->text();
    user_signup_email=ui->user_signup_input_email->text();
    user_signup_contact=ui->user_signup_input_contact->text();
    user_signup_password=ui->user_signup_input_pass->text();
    user_signup_address=ui->user_signup_input__address->text();


    QSqlQuery query;
    query.exec("INSERT INTO user (name,email,address,contact,password) VALUES('"+user_signup_name+"', '"+user_signup_email+"','"+user_signup_address+"','"+user_signup_contact+"','"+user_signup_password+"')");
    if(query.next())
    {



    }
    else
    {

        QMessageBox::information(this,"SignUp","SignUp Successfull");
        ui->User_Login->setCurrentIndex(1);
    }
    ui->user_signup_input_name->clear();
    ui->user_signup_input_email->clear();
    ui->user_signup_input_contact->clear();
    ui->user_signup_input_pass->clear();



}


void User::on_Menu_Button_clicked()
{
    ui->user_right_menu->setCurrentIndex(0);
}


void User::on_BackToMenu_3_clicked()
{
     ui->User_Login->setCurrentIndex(1);
}


void User::on_on_user_signup_button_clicked()
{
     user_signup_name= ui->user_signup_input_name->text();
     user_signup_email=ui->user_signup_input_email->text();
     user_signup_contact=ui->user_signup_input_contact->text();
     user_signup_password=ui->user_signup_input_pass->text();
     user_signup_address=ui->user_signup_input__address->text();


     QSqlQuery query;
     query.exec("INSERT INTO user (name,email,address,contact,password) VALUES('"+user_signup_name+"', '"+user_signup_email+"','"+user_signup_address+"','"+user_signup_contact+"','"+user_signup_password+"')");
     if(query.next())
     {



     }
     else
     {

        QMessageBox::information(this,"SignUp","SignUp Successfull");
        ui->User_Login->setCurrentIndex(1);
     }
     ui->user_signup_input_name->clear();
     ui->user_signup_input_email->clear();
     ui->user_signup_input_contact->clear();
     ui->user_signup_input_pass->clear();



}




void User::on_Completed_Order_clicked()
{
    ui->user_right_menu->setCurrentIndex(1);
}


void User::on_Track_Order_clicked()
{
    ui->user_right_menu->setCurrentIndex(2);
}


void User::on_Cart_clicked()
{
    ui->user_right_menu->setCurrentIndex(4);
}


void User::on_All_Warehouse_clicked()
{
    ui->user_right_menu->setCurrentIndex(5);
}


void User::on_Logout_clicked()
{
    ui->User_Login->setCurrentIndex(1);
}

