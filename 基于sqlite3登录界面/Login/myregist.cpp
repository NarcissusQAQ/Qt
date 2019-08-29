#include "myregist.h"
#include "ui_myregist.h"
#include <QMessageBox>
Myregist::Myregist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Myregist)
{
    ui->setupUi(this);
}

Myregist::~Myregist()
{
    delete ui;
}

void Myregist::on_pushButton_clicked()
{
    //获取文本中的内容
    QString name = ui->edit_name->text();
    QString pwd1 = ui->edit_pwd1->text();
    QString pwd2 = ui->edit_pwd2->text();

   //保证数据不为空
    if(name.isEmpty() || pwd1.isEmpty() || pwd2.isEmpty())
    {
        QMessageBox::information(this,"warning","name or password is empty");
        return ;
    }
    //判断两次密码是否一致
    if(pwd1 != pwd2)
    {
        QMessageBox::information(this,"warning","两次密码不一致");
        return ;
    }

    emit onRegist(name,pwd1);

}

void Myregist::on_pushButton_2_clicked()
{
    this->close();
}
