#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
signals:
        void onReturn();
private slots:
    void on_btn_return_clicked(bool checked);

private:
    Ui::Form *ui;
};

#endif // FORM_H
