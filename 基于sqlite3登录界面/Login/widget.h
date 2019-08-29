#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include "form.h"
#include "myregist.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btn_login_clicked(bool checked);

    void on_btn_Regist_clicked();

    void onHanderRegist(QString,QString);

private:
    Ui::Widget *ui;
    Form *form;//新的界面
    QSqlDatabase *db;
    Myregist *regist;
};

#endif // WIDGET_H
