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
