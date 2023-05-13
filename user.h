#ifndef USER_H
#define USER_H

#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();

private slots:
    void on_User_login_Button_clicked();

    void on_BackToMenu_clicked();

private:
    Ui::User *ui;
    QString user_login_name,user_login_pass;

};

#endif // USER_H
