#include "seller.h"
#include "ui_seller.h"

Seller::Seller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
     ui->Login->setCurrentIndex(0);
}

Seller::~Seller()
{
    delete ui;
}

void Seller::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window = new MainMenu();
    main_window->show();
}


void Seller::on_seller_login_Button_clicked()
{
    seller_login_email=ui->seller_login_Intput_UserName->text();
    seller_login_pass=ui->seller_login_Input_Password->text();

    if(seller_login_email=="seller" && seller_login_pass=="123")
    {
        ui->Login->setCurrentIndex(1);
    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->seller_login_Input_Password->clear();
    ui->seller_login_Intput_UserName->clear();
}


void Seller::on_Menu_Button_clicked()
{
    ui->Login->setCurrentIndex(0);
}

