#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   // ui->this->setWindowTitle();
    form = new Form;
    regist = new Myregist;
    connect(regist,SIGNAL(onRegist(QString,QString)),this,SLOT(onHanderRegist(QString,QString)));
    connect(form,SIGNAL(onReturn()),this,SLOT(show()));
    //建立链接，创建数据库
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("test.db");

    //打开数据库
    bool ok = db->open();
    if(!ok)
    {
        qDebug() << db->lastError().text();
        QMessageBox::information(this,"db open",db->lastError().text());
    }
    QSqlQuery query;
    query.exec("create table user(name text primary key,password text not null);");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_login_clicked(bool checked)
{
    //获取文本框中的内容
    QString name = ui->edit_name->text();
     QString pwd = ui->edit_pwd->text();

     QSqlQuery query;
     query.exec("select *from user;");

     int flag = 0;
     while(query.next())
     {
         QString u_name = query.value(0).toString();
         QString u_pwd = query.value(1).toString();
         //判断简单的用户名和密码是否正确
         if(name == u_name && pwd == u_pwd)
         {
                flag = 1;
             QMessageBox::information(this,"information","Login success!");
             break;
         }
     }
     if(flag)
     {
         //如果正确，显示新界面，隐藏登录界面
         ui->edit_name->clear();
         ui->edit_pwd->clear();
         this->close();
         form->show();
     }
     else
     {
         QMessageBox::information(this,"information","username or password error!");
     }

}

void Widget::on_btn_Regist_clicked()
{
    this->hide();
    regist->show();
}

void Widget::onHanderRegist(QString name, QString pwd)
{
   QString sql =  QString("insert into user(name,password) values('%1','%2');").arg(name).arg(pwd);
   QSqlQuery query;
   if(!query.exec(sql))
     {
       qDebug() << "insert error";
   }
   else
       {

   }
}
