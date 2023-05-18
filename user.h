#ifndef USER_H
#define USER_H

#include <QWidget>
#include "mainmenu.h"
#include <QSqlDatabase>
#include <QSqlQuery>


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

    void on_User_goto_singup_Button_2_clicked();

    void on_pushButton_clicked();

    void on_user_signup_input_name_linkActivated(const QString &link);

    void on_user_signup_button_clicked();

    void on_Menu_Button_clicked();

    void on_BackToMenu_3_clicked();

private:
    Ui::User *ui;
    QString user_login_name,user_login_pass,user_signup_name,user_signup_email,user_signup_password,user_signup_contact,user_signup_address;
    QSqlDatabase db5;

};

#endif // USER_H
