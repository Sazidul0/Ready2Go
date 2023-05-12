#include "seller.h"
#include "ui_seller.h"

Seller::Seller(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
}

Seller::~Seller()
{
    delete ui;
}
