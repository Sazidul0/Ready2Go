#include "warehouse.h"
#include "ui_warehouse.h"

Warehouse::Warehouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warehouse)
{
    ui->setupUi(this);
}

Warehouse::~Warehouse()
{
    delete ui;
}
