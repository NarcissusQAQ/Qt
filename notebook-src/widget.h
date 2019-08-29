#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QGridLayout>
#include <QVBoxLayout>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void onbtnShow(bool);
    void onFind(bool);
signals:
    void onReturn(QString);
   private:
        QLabel *label;
        QPushButton *btn[3];
        QLineEdit *edit;
        QCheckBox *cbox[3];
        QRadioButton *radio[3];
        QGridLayout *glayout;
        QVBoxLayout *vbox[2];
        QWidget *widget[2];
};

#endif // WIDGET_H
