#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel("内容：");
    btn[0] =   new QPushButton("find");
    btn[1] =   new QPushButton("close");
    btn[2] =   new QPushButton("show");
    btn[2]->setCheckable(true);
    edit = new QLineEdit;
    cbox[0] = new QCheckBox ("option");
    cbox[1] = new QCheckBox ("option");
    cbox[2] = new QCheckBox ("option");

    radio[0] = new QRadioButton("down");
    radio[1] = new QRadioButton("down");
    radio[2] = new QRadioButton("down");
    glayout = new QGridLayout;
    vbox[0] = new QVBoxLayout ;
    vbox[1] = new QVBoxLayout ;

    widget[0] = new QWidget;
    widget[1] = new QWidget;

    glayout->addWidget(label,0,0);
    glayout->addWidget(edit,0,1,1,2);
    glayout->addWidget(btn[0],0,3);
    glayout->addWidget(cbox[0],1,0);
    glayout->addWidget(cbox[1],2,0);//
    glayout->addWidget(cbox[2],3,0);
    glayout->addWidget(btn[1],1,3);
    glayout->addWidget(btn[2],2,3);
    widget[0]->setLayout(glayout);
    //======================
    vbox[0]->addWidget(radio[0]);
    vbox[0]->addWidget(radio[1]);
    vbox[0]->addWidget(radio[2]);
    widget[1]->setLayout(vbox[0]);

    //======================
    vbox[1]->addWidget(widget[0]);
    vbox[1]->addWidget(widget[1]);

    widget[1]->hide();

    //设置布局器的大小约束：顶层布局固定，自动适应布局大小
    vbox[1]->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(vbox[1]);

    //信号与槽
    connect(btn[2],SIGNAL(clicked(bool)),this,SLOT(onbtnShow(bool)));
    connect(btn[0],SIGNAL(clicked(bool)),this,SLOT(onFind(bool)));

}

Widget::~Widget()
{

}

void Widget::onbtnShow(bool ok)
{
    if(ok)
    {
        widget[1]->show();
        btn[2]->setText("hide");
    }
    else
    {
        widget[1]->hide();
        btn[2]->setText("show");
    }
}
void Widget::onFind(bool)
{
    QString text = edit->text();
    emit onReturn(text);
}
