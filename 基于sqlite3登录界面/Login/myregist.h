#ifndef MYREGIST_H
#define MYREGIST_H

#include <QWidget>

namespace Ui {
class Myregist;
}

class Myregist : public QWidget
{
    Q_OBJECT

public:
    explicit Myregist(QWidget *parent = 0);
    ~Myregist();
signals:
       void onRegist(QString,QString);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Myregist *ui;
};

#endif // MYREGIST_H
