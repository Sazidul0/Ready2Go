#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QWidget>

namespace Ui {
class Warehouse;
}

class Warehouse : public QWidget
{
    Q_OBJECT

public:
    explicit Warehouse(QWidget *parent = nullptr);
    ~Warehouse();

private:
    Ui::Warehouse *ui;
};

#endif // WAREHOUSE_H
