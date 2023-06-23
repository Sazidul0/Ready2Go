#include "admin.h"
#include "ui_admin.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QFrame>
#include <QSqlRecord>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
     ui->Login->setCurrentIndex(0);
    Database= QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("F:/QT/Ready2Go/Database.db");
    qDebug() <<Database.open();

}


Admin::~Admin()
{
    delete ui;
}






void Admin::on_BackToMenu_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window = new MainMenu();
    main_window->show();
}


void Admin::on_Admin_login_Button_clicked()
{
    admin_username = ui->Admin_login_Input_UserName->text();
    admin_userpass = ui->Admin_login_Input_Password->text();

    if(admin_username == "admin" && admin_userpass == "admin"){
        ui->Login->setCurrentIndex(1);
    }
    else{
        QMessageBox::information(this,"Login","Invalid UserName or Password!");
    }
    ui->Admin_login_Input_Password->clear();
    ui->Admin_login_Input_UserName->clear();
}


void Admin::on_Menu_Button_clicked()
{
        ui->Login->setCurrentIndex(0);
}


void Admin::on_BackToMenu_2_clicked()
{
        this->hide();
        MainMenu *main_window;
        main_window = new MainMenu();
        main_window->show();
}


void Admin::on_Completed_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
        QSqlQueryModel *modal= new QSqlQueryModel();
        QSqlQueryModel *modal1= new QSqlQueryModel();
       //Creating Modal...

        //Creating query and assigning database to it...
        QSqlQuery *qryy= new QSqlQuery(Database);
        QSqlQuery *qryy1= new QSqlQuery(Database);
//        QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

        //Preparing the queries with the necessary fetched data...
        qryy->prepare("select name from completedOrder");
        qryy1->prepare("select description from completedOrder");
       //Preparing the queries with the necessary fetched data...

        //Executing the queries...
        qryy->exec();
        qryy1->exec();


        //Assigning the queries to the previuosly created modals...
        modal->setQuery(*qryy);


        //Assigning the queries to the previuosly created modals...

        //Creating a grid layout...
        QGridLayout *lay1=new QGridLayout(this);
        //Creating an array of button...
        QPushButton *name[100];
        //running a loop to add the desired components to the scroll area...
        for(int j=0;j<=modal->rowCount()-1;j++)
        {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//


        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Description: "+str1+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_4->setLayout(lay1);
        }
//        Database.close();
}


void Admin::on_Track_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Admin::on_Panding_Order_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();
    QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

    //Creating query and assigning database to it...
    QSqlQuery *qryy= new QSqlQuery(Database);
    QSqlQuery *qryy1= new QSqlQuery(Database);
    QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

    //Preparing the queries with the necessary fetched data...
    qryy->prepare("select name from pendingOrder");
    qryy1->prepare("select email from pendingOrder");
    qryy2->prepare("select address from pendingOrder");    //Preparing the queries with the necessary fetched data...

    //Executing the queries...
    qryy->exec();
    qryy1->exec();
    qryy2->exec();//Executing the queries...

    //Assigning the queries to the previuosly created modals...
    modal->setQuery(*qryy);
    modal1->setQuery(*qryy1);
    modal2->setQuery(*qryy2);
    //Assigning the queries to the previuosly created modals...

    //Creating a grid layout...
    QGridLayout *lay1=new QGridLayout(this);
    //Creating an array of button...
    QPushButton *name[100];
    //running a loop to add the desired components to the scroll area...
    for(int j=0;j<=modal->rowCount()-1;j++)
    {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//(blood group)
        QString str2=modal2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Blood Group: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_3->setLayout(lay1);
    }
//    Database.close();
}


void Admin::on_All_Users_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    //Creating Modal...
    QSqlQueryModel *dbb= new QSqlQueryModel();
    QSqlQueryModel *dbb1= new QSqlQueryModel();
    QSqlQueryModel *dbb2= new QSqlQueryModel();    //Creating Modal...

    //Creating query and assigning database to it...
    QSqlQuery *qry= new QSqlQuery(Database);
    QSqlQuery *qry1= new QSqlQuery(Database);
    QSqlQuery *qry2= new QSqlQuery(Database);//Creating query and assigning database to it...

    //Preparing the queries with the necessary fetched data...
    qry->prepare("select name from user");
    qry1->prepare("select email from user");
    qry2->prepare("select address from user");    //Preparing the queries with the necessary fetched data...

    //Executing the queries...
    qry->exec();
    qry1->exec();
    qry2->exec();//Executing the queries...

    //Assigning the queries to the previuosly created modals...
   dbb->setQuery(*qry);
    dbb1->setQuery(*qry1);
    dbb2->setQuery(*qry2);
    //Assigning the queries to the previuosly created modals...

    //Creating a grid layout...
    QGridLayout *lay=new QGridLayout(this);
    //Creating an array of button...
    QPushButton *name[100];
    //running a loop to add the desired components to the scroll area...
    for(int j=0;j<=dbb->rowCount()-1;j++)
    {
        //Assigning the desired information from the previously prepared modals...
        QString str=dbb->record(j).value(0).toString();//(name)
        QString str1=dbb1->record(j).value(0).toString();//(blood group)
        QString str2=dbb2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Name: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay->addWidget(name[j]);
        lay->addWidget(lab);
        lay->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea->setLayout(lay);
    }
//     Database.close();
    //putting the layout inside the scroll area...
}


void Admin::on_Delivery_Boy_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
     QSqlQueryModel *modal= new QSqlQueryModel();
     QSqlQueryModel *modal1= new QSqlQueryModel();
     QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

     //Creating query and assigning database to it...
     QSqlQuery *qryy= new QSqlQuery(Database);
     QSqlQuery *qryy1= new QSqlQuery(Database);
     QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

     //Preparing the queries with the necessary fetched data...
     qryy->prepare("select name from deliveryboy");
     qryy1->prepare("select email from deliveryboy");
     qryy2->prepare("select address from deliveryboy");    //Preparing the queries with the necessary fetched data...

     //Executing the queries...
     qryy->exec();
     qryy1->exec();
     qryy2->exec();//Executing the queries...

     //Assigning the queries to the previuosly created modals...
     modal->setQuery(*qryy);
     modal1->setQuery(*qryy1);
     modal2->setQuery(*qryy2);
     //Assigning the queries to the previuosly created modals...

     //Creating a grid layout...
     QGridLayout *lay1=new QGridLayout(this);
     //Creating an array of button...
     QPushButton *name[100];
     //running a loop to add the desired components to the scroll area...
     for(int j=0;j<=modal->rowCount()-1;j++)
     {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//(blood group)
        QString str2=modal2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Blood Group: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_2->setLayout(lay1);
     }
//     Database.close();
}


void Admin::on_All_Sellers_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
     QSqlQueryModel *modal= new QSqlQueryModel();
     QSqlQueryModel *modal1= new QSqlQueryModel();
     QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

     //Creating query and assigning database to it...
     QSqlQuery *qryy= new QSqlQuery(Database);
     QSqlQuery *qryy1= new QSqlQuery(Database);
     QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

     //Preparing the queries with the necessary fetched data...
     qryy->prepare("select name from seller");
     qryy1->prepare("select email from seller");
     qryy2->prepare("select address from seller");    //Preparing the queries with the necessary fetched data...

     //Executing the queries...
     qryy->exec();
     qryy1->exec();
     qryy2->exec();//Executing the queries...

     //Assigning the queries to the previuosly created modals...
     modal->setQuery(*qryy);
     modal1->setQuery(*qryy1);
     modal2->setQuery(*qryy2);
     //Assigning the queries to the previuosly created modals...

     //Creating a grid layout...
     QGridLayout *lay1=new QGridLayout(this);
     //Creating an array of button...
     QPushButton *name[100];
     //running a loop to add the desired components to the scroll area...
     for(int j=0;j<=modal->rowCount()-1;j++)
     {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//(blood group)
        QString str2=modal2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Blood Group: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_4->setLayout(lay1);
     }
     Database.close();
}


void Admin::on_Available_Items_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
     QSqlQueryModel *modal= new QSqlQueryModel();
     QSqlQueryModel *modal1= new QSqlQueryModel();
     QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

     //Creating query and assigning database to it...
     QSqlQuery *qryy= new QSqlQuery(Database);
     QSqlQuery *qryy1= new QSqlQuery(Database);
     QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

     //Preparing the queries with the necessary fetched data...
     qryy->prepare("select name from seller");
     qryy1->prepare("select email from seller");
     qryy2->prepare("select address from seller");    //Preparing the queries with the necessary fetched data...

     //Executing the queries...
     qryy->exec();
     qryy1->exec();
     qryy2->exec();//Executing the queries...

     //Assigning the queries to the previuosly created modals...
     modal->setQuery(*qryy);
     modal1->setQuery(*qryy1);
     modal2->setQuery(*qryy2);
     //Assigning the queries to the previuosly created modals...

     //Creating a grid layout...
     QGridLayout *lay1=new QGridLayout(this);
     //Creating an array of button...
     QPushButton *name[100];
     //running a loop to add the desired components to the scroll area...
     for(int j=0;j<=modal->rowCount()-1;j++)
     {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//(blood group)
        QString str2=modal2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Blood Group: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_4->setLayout(lay1);
     }
     Database.close();
}


void Admin::on_All_Warehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();
    QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

    //Creating query and assigning database to it...
    QSqlQuery *qryy= new QSqlQuery(Database);
    QSqlQuery *qryy1= new QSqlQuery(Database);
    QSqlQuery *qryy2= new QSqlQuery(Database);//Creating query and assigning database to it...

    //Preparing the queries with the necessary fetched data...
    qryy->prepare("select name from seller");
    qryy1->prepare("select email from seller");
    qryy2->prepare("select address from seller");    //Preparing the queries with the necessary fetched data...

    //Executing the queries...
    qryy->exec();
    qryy1->exec();
    qryy2->exec();//Executing the queries...

    //Assigning the queries to the previuosly created modals...
    modal->setQuery(*qryy);
    modal1->setQuery(*qryy1);
    modal2->setQuery(*qryy2);
    //Assigning the queries to the previuosly created modals...

    //Creating a grid layout...
    QGridLayout *lay1=new QGridLayout(this);
    //Creating an array of button...
    QPushButton *name[100];
    //running a loop to add the desired components to the scroll area...
    for(int j=0;j<=modal->rowCount()-1;j++)
    {
        //Assigning the desired information from the previously prepared modals...
        QString str=modal->record(j).value(0).toString();//(name)
        QString str1=modal1->record(j).value(0).toString();//(blood group)
        QString str2=modal2->record(j).value(0).toString();//(address)

        //Assigning the desired information from the previously prepared modals...

        //Assigning the strings to widgets...
        name[j]=new QPushButton(str);
        QLabel *lab=new QLabel("Blood Group: "+str1+", Address: "+str2+"."); //Assigning the strings to widgets...
        lab->setStyleSheet("color:white");
        QFrame *line;

        //Creating horizontal line with desired properties...
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

        //Setting up the pushbutton with the on-hover changes...
        name[j]->setObjectName("btnName_1");
        name[j]->setStyleSheet(
            "   QPushButton#btnName_1 {"
            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
            " }"
            " QPushButton#btnName_1:hover {"
            "     color: yellow;font-size:25px;"
            " }");                                  //Setting up the pushbutton with the on-hover changes...


        lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

        //adding all the widgets to the previously cretaed grid layout...
        lay1->addWidget(name[j]);
        lay1->addWidget(lab);
        lay1->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


        //connecting the button containg name with the onnameclicked function...
        connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
        ui->scrollArea_4->setLayout(lay1);
    }
    Database.close();
}


void Admin::on_Menu_Button_2_clicked()
{
      ui->stackedWidget->setCurrentIndex(8);
}





void Admin::on_Admin_Info_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void Admin::on_LogOut_clicked()
{
    this->hide();
    MainMenu *main_window;
    main_window = new MainMenu();
    main_window->show();
}

