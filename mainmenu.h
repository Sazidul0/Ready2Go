#ifndef MAINMENU_H
#define MAINMENU_H

#include "admin.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_admin_clicked();

private:
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
