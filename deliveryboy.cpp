#include "deliveryboy.h"
#include "ui_deliveryboy.h"

DeliveryBoy::DeliveryBoy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeliveryBoy)
{
    ui->setupUi(this);
    db2= QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("S:/QTTT/Ready2Go/Database.db");
    qDebug() <<db2.open();
      ui->DeliveryBoy_2->setCurrentIndex(0);

}
DeliveryBoy::~DeliveryBoy()
{
    delete ui;
}

void DeliveryBoy::on_DeliveryBoy_Button_2_clicked()
{

}


void DeliveryBoy::on_DeliveryBoy_Button_clicked()
{
    DeliveryBoy_input_login_email=ui->DeliveryBoy_login_Intput_UserName->text();
    DeliveryBoy_input_login_input_pass=ui->DeliveryBoy_login_Input_Password->text();

    QSqlQuery query;
    query.exec("SELECT *FROM deliveryboy WHERE email='"+DeliveryBoy_input_login_email+"' AND password='"+DeliveryBoy_input_login_input_pass+"'");
    if(query.next())
    {
        ui->DeliveryBoy_2->setCurrentIndex(1);
    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->DeliveryBoy_login_Input_Password->clear();
    ui->DeliveryBoy_login_Intput_UserName->clear();
}


void DeliveryBoy::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window=new MainMenu();
    main_window->show();
}


void DeliveryBoy::on_DeliveryBoy_signup_button_clicked()
{
    deliveryboy_signup_name= ui->DeliveryBoy_signup_Intput_UserName->text();
    deliveryboy_signup_email=ui->DeliveryBoy_signup_Intput_email->text();
    deliveryboy_signup_contact=ui->DeliveryBoy_signu_Intput_contact->text();
    deliveryboy_signup_password=ui->DeliveryBoy_signup_Input_password->text();
    deliveryboy_signup_address=ui->DeliveryBoy_signup_Intput_address->text();


    QSqlQuery query;
    query.exec("INSERT INTO deliveryboy (name,email,address,contact,password) VALUES('"+deliveryboy_signup_name+"', '"+deliveryboy_signup_email+"','"+deliveryboy_signup_address+"','"+deliveryboy_signup_contact+"','"+deliveryboy_signup_password+"')");
    if(query.next())
    {

    }
    else
    {

        QMessageBox::information(this,"SignUp","SignUp Successfull");
        ui->DeliveryBoy_2->setCurrentIndex(0);
    }
    ui->DeliveryBoy_signup_Intput_UserName->clear();
    ui->DeliveryBoy_signup_Intput_email->clear();
    ui->DeliveryBoy_signu_Intput_contact->clear();
    ui->DeliveryBoy_signup_Intput_address->clear();
     ui->DeliveryBoy_signup_Input_password->clear();
}


void DeliveryBoy::on_BackToMenu_2_clicked()
{
     this->hide();
     MainMenu *main_window;
     main_window=new MainMenu();
     main_window->show();
}


void DeliveryBoy::on_DeliveryBoy_signup_button_2_clicked()
{

     DeliveryBoy_input_login_email=ui->DeliveryBoy_login_Intput_UserName->text();
     DeliveryBoy_input_login_input_pass=ui->DeliveryBoy_login_Input_Password->text();

     QSqlQuery query;
     query.exec("SELECT *FROM deliveryboy WHERE email='"+DeliveryBoy_input_login_email+"' AND password='"+DeliveryBoy_input_login_input_pass+"'");
     if(query.next())
     {
        ui->DeliveryBoy_2->setCurrentIndex(1);
     }
     else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
     }
     ui->DeliveryBoy_login_Input_Password->clear();
     ui->DeliveryBoy_login_Intput_UserName->clear();

}


void DeliveryBoy::on_Menu_Button_clicked()
{
    ui->DeliveryBoy_2->setCurrentIndex(0);
}


void DeliveryBoy::on_BackToMenu_3_clicked()
{
       ui->DeliveryBoy_2->setCurrentIndex(0);
}


void DeliveryBoy::on_DeliveryBoy_signup_button_3_clicked()
{
   ui->DeliveryBoy_2->setCurrentIndex(2);
}

