#include "deliveryboy.h"
#include "ui_deliveryboy.h"

DeliveryBoy::DeliveryBoy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeliveryBoy)
{
    ui->setupUi(this);
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

    if(DeliveryBoy_input_login_email=="delivery_boy" && DeliveryBoy_input_login_input_pass=="123")
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

