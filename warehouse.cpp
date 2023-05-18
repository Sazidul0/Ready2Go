#include "warehouse.h"
#include "ui_warehouse.h"

Warehouse::Warehouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warehouse)
{
    ui->setupUi(this);
      ui->Login->setCurrentIndex(0);
}

Warehouse::~Warehouse()
{
    delete ui;
}

void Warehouse::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window=new MainMenu();
    main_window->show();
}


void Warehouse::on_warehouse_login_Button_clicked()
{
    warehouse_login_name=ui->warehouse_login_Intput_UserName->text();
    warehouse_login_pass=ui->warehouse_login_Input_Password->text();
    if(warehouse_login_name=="warehouse" && warehouse_login_pass=="123")
    {
        ui->Login->setCurrentIndex(1);
    }

    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->warehouse_login_Intput_UserName->clear();
    ui->warehouse_login_Input_Password->clear();


}


void Warehouse::on_Menu_Button_clicked()
{
     ui->Login->setCurrentIndex(0);
}

