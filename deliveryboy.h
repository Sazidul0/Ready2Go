#ifndef DELIVERYBOY_H
#define DELIVERYBOY_H

#include <QWidget>

namespace Ui {
class DeliveryBoy;
}

class DeliveryBoy : public QWidget
{
    Q_OBJECT

public:
    explicit DeliveryBoy(QWidget *parent = nullptr);
    ~DeliveryBoy();

private:
    Ui::DeliveryBoy *ui;
};

#endif // DELIVERYBOY_H
